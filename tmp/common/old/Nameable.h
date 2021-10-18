/**
 * @author Forrest Jablonski
 */

#pragma once

#include "Standard.h"

namespace ym
{

/*
 * Available variants
 */
class Nameable_NV;
class CNameable_NV;

/**
 * 
 */
class Nameable_NV
{
public:
   explicit inline Nameable_NV(SStr_T const Name_Ptr)
      : _Name_ptr {Name_Ptr}
   {
   }

   inline auto getName(void) const { return _Name_ptr; }

   inline void setName(SStr_T const Name_Ptr) { _Name_ptr = Name_Ptr; }

private:
   SStr_T /* non-const */ _Name_ptr;
};

/**
 * C = Const
 */
class CNameable_NV
{
public:
   explicit inline CNameable_NV(SStr_T const Name_Ptr)
      : _Name_Ptr {Name_Ptr}
   {
   }

   inline auto getName(void) const { return _Name_Ptr; }

private:
   SStr_T const _Name_Ptr;
};

} // ym
