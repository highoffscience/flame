/**
 * @author Forrest Jablonski
 */

#include "colorscheme.h"

/**
 * Clr is in [0..1] and maps to a pixel
 */
auto hoso::flame::ColorScheme::apply(Pixel::dim_t const Clr) const -> Pixel
{
   #include "colorscheme.script"
}
