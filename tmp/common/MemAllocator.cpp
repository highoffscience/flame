/**
 * @author Forrest Jablonski
 */

#include "MemAllocator.h"

/**
 * 
 */
ym::MemAllocator::MemAllocator(void)
   : _items    { },
     _next_idx {0}
{
}

/**
 * 
 */
auto ym::MemAllocator::getInstancePtr(void) -> MemAllocator *
{
   static MemAllocator * instance_ptr = nullptr;

   if (!instance_ptr)
   {
      instance_ptr = new MemAllocator;
   }

   return instance_ptr;
}
