/**
 * @author Forrest Jablonski
 *
 * AUTO-GENERATED
 */

#include <cmath>

#include "VariationBlend.h"

#include "Point.h"

/**
 *
 */
inline fct::Point var_0(const fct::Point& pnt)
{
   return {pnt.x, pnt.y};
}

/**
 * Transforms 'pnt'
 * 'index' was the most recently applied transformation
 */
void fct::vb::transform(const uint index, fct::Point& pnt)
{
   constexpr double weights[3][1] = {
      {1.0},
      {1.0},
      {1.0}
   };
   
   pnt = (var_0(pnt) * weights[index][0]);
}
