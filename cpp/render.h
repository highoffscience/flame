/**
 * @author Forrest Jablonski
 */

#pragma once

#include "hoso.h"

namespace hoso::flame
{
   /**
    * 
    */
   class Render
   {
   public:
      Render(void) = default;

      void populate(class Pixel * const * const histo_Ptr_Ptr) const;
   };
} // hoso::flame
