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

   uint32 preXform(Point        & pnt_ref,
                   Pixel::dim_t & clr_ref);

   void postXform (Point        & pnt_ref,
                   Pixel::dim_t & clr_ref);
};

} // hoso::flame
