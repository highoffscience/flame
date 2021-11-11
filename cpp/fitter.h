/**
 * @author Forrest Jablonski
 */

#pragma once

#include "hoso.h"
#include "point.h"

namespace hoso::flame
{

/**
 *
 */
struct Fitter
{
   explicit Fitter(uint32 const   Width,
                   uint32 const   Height,
                   Point  const & Min,
                   Point  const & Max);

   inline Point apply(Point const & P) const;

private:
   Point const _Scale;
   Point const _Trans;
};

/**
 *
 */
inline auto hoso::flame::Fitter::apply(Point const & P) const -> Point
{
   return P * _Scale + _Trans;
}

} // hoso::flame
