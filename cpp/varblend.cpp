/**
 * @author Forrest Jablonski
 */

#include "varblend.h"

/**
 *
 */
inline fct::Point var_0(const fct::Point& pnt)
{
   return {pnt.x, pnt.y};
}

/**
 *
 */
auto hoso::flame::Point::apply(uint32 const Transform_idx) const -> Point
{

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
