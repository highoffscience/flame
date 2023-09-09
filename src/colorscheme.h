/**
 * @file    colorscheme.h
 * @version 1.0.0
 * @author  Forrest Jablonski
 */

#pragma once

#include "ymdefs.h"

#include "fastmath.h"
#include "pixel.h"

namespace flame
{

/** ColorScheme
 * 
 * @brief Color scheme of the generated pixels.
 */
class ColorScheme
{
public:
   YM_NO_DEFAULT(ColorScheme)

   /** apply
    * 
    * @brief Maps [Clr] -> [Red, Green, Blue].
    */
   static inline Pixel apply(Pixel::dim_t const Clr)
   {
      #include "scripts/colorscheme/index.script"
   }
};

} // flame
