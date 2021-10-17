/**
 * @author Forrest Jablonski
 *
 * AUTO-GENERATED
 */

#include <cmath>

#include "ColorScheme.h"

/**
 * 'color' is in [0..1] and maps to a pixel
 */
auto fct::cs::transform(const float color) -> Pixel
{
   const Pixel begin = {0.0, 1.0, 0.0, 0.0};
   const Pixel end = {1.0, 0.0, 0.0, 0.0};
   const Pixel alpha = end - begin;
   const Pixel beta = begin;
   
   return alpha * color + beta;
}
