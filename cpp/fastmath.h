/**
 * @author Forrest Jablonski
 */

#pragma once

#include "dim.h"
#include "hoso.h"

namespace hoso::flame
{

/**
 *
 */
class FastMath
{
public:
   explicit FastMath(void) = delete;

   static constexpr auto Pi  = static_cast<dim_t>(3.14159265358979324);
   static constexpr auto Tau = static_cast<dim_t>(2.0 * Pi); // upcast intentional

   static constexpr auto fmod(dim_t const X,
                              dim_t const Y);

   static constexpr auto fabs(dim_t const X);

   static constexpr auto min(dim_t const X,
                             dim_t const Y);

   static constexpr auto max(dim_t const X,
                             dim_t const Y);

   static constexpr auto sin(dim_t x_rad);

   // static constexpr auto cos(dim_t x_rad);
};

/**
 *
 */
constexpr auto FastMath::fmod(dim_t const X,
                              dim_t const Y)
{
   return X - (int64(X / Y) * Y);
}

/**
 *
 */
constexpr auto FastMath::fabs(dim_t const X)
{
   return (X < Zero) ? -X : X;
}

/**
 *
 */
constexpr auto FastMath::min(dim_t const X,
                             dim_t const Y)
{
   return (X < Y) ? X : Y;
}

/**
 *
 */
constexpr auto FastMath::max(dim_t const X,
                             dim_t const Y)
{
   return (X > Y) ? X : Y;
}

/**
 * Bhaskara I's approximation
 * Discovered in the 7th century!
 */
constexpr auto FastMath::sin(dim_t x_rad)
{
   // wrap into interval [-Tau..Tau]
   x_rad = FastMath::fmod(x_rad, Tau);

   // map into interval [-Pi..Pi]
        if (x_rad < -Pi) { x_rad += Tau; }
   else if (x_rad > +Pi) { x_rad -= Tau; }

   // method only works in interval [0..Pi]
   auto b = FastMath::fabs(x_rad);
   b = 4.0 * b * (Pi - b);
   b = (4.0 * b) / ((5.0 * Pi * Pi) - b);

   return (x_rad < Zero) ? -b : b;
}

} // hoso::flame
