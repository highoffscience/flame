/**
 * @author Forrest Jablonski
 *
 * AUTO-GENERATED
 */

#include "colorscheme.h"

/**
 * color is in [0..1] and maps to a pixel
 */
auto fct::cs::transform(const float color) -> Pixel
{
   //                     r    g    b    a
   constexpr Pixel Begin{0.0, 1.0, 0.0, 0.0};
   constexpr Pixel End  {1.0, 0.0, 0.0, 0.0};
   constexpr Pixel p;
   
   constexpr Pixel Alpha = End - Begin;
   constexpr Pixel Beta = Begin;
   
   return alpha * color + beta;
}
