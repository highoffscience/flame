/**
 * @author Forrest Jablonski
 */

#pragma once

#include "hoso.h"

#include <type_traits>

namespace hoso::flame
{
   using dim_t = float64;
   static_assert(std::is_floating_point_v<dim_t>, "Dimension type must be floating point!");

   static constexpr dim_t Zero = 0.0;
   static constexpr dim_t One  = 1.0;

   /**
    *
    */
   constexpr dim_t operator"" _f(long double const X)
   {
      return static_cast<dim_t>(X);
   }

} // hoso::flame
