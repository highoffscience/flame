/**
 * @file    varblend.h
 * @version 1.0.0
 * @author  Forrest Jablonski
 */

#pragma once

#include "ymdefs.h"

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

   static inline Point apply(ym::uint32 const Transform_idx,
                             Point      const P            );

private:
   static inline Point var0(Point const P) {
      #include "scripts/varblend/var0.script"
   }

   static inline Point var1(Point const P) {
      #include "scripts/varblend/var1.script"
   }

   static inline Point var2(Point const P) {
      #include "scripts/varblend/var2.script"
   }

   static inline Point var3(Point const P) {
      #include "scripts/varblend/var3.script"
   }
};

/** apply
 *
 * @brief Applies the given set of transforms.
 */
inline auto flame::VarBlend::apply(ym::uint32 const Transform_idx,
                                   Point      const P            ) -> Point
{
   // #include "scripts/varblend/index.script"

   constexpr ym::uint32 NTransforms = 4u;
   constexpr ym::uint32 NVars       = 4u;

   // rows should add up to 1 but not strictly necessary
   constexpr Point::dim_t Weights[NTransforms][NVars] = {
      {1.0, 0.0, 0.0, 0.0,},
      {1.0, 0.0, 0.0, 0.0},
      {1.0, 0.0, 0.0, 0.0},
      {1.0, 0.0, 0.0, 0.0},
   };

   return
      (var0(P) * Weights[Transform_idx][0]) +
      (var1(P) * Weights[Transform_idx][1]) +
      (var2(P) * Weights[Transform_idx][2]) +
      (var3(P) * Weights[Transform_idx][3]);
}

} // flame
