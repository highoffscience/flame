/**
 * @author Forrest Jablonski
 */

#pragma once

#include "hoso.h"

#include "textlogger.h"

#include <atomic>
#include <exception>
#include <string>
#include <type_traits>
#include <utility>

#if defined(HOSO_DBG)
#include <boost/stacktrace.hpp>
#endif // HOSO_DBG

namespace hoso
{

/*
 * Convenience functions.
 * -------------------------------------------------------------------------- */

template <typename... Args_T>
inline void hosoAssert(   bool   const    Condition,
                          str    const    Format,
                          Args_T const... Args);

template <typename... Args_T>
inline void hosoAssertDbg(bool   const    Condition,
                          str    const    Format,
                          Args_T const... Args);

template <typename... Args_T>
inline void hosoThrow(    bool   const    Condition,
                          str    const    Format,
                          Args_T const... Args);

template <typename... Args_T>
inline void hosoThrowDbg( bool   const    Condition,
                          str    const    Format,
                          Args_T const... Args);

/* -------------------------------------------------------------------------- */

/**
 *
 */
class Hosception : public std::exception
{
public:
   virtual ~Hosception(void) = default;

   template <typename... Args_T>
   friend void hosoAssert(bool   const    Condition,
                          str    const    Format,
                          Args_T const... Args);

   template <typename... Args_T>
   friend void hosoThrow(bool   const    Condition,
                         str    const    Format,
                         Args_T const... Args);

   inline auto getTag(void) const { return _Tag; }

   virtual str what(void) const noexcept override { return "Hosception"; }

private:
   explicit Hosception(void);

   template <typename... Args_T>
   static void assertPrintToLogAndConditionallyThrow(bool   const    Condition,
                                                     bool   const    TerminateOnFailure,
                                                     str    const    Format,
                                                     Args_T const... Args);

   static std::atomic<uint32> _s_tagCount;

   uint32 const _Tag;
};

/**
 *
 */
template <typename... Args_T>
inline void hosoAssert(bool   const    Condition,
                       str    const    Format,
                       Args_T const... Args)
{
   Hosception::assertPrintToLogAndConditionallyThrow(Condition, true, Format, Args...);
}

/**
 *
 */
template <typename... Args_T>
inline void hosoAssertDbg(bool   const    Condition,
                          str    const    Format,
                          Args_T const... Args)
{
#if defined(HOSO_DBG)
   ymAssert(Condition, Format, Args...);
#endif // HOSO_DBG
}

/**
 *
 */
template <typename... Args_T>
inline void hosoThrow(bool   const    Condition,
                      str    const    Format,
                      Args_T const... Args)
{
   Hosception::assertPrintToLogAndConditionallyThrow(Condition, false, Format, Args...);
}

/**
 *
 */
template <typename... Args_T>
inline void hosoThrowDbg(bool   const    Condition,
                         str    const    Format,
                         Args_T const... Args)
{
#if defined(HOSO_DBG)
   ymThrow(Condition, Format, Args...);
#endif // HOSO_DBG
}

/**
 *
 */
template <typename... Args_T>
void Hosception::assertPrintToLogAndConditionallyThrow(bool   const    Condition,
                                                       bool   const    TerminateOnFailure,
                                                       str    const    Format,
                                                       Args_T const... Args)
{
   if (!Condition)
   { // assert failed
      hosoLog(0, "Assert failed!");

      Hosception e;
      if (TerminateOnFailure)
      { // let user know we are about to terminate
         hosoLog(0, "About to terminate with tag %lu!", e.getTag());
      }
      else
      { // let user know we are about to throw
         hosoLog(0, "Throwing Hosception with tag %lu!", e.getTag());
      }

      hosoLog(0, Format, Args...);

   #if defined(HOSO_DBG)
      hosoLog(0, "Stack dump follows...");

      { // split and print stack dump
         std::string const StackDumpStr = boost::stacktrace::to_string(boost::stacktrace::stacktrace());

         for (auto startPos = StackDumpStr.find_first_not_of('\n', 0);
              startPos != std::string::npos;
              /*empty*/)
         { // print each line of the stack dump separately
            auto const EndPos = StackDumpStr.find_first_of('\n', startPos);
            hosoLog(0, StackDumpStr.substr(startPos, EndPos - startPos).c_str());
            startPos = StackDumpStr.find_first_not_of('\n', EndPos);
         }
      }
   #endif // HOSO_DBG

      if (TerminateOnFailure)
      { // terminate
         std::terminate();
      }
      else
      { // throw
         throw e;
      }
   }
}

} // hoso
