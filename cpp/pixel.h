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

   explicit constexpr inline Pixel(void);
   explicit constexpr inline Pixel(dim_t const R_,
                                   dim_t const G_,
                                   dim_t const B_,
                                   dim_t const A_);

   constexpr inline auto isZero(void) const;

   constexpr inline auto pls(Pixel const & Rhs) const;
   constexpr inline auto mns(Pixel const & Rhs) const;
   constexpr inline auto tms(Pixel const & Rhs) const;
   constexpr inline auto dvd(Pixel const & Rhs) const;

   constexpr inline auto pls(dim_t const Rhs) const;
   constexpr inline auto mns(dim_t const Rhs) const;
   constexpr inline auto tms(dim_t const Rhs) const;
   constexpr inline auto dvd(dim_t const Rhs) const;

   dim_t r; // red
   dim_t g; // green
   dim_t b; // blue
   dim_t a; // alpha
};

/**
 * 
 */
constexpr inline Pixel::Pixel(void)
   : Pixel(0.0, 0.0, 0.0, 0.0)
{
}

/**
 * 
 */
constexpr inline Pixel::Pixel(dim_t const R_,
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
constexpr inline auto Pixel::isZero(void) const
{
   return r == static_cast<dim_t>(0.0) &&
          g == static_cast<dim_t>(0.0) &&
          b == static_cast<dim_t>(0.0) &&
          a == static_cast<dim_t>(0.0);
}

/**
 * 
 */
constexpr inline auto Pixel::pls(Pixel const & Rhs) const
{
   return Pixel(r + Rhs.r,
                g + Rhs.g,
                b + Rhs.b,
                a + Rhs.a);
}

/**
 * 
 */
constexpr inline auto Pixel::mns(Pixel const & Rhs) const
{
   return Pixel(r - Rhs.r,
                g - Rhs.g,
                b - Rhs.b,
                a - Rhs.a);
}

/**
 * 
 */
constexpr inline auto Pixel::tms(Pixel const & Rhs) const
{
   return Pixel(r * Rhs.r,
                g * Rhs.g,
                b * Rhs.b,
                a * Rhs.a);
}

/**
 * 
 */
constexpr inline auto Pixel::dvd(Pixel const & Rhs) const
{
   return Pixel(r / Rhs.r,
                g / Rhs.g,
                b / Rhs.b,
                a / Rhs.a);
}

/**
 * 
 */
constexpr inline auto Pixel::pls(dim_t const Rhs) const
{
   return Pixel(r + Rhs,
                g + Rhs,
                b + Rhs,
                a + Rhs);
}

/**
 * 
 */
constexpr inline auto Pixel::mns(dim_t const Rhs) const
{
   return Pixel(r - Rhs,
                g - Rhs,
                b - Rhs,
                a - Rhs);
}

/**
 * 
 */
constexpr inline auto Pixel::tms(dim_t const Rhs) const
{
   return Pixel(r * Rhs,
                g * Rhs,
                b * Rhs,
                a * Rhs);
}

/**
 * 
 */
constexpr inline auto Pixel::dvd(dim_t const Rhs) const
{
   return Pixel(r / Rhs,
                g / Rhs,
                b / Rhs,
                a / Rhs);
}

} // hoso::flame
