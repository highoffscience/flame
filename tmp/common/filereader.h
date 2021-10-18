/**
 * @author Forrest Jablonski
 */

#include "standard.h"

#include <exception>

namespace hoso
{

/**
 *
 */
class FileReader
{
public:
   explicit FileReader(void);
           ~FileReader(void);

   uchar * getDataBuffer(str const Filename);
   void destroyDataBuffer(void);

   /**
    *
    */
   class FileReaderError : public std::exception
   {
   public:
      explicit inline FileReaderError(str const Msg);
   };

private:
   uchar * _dataBuffer_ptr;
};

/**
 *
 */
FileReader::FileReaderError::FileReaderError(str const Msg)
   : std::exception(Msg)
{
}

} // hoso
