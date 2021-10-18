/**
 * @author Forrest Jablonski
 */

#include "standard.h"

#include <memory>
#include <vector>

namespace yymm
{

/**
 * 
 */
class MemAllocator
{
   static MemAllocator * getInstancePtr(void);

   template <typename T>
   T * allocate(uint64 const NElements);

   template <typename T>
   void deallocate(T * const mem_Ptr);

private:
   explicit MemAllocator(void);

   /**
    * 
    */
   struct Item
   {
      void * mem_ptr;
      uint64 nElements;
   };

   std::vector<Item> _items;
   uint64            _next_idx;
};

/**
 * TODO This doesn't need to be a template. All I need is the size. Look up how to align.
 *      Then I can make an inline convenience casting function 
 */
template <typename T>
T * MemAllocator::allocate(uint64 const NElements)
{
   std::allocator<T> a;
   auto * const mem_Ptr = a.allocate(NElements);

   for (auto &)
   _items.emplace_back(a.allocate(NElements), NElements);
   return _items.back().mem_ptr;
}

/**
 * 
 */
template <typename T>
void MemAllocate::deallocate(T * const mem_Ptr)
{

}

} // yymm
