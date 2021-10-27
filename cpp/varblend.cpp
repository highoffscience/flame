/**
 * @author Forrest Jablonski
 */

#include "varblend.h"

/**
 *
 */
hoso::flame::VarBlend::VarBlend(void)
   : _vars {0}
{
}

/**
 *
 */
//inline fct::Point var_0(const fct::Point& pnt)
//{
//   return {pnt.x, pnt.y};
//}

/**
 *
 */
auto hoso::flame::VarBlend::apply(uint32 const XForm_idx) const -> Point
{
   return Point();
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
