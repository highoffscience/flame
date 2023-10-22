/**
 * @file    varblend.h
 * @version 1.0.0
 * @author  Forrest Jablonski
 */

#pragma once

#include "ymdefs.h"

#include "fastmath.h"
#include "point.h"

namespace flame
{

/** VarBlend
 *
 * @brief Transforms the point via warping the coordinate system.
 */
class VarBlend // Variation Blend
{
public:
   YM_NO_DEFAULT(VarBlend)

   /** apply
    *
    * @brief Applies the given set of transforms.
    */
   static inline Point apply(ym::uint32 const Transform_idx,
                             Point      const P            )
   {
      #include "./scripts/varblend.script"
   }
};

} // flame
