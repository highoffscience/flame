/**
 * @author Forrest Jablonski
 */

#pragma once

#include "hoso.h"
#include "logger.h"
#include "semaphore.h"
#include "timerdefs.h"

#include <atomic>
#include <cstdio>
#include <mutex>
#include <thread>

namespace hoso
{

/*
 * Convenience functions.
 * -------------------------------------------------------------------------- */

template <typename... Args_T>
inline void hosoLog(uint32 const    Verbosity,
                    str    const    Format,
                    Args_T const... Args);

/* -------------------------------------------------------------------------- */

/**
 * Uses the multi-producer/single-consumer model.
 */
class TextLogger : public Logger
{
public:
   explicit TextLogger(str const Filename);
   virtual ~TextLogger(void);

   HOSO_NO_COPY  (TextLogger);
   HOSO_NO_ASSIGN(TextLogger);

   static TextLogger * getGlobalInstancePtr(void);

   bool open (void);
   void close(void);

   void enableClients (uint64 const Clients_mask);
   void disableClients(uint64 const Clients_mask);

   inline auto isOpen(void) const { return _isOpen.load(std::memory_order_relaxed); }

   inline auto isGlobalInstance(void) const { return _isGlobalInstance; }

   uint64 getVerbosityCap(void) const;
   void   setVerbosityCap(uint64 const VerbosityCap);

   static constexpr auto getMaxMessageSize_bytes(void) { return _s_MaxMessageSize_bytes; }
   static constexpr auto getMaxNMessagesInBuffer(void) { return _s_MaxNMessagesInBuffer; }

   template <typename... Args_T>
   void printf(uint32 const    Verbosity,
               str    const    Format,
               Args_T const... Args);

private:
   explicit TextLogger(str  const Filename,
                       bool const IsGlobalInstance);

   typedef uint32 MsgReadyBF_T; // BF = BitField

   static constexpr uint32 _s_MaxMessageSize_bytes = 256;
   static constexpr uint32 _s_MaxNMessagesInBuffer = sizeof(MsgReadyBF_T) * 8; // 8 bits per byte
   static constexpr uint32 _s_BufferSize_bytes     = _s_MaxMessageSize_bytes * _s_MaxNMessagesInBuffer;

   static_assert((_s_MaxNMessagesInBuffer & (_s_MaxNMessagesInBuffer - 1)) == 0, "Needs to be power of 2!");

   // TODO reorganize declaration of variables
   uint32                    _readPos;  // these positions are slot numbers [0.._s_MaxNMessagesInBuffer)
   std::atomic<uint32>       _writePos; //  :
   std::atomic<MsgReadyBF_T> _msgReady_bf;
   Semaphore                 _availableSem;
   Semaphore                 _messagesSem;
   std::thread               _writer;
   std::mutex                _openingGuard;
   std::atomic<bool>         _isOpen;
   std::atomic<uint64>       _activeVerbosities;
   bool const                _isGlobalInstance;
   char                      _buffer[_s_BufferSize_bytes];

   template <typename... Args_T>
   void printf_Helper(str    const    Format,
                      Args_T const... Args);

   template <typename... Args_T>
   void printfError(str    const    Format,
                    Args_T const... Args);

   void writeMessagesToFile(void);

   uint32 populateFormattedTime(char * const write_Ptr) const;

   bool willPrint(uint64 const Verbosities);
};

/**
 *
 */
template <typename... Args_T>
inline void hosoLog(uint32 const    Verbosity,
                    str    const    Format,
                    Args_T const... Args)
{
   TextLogger::getGlobalInstancePtr()->printf(Verbosity, Format, Args...);
}

/**
 *
 */
template <typename... Args_T>
void TextLogger::printf(uint32 const    Verbosity,
                        str    const    Format,
                        Args_T const... Args)
{
   if (_isOpen.load(std::memory_order_acquire))
   { // ok to print
      if (Verbosity <= getVerbosityCap())
      { // verbose enough to print this message
         printf_Helper(Format, Args...);
      }
   }
   else
   { // trying to print while not open
      printfError("%s is not open! Attempted to print '%s'!\n", getName(), Format);
   }
}

/**
 *
 */
template <typename... Args_T>
void TextLogger::printfError(str    const    Format,
                             Args_T const... Args)
{
   if (isGlobalInstance())
   { // last line of defense failed - just print to stderr and hope someone is watching
      std::fprintf(stderr, "Error! Msg = ");
      std::fprintf(stderr, Format, Args...);
      std::fprintf(stderr, "\n"           );
   }
   else
   { // last try to let the global instance know something is wrong
      getGlobalInstancePtr()->printfError(Format, Args...);
   }
}

/**
 *
 */
template <typename... Args_T>
void TextLogger::printf_Helper(str    const    Format,
                               Args_T const... Args)
{
   _availableSem.wait();
      
   auto   const WritePos  = _writePos.fetch_add(1, std::memory_order_relaxed) & (getMaxNMessagesInBuffer() - 1);
   auto * const write_Ptr = _buffer + (WritePos * getMaxMessageSize_bytes());

   auto const Offset = populateFormattedTime(write_Ptr);
   auto const AdjustedMsgSize_bytes = getMaxMessageSize_bytes() - Offset;

   auto const NCharsWrittenInTheory = std::snprintf(write_Ptr + Offset,
                                                    AdjustedMsgSize_bytes,
                                                    Format,
                                                    Args...);

   if (NCharsWrittenInTheory < 0)
   { // snprintf hit an internal error
      printfError("std::snprintf failed with error code %d!\n", NCharsWrittenInTheory);
      printfError(" Message was '%s'\n", write_Ptr);

      // don't fail here - just keep going
   }
      
   if (NCharsWrittenInTheory >= static_cast<int32>(AdjustedMsgSize_bytes))
   { // not everything was printed to the buffer
      printfError("Failed to write everything to the buffer! NCharsWrittenInTheory = %ld. "
                  "Max message size = %lu (adjusted = %lu). Message = '%s'\n",
                  NCharsWrittenInTheory,
                  getMaxMessageSize_bytes(),
                  AdjustedMsgSize_bytes,
                  write_Ptr + Offset);

      // don't fail here - just keep going
   }

   _msgReady_bf.fetch_or(1 << WritePos, std::memory_order_release);

   _messagesSem.post();
}

} // hoso
