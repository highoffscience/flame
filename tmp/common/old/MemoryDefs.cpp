/**
 * @author Forrest Jablonski
 */

#include "MemoryDefs.h"

std::unordered_map<void *, ym::uint32> ym::MemoryDefs::_allocatedSizes; // default

/**
 *
 */
void ym::MemoryDefs::deallocate(void * const data_Ptr)
{
   auto const It = _allocatedSizes.find(data_Ptr);

   ymAssert(It != _allocatedSizes.end(),
      "Trying to deallocate storage at %p where none was allocated!",
      data_Ptr);

   std::allocator<uint8> a;
   a.deallocate(static_cast<uint8 *>(data_Ptr), It->second);

   _allocatedSizes.erase(It);
}
