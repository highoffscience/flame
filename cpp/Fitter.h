/**
 * @author Forrest Jablonski
 */

#pragma once

#include "Standard.h"

#include "Point.h"

namespace fct
{
   namespace fit
   {
      void init(const Point& minFitPnt, const Point& maxFitPnt);
   
      Point transform(const Point& pnt);
   } // fit
} // fct
