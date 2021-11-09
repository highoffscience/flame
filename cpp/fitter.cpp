/**
 * @author Forrest Jablonski
 */

#include "fastmath.h"
#include "fitter.h"

/**
 * TODO can do fancier math to determine the scale more accurately
 */
hoso::flame::Fitter::Fitter(uint32 const   Width,
                            uint32 const   Height,
                            Point  const & Min,
                            Point  const & Max)
   : _Scale {FastMath::min(Width / (Max.x - Min.x), Height / (Max.y - Min.y))},
     _Trans {-0.5 * (Max.x + Min.x), -0.5 * (Max.y + Min.y)}
{
}

/**
 *
 */
auto hoso::flame::Fitter::apply(Point const & P) const -> Point
{
   return (P + _Trans) * _Scale;
}
