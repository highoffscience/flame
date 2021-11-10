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
   : // _Scale {FastMath::min(Width  / (Max.x - Min.x),
     //                       Height / (Max.y - Min.y))},
     // _Trans {((-0.5 * (Max.x + Min.x)) * _Scale.x) + (Width  / 2),
     //         ((-0.5 * (Max.y + Min.y)) * _Scale.y) + (Height / 2)}
     _Scale {100.0, 100.0},
     _Trans {0.0,   0.0}
{
}

/**
 *
 */
auto hoso::flame::Fitter::apply(Point const & P) const -> Point
{
   return P * _Scale + _Trans;
}
