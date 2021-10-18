/**
 * @author Forrest Jablonski
 */

#pragma once

#include "Standard.h"

#include "Ymception.h"

#include <memory>
#include <unordered_map>

namespace ym
{

/*
 * Convenience functions.
 * -------------------------------------------------------------------------- */

template <typename T>
inline T * ymAllocate(uint32 const NElements);

inline void ymDeallocate(void * const data_Ptr);

/* -------------------------------------------------------------------------- */

/**
 *
 */
class MemoryDefs
{
public:
   YM_NO_DEFAULT(MemoryDefs);

   template <typename T>
   friend T * ymAllocate(uint32 const NElements);

   friend void ymDeallocate(void * const data_Ptr);

private:
   template <typename T>
   static T * allocate(uint32 const NElements);

   static void deallocate(void * const data_Ptr);

   static std::unordered_map<void *, uint32> _allocatedSizes;
};

/**
 *
 */
template <typename T>
inline T * ymAllocate(uint32 const NElements)
{
   return MemoryDefs::allocate<T>(NElements);
}

/**
 *
 */
inline void ymDeallocate(void * const data_Ptr)
{
   MemoryDefs::deallocate(data_Ptr);
}

/**
 *
 */
template <typename T>
T * MemoryDefs::allocate(uint32 const NElements)
{
   std::allocator<T> a;
   T * data_ptr = nullptr;

   try
   {
      data_ptr = a.allocate(NElements);
      _allocatedSizes.insert({data_ptr, NElements * sizeof(T)});
   }
   catch(std::exception const & E)
   {
      data_ptr = nullptr;
      ymAssert(true, E.what());
   }

   return data_ptr;
}

} // ym
