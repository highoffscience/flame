/**
 * @author Forrest Jablonski
 */

#include "file.h"

/**
 * 
 */
hoso::File::File(str const Filename,
                 str const Mode)
   : _file_Ptr {std::fopen(Filename, Mode)}
{
}

/**
 * 
 */
hoso::File::~File(void)
{
   std::fclose(_file_Ptr);
}
