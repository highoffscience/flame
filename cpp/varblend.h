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

   Point apply(uint32 const   Transform_idx,
               Point  const & P) const;

private:
   inline Point var0(Point const & P) const;
   inline Point var1(Point const & P) const;
   inline Point var2(Point const & P) const;
   inline Point var3(Point const & P) const;
};

} // hoso::flame
