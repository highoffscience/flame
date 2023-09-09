/**
 * @file    strangor.h
 * @version 1.0.0
 * @author  Forrest Jablonski
 */

#pragma once

#include "ymdefs.h" /// @todo it would be better to have ym/ymdefs.h

#include "pixel.h"
#include "point.h"

namespace flame
{

/** Strangor
 *
 * @brief Transforms a point according to strange attractor rules.
 * 
 * @note There are IFS (Iterated Function Systems) and IAS (Iterated Affine Systems).
 * 
 * @todo Implement IFS.
 */
class Strangor // Strange Attractor
{
public:
   YM_NO_DEFAULT(Strangor)

   static inline ym::uint32 apply(ym::float64    const RandVal,
                                  Point        &       pnt_ref,
                                  Pixel::dim_t &       clr_ref);

private:
   /** IASMatrix
    * 
    * @brief Matrix describing iterated affine system.
    */
   struct IASMatrix
   {
      Point::dim_t const A;
      Point::dim_t const B;
      Point::dim_t const C;
      Point::dim_t const D;
      Point::dim_t const E;
      Point::dim_t const F;

      Pixel::dim_t const Clr;
      ym::float64  const Prob;
   };
};

/**
 *
 */
inline ym::uint32 Strangor::apply(ym::float64    const RandVal,
                                  Point        &       pnt_ref,
                                  Pixel::dim_t &       clr_ref)
{
   constexpr IASMatrix Transforms[] = {
      #include "scripts/strangor/index.script"
   };

   ym::float64 sum = 0.0;
   ym::uint32  idx = 0u;

   for (ym::uint32 i = 0u; i < YM_ARRAY_SIZE(Transforms); ++i)
   {
      sum += Transforms[i].Prob;

      if (RandVal < sum)
      {
         idx = i;
         break;
      }
   }

   pnt_ref = Point(Transforms[idx].A * pnt_ref.x + Transforms[idx].B * pnt_ref.y + Transforms[idx].E,
                   Transforms[idx].C * pnt_ref.x + Transforms[idx].D * pnt_ref.y + Transforms[idx].F);

   clr_ref = 0.5 * (clr_ref + Transforms[idx].Clr);

   return idx;
}

} // flame
