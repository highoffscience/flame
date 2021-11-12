/**
 * @author Forrest Jablonski
 */

#pragma once

#include "hoso.h"
#include "point.h"
#include "pixel.h"

namespace hoso::flame
{

/**
 *
 */
class StrangeAttractor
{
public:
   explicit StrangeAttractor(void) = default;

   uint32 preTransform(      Point        & pnt_ref,
                             Pixel::dim_t & clr_ref,
                       class Random       & rand_ref) const;

   void postTransform (      Point        & pnt_ref,
                             Pixel::dim_t & clr_ref,
                       class Random       & rand_ref) const;

private:
   /**
    * Do not reorder
    */
   struct IFSMatrix
   {
      Pixel::dim_t const Clr;
      float64      const Prob;
   };

   /**
    * Do not reorder
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
      float64      const Prob;
   };
};

} // hoso::flame
