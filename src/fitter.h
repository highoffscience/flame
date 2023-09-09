/**
 * @file    fitter.h
 * @version 1.0.0
 * @author  Forrest Jablonski
 */

#pragma once

#include "ymdefs.h"

#include "point.h"

namespace flame
{

/** Fitter
 * 
 * @brief Fits points into a 2D buffer of predetermined size.
 */
class Fitter
{
public:
   explicit Fitter(ym::uint32 const Width_pxls,
                   ym::uint32 const Height_pxls,
                   Point      const Max,
                   Point      const Min);

   inline Point apply(Point const Pnt) const {
      return (Pnt * _Scale) + _Trans;
   }

   inline auto getScale(void) const { return _Scale; }
   inline auto getTrans(void) const { return _Trans; }

private:
   Point const _Scale;
   Point const _Trans;
};

} // flame
