/**
 * @author Forrest Jablonski
 */

#pragma once

#include "Standard.h"

#include <cstdio>
#include <tuple>

namespace ym
{

/**
 *
 */
class Logger
{
public:
   explicit Logger(void) = default;
   virtual ~Logger(void) = default;

   YM_NO_COPY  (Logger);
   YM_NO_ASSIGN(Logger);

protected:
   std::tuple<FILE *, int32> open(SStr_T const Filename) const;
   int32 close(FILE * const outfile_Ptr) const;
};

} // ym
