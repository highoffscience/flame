/**
 * @file    fastmath.h
 * @version 1.0.0
 * @author  Forrest Jablonski
 */

#pragma once

#include "ymdefs.h"

#include <cmath>
#include <type_traits>

namespace flame
{

/** FastMath
 * 
 * @brief Library of fast (and often times approximate) functions.
 */
class FastMath
{
public:
   YM_NO_DEFAULT(FastMath)

   template <typename float_t>
   requires(std::is_floating_point_v<float_t>)
   static constexpr auto Pi  = static_cast<float_t>(3.14159265358979324);

   template <typename float_t>
   requires(std::is_floating_point_v<float_t>)
   static constexpr auto Tau = static_cast<float_t>(2.0 * Pi<float_t>); // upcast intentional

   template <typename float_t>
   requires(std::is_floating_point_v<float_t>)
   static constexpr auto fmod(float_t const X,
                              float_t const Y) {
      return X - (int64(X / Y) * Y);
   }

   template <typename float_t>
   requires(std::is_floating_point_v<float_t>)
   static constexpr auto fabs(float_t const X) {
      return (X < static_cast<float_t>(0.0)) ? -X : X;
   }

   template <typename T>
   static constexpr auto min(T const X,
                             T const Y) {
      return (X < Y) ? X : Y;
   }

   template <typename T>
   static constexpr auto max(T const X,
                             T const Y) {
      return (X > Y) ? X : Y;
   }

   template <typename float_t>
   requires(std::is_floating_point_v<float_t>)
   static inline auto sin(float_t x_rad);

   // template <typename float_t>
   // requires(std::is_floating_point_v<float_t>)
   // static inline auto cos(float_t x_rad);
};

/** sin
 * 
 * @brief Fast, approximate, sine function.
 * 
 * @note Bhaskara I's approximation - Discovered in the 7th century!
 */
template <typename float_t>
requires(std::is_floating_point_v<float_t>)
constexpr auto FastMath::sin(float_t x_rad)
{
   // wrap into interval [-Tau..Tau]
   x_rad = fmod(x_rad, Tau<float_t>);

   // map into interval [-Pi..Pi]
        if (x_rad < -Pi<float_t>) { x_rad += Tau<float_t>; }
   else if (x_rad > +Pi<float_t>) { x_rad -= Tau<float_t>; }

   // method only works in interval [0..Pi]
   auto b = fabs(x_rad);
   b = float_t(4.0) * b * (Pi<float_t> - b);
   b = (float_t(4.0) * b) / ((float_t(5.0) * Pi<float_t> * Pi<float_t>) - b);

   return (x_rad < static_cast<float_t>(0.0)) ? -b : b;
}

} // flame
