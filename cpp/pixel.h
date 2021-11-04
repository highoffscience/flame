/**
 * @author Forrest Jablonski
 */

#pragma once

#include <cmath>

#include "hoso.h"

namespace hoso::flame
{

/**
 * Represents a pixel using the rgba color space
 */
struct Pixel
{
   typedef float64 dim_t;

   explicit constexpr Pixel(void);
   explicit constexpr Pixel(dim_t const R_,
                            dim_t const G_,
                            dim_t const B_,
                            dim_t const A_);

   constexpr auto isZero(void) const;

   constexpr auto operator + (Pixel const & Rhs) const;
   constexpr auto operator - (Pixel const & Rhs) const;
   constexpr auto operator * (Pixel const & Rhs) const;
   constexpr auto operator / (Pixel const & Rhs) const;

   constexpr auto operator + (dim_t const Rhs) const;
   constexpr auto operator - (dim_t const Rhs) const;
   constexpr auto operator * (dim_t const Rhs) const;
   constexpr auto operator / (dim_t const Rhs) const;

   constexpr void operator += (Pixel const & Rhs);
   constexpr void operator -= (Pixel const & Rhs);
   constexpr void operator *= (Pixel const & Rhs);
   constexpr void operator /= (Pixel const & Rhs);

   constexpr void operator += (dim_t const Rhs);
   constexpr void operator -= (dim_t const Rhs);
   constexpr void operator *= (dim_t const Rhs);
   constexpr void operator /= (dim_t const Rhs);
   constexpr void operator ^= (dim_t const Rhs);

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
constexpr auto Pixel::operator + (Pixel const & Rhs) const
{
   return Pixel(r + Rhs.r,
                g + Rhs.g,
                b + Rhs.b,
                a + Rhs.a);
}

/**
 *
 */
constexpr auto Pixel::operator - (Pixel const & Rhs) const
{
   return Pixel(r - Rhs.r,
                g - Rhs.g,
                b - Rhs.b,
                a - Rhs.a);
}

/**
 *
 */
constexpr auto Pixel::operator * (Pixel const & Rhs) const
{
   return Pixel(r * Rhs.r,
                g * Rhs.g,
                b * Rhs.b,
                a * Rhs.a);
}

/**
 *
 */
constexpr auto Pixel::operator / (Pixel const & Rhs) const
{
   return Pixel(r / Rhs.r,
                g / Rhs.g,
                b / Rhs.b,
                a / Rhs.a);
}

/**
 *
 */
constexpr auto Pixel::operator + (dim_t const Rhs) const
{
   return Pixel(r + Rhs,
                g + Rhs,
                b + Rhs,
                a + Rhs);
}

/**
 *
 */
constexpr auto Pixel::operator - (dim_t const Rhs) const
{
   return Pixel(r - Rhs,
                g - Rhs,
                b - Rhs,
                a - Rhs);
}

/**
 *
 */
constexpr auto Pixel::operator * (dim_t const Rhs) const
{
   return Pixel(r * Rhs,
                g * Rhs,
                b * Rhs,
                a * Rhs);
}

/**
 *
 */
constexpr auto Pixel::operator / (dim_t const Rhs) const
{
   return Pixel(r / Rhs,
                g / Rhs,
                b / Rhs,
                a / Rhs);
}

/**
 *
 */
constexpr void Pixel::operator += (Pixel const & Rhs)
{
   *this = *this + Rhs;
}

/**
 *
 */
constexpr void Pixel::operator -= (Pixel const & Rhs)
{
   *this = *this - Rhs;
}

/**
 *
 */
constexpr void Pixel::operator *= (Pixel const & Rhs)
{
   *this = *this * Rhs;
}

/**
 *
 */
constexpr void Pixel::operator /= (Pixel const & Rhs)
{
   *this = *this / Rhs;
}

/**
 *
 */
constexpr void Pixel::operator += (dim_t const Rhs)
{
   *this = *this + Rhs;
}

/**
 *
 */
constexpr void Pixel::operator -= (dim_t const Rhs)
{
   *this = *this - Rhs;
}

/**
 *
 */
constexpr void Pixel::operator *= (dim_t const Rhs)
{
   *this = *this * Rhs;
}

/**
 *
 */
constexpr void Pixel::operator /= (dim_t const Rhs)
{
   *this = *this / Rhs;
}

/**
 *
 */
// #include <cmath>
constexpr void Pixel::operator ^= (dim_t const Rhs)
{
   r = std::pow(r, Rhs);
   g = std::pow(g, Rhs);
   b = std::pow(b, Rhs);
   //a = std::pow(r, Rhs);
}

} // hoso::flame
