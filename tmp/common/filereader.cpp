/**
 * @author Forrest Jablonski
 */

#include "filereader.h"

#include <cstdio>
#include <exception>
#include <filesystem>
#include <new>

/**
 * 
 */
hoso::FileReader::FileReader(void)
   : _dataBuffer_ptr {nullptr}
{
}

/**
 * 
 */
hoso::FileReader::~FileReader(void)
{
   destroyDataBuffer();
}

/**
 * 
 */
auto hoso::FileReader::getDataBuffer(str const Filename) -> uchar *
{
   FILE * const file_Ptr = std::fopen(Filename, "r");
   if (!file_Ptr)
   {
      std::printf("Could not open file\n");
      return nullptr;
   }

   uint64 filesize_bytes = 0;
   try
   {
      filesize_bytes = std::filesystem::file_size(Filename);
   }
   catch (std::exception const & E)
   {
      std::printf(E.what());
      return nullptr;
   }

   if (filesize_bytes == 0)
   {
      std::printf("Filesize cannot be empty\n");
      std::fclose(file_Ptr);
      return nullptr;
   }

   

   auto * const buffer_Ptr = static_cast<uchar *>(::operator new(filesize_bytes));
   if (!buffer_Ptr)
   {
      std::fclose(file_Ptr);
      std::printf("Could not create buffer\n");
      return nullptr;
   }

   (void)std::fread(buffer_Ptr, sizeof(uchar), filesize_bytes, file_Ptr);
   std::fclose(file_Ptr);

   return buffer_Ptr;
}

/**
 * 
 */
void FileReader::destroyDataBuffer(uchar * const buffer_Ptr)
{
   if (buffer_Ptr)
   {
      ::operator delete(buffer_Ptr);
   }
}

int main(void)
{
   FileReader f;
   auto * const dataBuffer_Ptr = f.getDataBuffer("bible.txt");
   f.destroyDataBuffer(dataBuffer_Ptr);
   return 0;
}
