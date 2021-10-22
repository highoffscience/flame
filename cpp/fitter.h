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
   explicit Fitter(void);
   explicit Fitter(Point const & Min,
                   Point const & Max);

   Point apply(Point const & Pnt) const;

private:
   Point const Min;
   Point const Max;
};

} // hoso::flame
