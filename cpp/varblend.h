/**
 * @author Forrest Jablonski
 */

#pragma once

#include "hoso.h"
#include "point.h"

namespace hoso::flame
{

/**
 * 
 */
struct VarBlend // Variation Blend
{
   explicit VarBlend(void);

   Point apply
};
   namespace vb
   {
      void transform(const uint index, Point& pnt);
   } // var

} // hoso::flame
