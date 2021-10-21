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
   class Fitter
   {

   };
      void init(const Point& minFitPnt, const Point& maxFitPnt);
   
      Point transform(const Point& pnt);
   } // fit
} // hoso::flame
