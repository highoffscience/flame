/**
 * @author Forrest Jablonski
 */

#pragma once

#include "dim.h"
#include "hoso.h"
#include "pixel.h"

namespace hoso::flame
{

/**
 *
 */
class ColorScheme
{
public:
   explicit ColorScheme(void) = default;

   Pixel apply(dim_t const Clr) const;
};

} // hoso::flame
