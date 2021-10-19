/**
 * @author Forrest Jablonski
 */

#pragma once

#include "hoso.h"
#include "nameable.h"

#include <cstdio>

namespace hoso
{

/**
 * Limited interface since derived classes might want to be thread safe.
 */
class Logger : public CNameable_NV
{
public:
   explicit Logger(str const Name);
   virtual ~Logger(void);

   HOSO_NO_COPY  (Logger);
   HOSO_NO_ASSIGN(Logger);

protected:
   inline auto getOutfilePtr(void) { return _outfile_ptr; }

   bool open (str const Filename);
   void close(void);

private:
   std::FILE * _outfile_ptr;
};

} // hoso
