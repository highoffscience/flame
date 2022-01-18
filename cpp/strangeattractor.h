/**
 * @author Forrest Jablonski
 */

#pragma once

#include "dim.h"
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

   uint32 preTransform(      Point  & pnt_ref,
                             dim_t  & clr_ref,
                       class Random & rand_ref) const;

   void postTransform (      Point  & pnt_ref,
                             dim_t  & clr_ref,
                       class Random & rand_ref) const;

private:
   /**
    * Do not reorder
    */
   struct IFSMatrix
   {
      dim_t   const Clr;
      float64 const Prob;
   };

   /**
    * Do not reorder
    */
   struct IASMatrix
   {
      dim_t const A;
      dim_t const B;
      dim_t const C;
      dim_t const D;
      dim_t const E;
      dim_t const F;

      dim_t   const Clr;
      float64 const Prob;
   };
};

} // hoso::flame
