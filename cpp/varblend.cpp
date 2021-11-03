/**
 * @author Forrest Jablonski
 */

#include "varblend.h"

/**
 *
 */
constexpr auto hoso::flame::VarBlend::var0(Point const & P) const -> Point
{
   #include "var0.script"
}

/**
 *
 */
constexpr auto hoso::flame::VarBlend::var1(Point const & P) const -> Point
{
   #include "var1.script"
}

/**
 *
 */
constexpr auto hoso::flame::VarBlend::var2(Point const & P) const -> Point
{
   #include "var2.script"
}

/**
 *
 */
constexpr auto hoso::flame::VarBlend::var3(Point const & P) const -> Point
{
   #include "var3.script"
}

/**
 *
 */
auto hoso::flame::VarBlend::apply(uint32 const   Transform_idx,
                                  Point  const & P) const -> Point
{
   constexpr uint32 NXforms = 3;
   constexpr uint32 NVars   = 4;
   constexpr Point::dim_t Weights[NXforms][NVars] = {
      {1.0f, 0.0f, 0.0f, 0.0f},
      {1.0f, 0.0f, 0.0f, 0.0f},
   };

   return (var0(P) * Weights[Transform_idx][0]) +
          (var1(P) * Weights[Transform_idx][1]) +
          (var2(P) * Weights[Transform_idx][2]) +
          (var3(P) * Weights[Transform_idx][3]);
}
