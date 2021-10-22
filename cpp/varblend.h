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
class VarBlend // Variation Blend
{
public:
   explicit VarBlend(void) = default;

   Point apply(uint32 const Transform_idx) const;
};

} // hoso::flame
