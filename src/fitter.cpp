/**
 * @file    fitter.cpp
 * @version 1.0.0
 * @author  Forrest Jablonski
 */

#include "fitter.h"

#include "fastmath.h"

/**
 * TODO can do fancier math to determine the scale more accurately
 */
flame::Fitter::Fitter(ym::uint32 const Width,
                      ym::uint32 const Height,
                      Point      const Max,
                      Point      const Min)
   : _Scale {FastMath::min(Width  / (Max.x - Min.x),
                           Height / (Max.y - Min.y))},
     _Trans {(Width  / 2.0) - (((Max.x + Min.x) / 2.0) * _Scale.x),
             (Height / 2.0) - (((Max.y + Min.y) / 2.0) * _Scale.y)}
{
}
