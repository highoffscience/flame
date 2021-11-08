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
   explicit StrangeAttractor(void);

   uint32 preTransform(Point        & pnt_ref,
                       Pixel::dim_t & clr_ref);

   void postTransform (Point        & pnt_ref,
                       Pixel::dim_t & clr_ref);

private:
   Random _rand;

   /**
    *
    */
   struct IFSMatrix
   {
      float64       const Prob;
      Pixel::dim_t  const Clr;
   };

   /**
    *
    */
   struct IASMatrix
   {
      float64       const Prob;
      Pixel::dim_t  const Clr;

      Point::dim_t  const A;
      Point::dim_t  const B;
      Point::dim_t  const C;
      Point::dim_t  const D;
      Point::dim_t  const E;
      Point::dim_t  const F;
   };
};

} // hoso::flame
