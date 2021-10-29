/**
 * @author Forrest Jablonski
 */

#pragma once

#include "hoso.h"
#include "point.h"
#include "pixel.h"
#include "random.h"

namespace hoso::flame
{

/**
 *
 */
class StrangeAttractor
{
public:
   explicit StrangeAttractor(void) = default;

   uint32 preTransform(Point        & pnt_ref,
                       Pixel::dim_t & clr_ref) const;

   void postTransform (Point        & pnt_ref,
                       Pixel::dim_t & clr_ref) const;

private:
   /**
    *
    */
   struct IFSMatrix
   {
      Pixel::dim_t  const Clr;
      Random::dim_t const Prob;
   };

   /**
    *
    */
   struct IASMatrix
   {
      Pixel::dim_t  const Clr;
      Random::dim_t const Prob;
      Point::dim_t  const A;
      Point::dim_t  const B;
      Point::dim_t  const C;
      Point::dim_t  const D;
      Point::dim_t  const E;
      Point::dim_t  const F;
   };
};

} // hoso::flame
