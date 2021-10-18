/**
 * @author Forrest Jablonski
 */

#include "Logger.h"

/**
 *
 */
auto ym::Logger::open(SStr_T const Filename) const -> std::tuple<FILE *, int32>
{
   FILE * outfile_ptr = nullptr;
   auto const ErrorCode = fopen_s(&outfile_ptr, Filename, "w");

   return std::make_tuple(outfile_ptr, ErrorCode);
}

/**
 *
 */
auto ym::Logger::close(FILE * const outfile_Ptr) const -> int32
{
   auto const ErrorCode = std::fclose(outfile_Ptr);

   return ErrorCode;
}
