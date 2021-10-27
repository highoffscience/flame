/**
 * @author Forrest Jablonski
 */

#pragma once

#include "hoso.h"

namespace hoso::flame
{

/**
 * Represents a pixel using the rgba color space
 */
struct Pixel
{
   typedef float32 dim_t;

   explicit constexpr Pixel(void);
   explicit constexpr Pixel(dim_t const R_,
                            dim_t const G_,
                            dim_t const B_,
                            dim_t const A_);

   constexpr auto isZero(void) const;

   constexpr auto pls(Pixel const & Rhs) const;
   constexpr auto mns(Pixel const & Rhs) const;
   constexpr auto tms(Pixel const & Rhs) const;
   constexpr auto dvd(Pixel const & Rhs) const;

   constexpr auto pls(dim_t const Rhs) const;
   constexpr auto mns(dim_t const Rhs) const;
   constexpr auto tms(dim_t const Rhs) const;
   constexpr auto dvd(dim_t const Rhs) const;

   dim_t r; // red
   dim_t g; // green
   dim_t b; // blue
   dim_t a; // alpha
};

/**
 * 
 */
constexpr Pixel::Pixel(void)
   : Pixel(0.0, 0.0, 0.0, 0.0)
{
}

/**
 * 
 */
constexpr Pixel::Pixel(dim_t const R_,
                       dim_t const G_,
                       dim_t const B_,
                       dim_t const A_)
   : r {R_},
     g {G_},
     b {B_},
     a {A_}
{
}

/**
 * 
 */
constexpr auto Pixel::isZero(void) const
{
   return r == static_cast<dim_t>(0.0) &&
          g == static_cast<dim_t>(0.0) &&
          b == static_cast<dim_t>(0.0) &&
          a == static_cast<dim_t>(0.0);
}

/**
 * 
 */
constexpr auto Pixel::pls(Pixel const & Rhs) const
{
   return Pixel(r + Rhs.r,
                g + Rhs.g,
                b + Rhs.b,
                a + Rhs.a);
}

/**
 * 
 */
constexpr auto Pixel::mns(Pixel const & Rhs) const
{
   return Pixel(r - Rhs.r,
                g - Rhs.g,
                b - Rhs.b,
                a - Rhs.a);
}

/**
 * 
 */
constexpr auto Pixel::tms(Pixel const & Rhs) const
{
   return Pixel(r * Rhs.r,
                g * Rhs.g,
                b * Rhs.b,
                a * Rhs.a);
}

/**
 * 
 */
constexpr auto Pixel::dvd(Pixel const & Rhs) const
{
   return Pixel(r / Rhs.r,
                g / Rhs.g,
                b / Rhs.b,
                a / Rhs.a);
}

/**
 * 
 */
constexpr auto Pixel::pls(dim_t const Rhs) const
{
   return Pixel(r + Rhs,
                g + Rhs,
                b + Rhs,
                a + Rhs);
}

/**
 * 
 */
constexpr auto Pixel::mns(dim_t const Rhs) const
{
   return Pixel(r - Rhs,
                g - Rhs,
                b - Rhs,
                a - Rhs);
}

/**
 * 
 */
constexpr auto Pixel::tms(dim_t const Rhs) const
{
   return Pixel(r * Rhs,
                g * Rhs,
                b * Rhs,
                a * Rhs);
}

/**
 * 
 */
constexpr auto Pixel::dvd(dim_t const Rhs) const
{
   return Pixel(r / Rhs,
                g / Rhs,
                b / Rhs,
                a / Rhs);
}

} // hoso::flame
