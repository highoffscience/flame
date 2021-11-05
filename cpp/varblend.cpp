/**
 * @author Forrest Jablonski
 */

#include "varblend.h"
#include "fastmath.h"

/**
 *
 */
inline auto hoso::flame::VarBlend::var0(Point const & P) const -> Point
{
   #include "var0.script"
}

/**
 *
 */
inline auto hoso::flame::VarBlend::var1(Point const & P) const -> Point
{
   #include "var1.script"
}

/**
 *
 */
inline auto hoso::flame::VarBlend::var2(Point const & P) const -> Point
{
   #include "var2.script"
}

/**
 *
 */
inline auto hoso::flame::VarBlend::var3(Point const & P) const -> Point
{
   #include "var3.script"
}

/**
 *
 */
auto hoso::flame::VarBlend::apply(uint32 const   Transform_idx,
                                  Point  const & P) const -> Point
{
   constexpr uint32 NVars = 4;
   // rows should add up to 1
   constexpr Point::dim_t Weights[/*NXforms*/][NVars] = {
      {1.0f, 0.0f, 0.0f, 0.0f},
      {1.0f, 0.0f, 0.0f, 0.0f},
   };

   return (var0(P) * Weights[Transform_idx][0]) +
          (var1(P) * Weights[Transform_idx][1]) +
          (var2(P) * Weights[Transform_idx][2]) +
          (var3(P) * Weights[Transform_idx][3]);
}
