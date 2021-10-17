/**
 * @author Forrest Jablonski
 */

#pragma once

#include "Standard.h"

namespace fct
{
   class Point;

   namespace sa
   {
      uint  preTransform(Point& pnt, double& clr);
      void postTransform(Point& pnt, double& clr);
   } // sa
} // fct
