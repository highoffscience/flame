/**
 * @author Forrest Jablonski
 */

#pragma once

#include "hoso.h"

#include <cmath>
#include <type_traits>

namespace hoso::flame
{

/**
 * Represents a pixel using the rgba color space
 */
struct Pixel
{
   typedef float64 dim_t;
   static_assert(std::is_floating_point_v<dim_t>, "Pixel channel must be floating point!");

   // TODO research how to use user defined literals. Cleaner than static casting everything
   template <typename T>
   static constexpr auto Zero = static_cast<dim_t>(0.0);

   explicit constexpr Pixel(void);
   explicit constexpr Pixel(dim_t const R_,
                            dim_t const G_,
                            dim_t const B_,
                            dim_t const A_);
   implicit constexpr Pixel(dim_t const RGBA_);

   constexpr auto isZero(void) const;

   constexpr auto operator +  (Pixel const & Rhs) const;
   constexpr auto operator -  (Pixel const & Rhs) const;
   constexpr auto operator *  (Pixel const & Rhs) const;
   constexpr auto operator /  (Pixel const & Rhs) const;
   constexpr auto operator ^  (Pixel const & Rhs) const;

   constexpr void operator += (Pixel const & Rhs);
   constexpr void operator -= (Pixel const & Rhs);
   constexpr void operator *= (Pixel const & Rhs);
   constexpr void operator /= (Pixel const & Rhs);
   constexpr void operator ^= (Pixel const & Rhs);

   dim_t r; // red
   dim_t g; // green
   dim_t b; // blue
   dim_t a; // alpha
};

/**
 *
 */
constexpr Pixel::Pixel(void)
   : Pixel(static_cast<dim_t>(0.0))
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
constexpr Pixel::Pixel(dim_t const RGBA_)
   : Pixel(RGBA_, RGBA_, RGBA_, RGBA_)
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
constexpr auto Pixel::operator ^ (Pixel const & Rhs) const
{
   return Pixel(std::pow(r, Rhs.r),
                std::pow(g, Rhs.g),
                std::pow(b, Rhs.b),
                std::pow(a, Rhs.a));
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
constexpr void Pixel::operator ^= (Pixel const & Rhs)
{
   *this = *this ^ Rhs;
}

} // hoso::flame
