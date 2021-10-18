/**
 * @author Forrest Jablonski
 */

#include "logger.h"

/**
 *
 */
hoso::Logger::Logger(str const Name)
   : CNameable_NV (Name   ),
     _outfile_ptr {nullptr}
{
}

/**
 *
 */
hoso::Logger::~Logger(void)
{
   close();
}

/**
 *
 */
bool hoso::Logger::open(str const Filename)
{
   if (!_outfile_ptr)
   {
   #if defined(_WIN32)
      // visual studio prefers fopen_s
      auto const ErrorCode = fopen_s(&_outfile_ptr, Filename, "w");
      static_cast<void>(ErrorCode); // null is written to _outfile_ptr in case of error
   #else
      _outfile_ptr = std::fopen(Filename, "w");
   #endif // _WIN32
   }

   return _outfile_ptr != nullptr;
}

/**
 *
 */
bool hoso::Logger::close(void)
{
   if ()
   auto const ErrorCode = std::fclose(_outfile_ptr);
   _outfile_ptr = nullptr;

   return ErrorCode == 0;
}
