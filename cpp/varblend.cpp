/**
 * @author Forrest Jablonski
 */

#include "fastmath.h"
#include "varblend.h"

/**
 *
 */
inline auto hoso::flame::VarBlend::var0(Point const & P) const -> Point
{
   #include "varblend_scripts/var0.script"
}

/**
 *
 */
inline auto hoso::flame::VarBlend::var1(Point const & P) const -> Point
{
   #include "varblend_scripts/var1.script"
}

/**
 *
 */
inline auto hoso::flame::VarBlend::var2(Point const & P) const -> Point
{
   #include "varblend_scripts/var2.script"
}

/**
 *
 */
inline auto hoso::flame::VarBlend::var3(Point const & P) const -> Point
{
   #include "varblend_scripts/var3.script"
}

/**
 *
 */
auto hoso::flame::VarBlend::apply(uint32 const   Transform_idx,
                                  Point  const & P) const -> Point
{
   constexpr uint32 NTransforms = 2;
   constexpr uint32 NVars       = 4;

   // rows should add up to 1 but not strictly necessary
   constexpr dim_t Weights[NTransforms][NVars] = {
      {0.5, 0.5, 0.0, 0.0},
      {1.0, 0.0, 0.0, 0.0},
   };

   return (var0(P) * Weights[Transform_idx][0]) +
          (var1(P) * Weights[Transform_idx][1]) +
          (var2(P) * Weights[Transform_idx][2]) +
          (var3(P) * Weights[Transform_idx][3]);
}
