/**
 * @author Forrest Jablonski
 */

#pragma once

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
   explicit ColorScheme(void);

   Pixel apply(Pixel::dim_t const Clr) const;
};

} // hoso::flame
