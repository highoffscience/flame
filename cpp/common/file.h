/**
 * @author Forrest Jablonski
 */

#pragma once

#include "hoso.h"

#include <cstdio>

namespace hoso
{

/**
 * 
 */
class File
{
public:
   explicit File(str const Filename,
                 str const Mode);

   ~File(void);

   auto inline operator->(void) { return _file_Ptr; }

  /*implicit*/ inline operator std::FILE * (void) { return _file_Ptr; }

  // TODO read whole file if read mode into unique_ptr buffer

private:
   std::FILE * const _file_Ptr;
};

} // hoso
