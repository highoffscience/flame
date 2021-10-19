/**
 * @author Forrest Jablonski
 */

#pragma once

#include "hoso.h"

namespace hoso
{

/*
 * Available variants
 * NV = Non-Virtual
 * 
 * Names must be string literals
 */
class Nameable_NV;
class CNameable_NV; // C = const

/**
 * 
 */
class Nameable_NV
{
public:
   explicit inline Nameable_NV(void);
   explicit inline Nameable_NV(str const Name);

   inline auto getName(void) const { return _name; }

   inline void setName(str const Name) { _name = Name; }

private:
   str /* non-const */ _name;
};

/**
 * C = Const
 */
class CNameable_NV
{
public:
   explicit inline CNameable_NV(str const Name);

   inline auto getName(void) const { return _Name; }

private:
   str const _Name;
};

/**
 *
 */
inline Nameable_NV::Nameable_NV(void)
   : Nameable_NV(nullptr)
{
}

/**
 *
 */
inline Nameable_NV::Nameable_NV(str const Name)
   : _name {Name}
{
}

/**
 *
 */
inline CNameable_NV::CNameable_NV(str const Name)
   : _Name {Name}
{
}

} // hoso
