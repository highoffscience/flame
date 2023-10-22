/**
 * @file    fitter.cpp
 * @version 1.0.0
 * @author  Forrest Jablonski
 */

#include "fitter.h"

#include "fastmath.h"

/**
 * 
 */
flame::Fitter::Fitter(ym::uint32 const Width,
                      ym::uint32 const Height,
                      Point      const Max,
                      Point      const Min)
   : _scale {FastMath::min(Width  / (Max.x - Min.x),
                           Height / (Max.y - Min.y))},
     _trans {(Width  / 2.0) - (((Max.x + Min.x) / 2.0) * _scale.x),
             (Height / 2.0) - (((Max.y + Min.y) / 2.0) * _scale.y)}
{
}
