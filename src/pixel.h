/**
 * @file    pixel.h
 * @version 1.0.0
 * @author  Forrest Jablonski
 */

#pragma once

#include "ymdefs.h"

#include <cmath>
#include <type_traits>

namespace flame
{

/** Pixel
 * 
 * @brief Represents a pixel using the rgba color space.
 * 
 * @note This class is specific for this program, it is the users responsibility to avoid
 *       dividing by 0, or doing anything as dangerous.
 */
struct Pixel
{
   using dim_t = ym::float64;

   explicit    constexpr Pixel(void);
   explicit    constexpr Pixel(dim_t const R_,
                               dim_t const G_,
                               dim_t const B_,
                               dim_t const A_ = 0.0);
   YM_IMPLICIT constexpr Pixel(dim_t const RGBA_);

   static Pixel * createHisto (ym::uint32 const HistoSize);
   static void    destroyHisto(Pixel *    const histo_Ptr);

   constexpr auto isZero(void) const { 
      return r == 0.0 && g == 0.0 && b == 0.0 && a == 0.0;
   }

   constexpr auto operator + (Pixel const & Rhs) const { return Pixel(r + Rhs.r, g + Rhs.g, b + Rhs.b, a + Rhs.a); }
   constexpr auto operator - (Pixel const & Rhs) const { return Pixel(r - Rhs.r, g - Rhs.g, b - Rhs.b, a - Rhs.a); }
   constexpr auto operator * (Pixel const & Rhs) const { return Pixel(r * Rhs.r, g * Rhs.g, b * Rhs.b, a * Rhs.a); }
   constexpr auto operator / (Pixel const & Rhs) const { return Pixel(r / Rhs.r, g / Rhs.g, b / Rhs.b, a / Rhs.a); }
   constexpr auto operator ^ (Pixel const & Rhs) const { return Pixel(std::pow(r, Rhs.r),
                                                                      std::pow(g, Rhs.g),
                                                                      std::pow(b, Rhs.b),
                                                                      std::pow(a, Rhs.a)); }

   constexpr Pixel & operator += (Pixel const & Rhs) { return *this = *this + Rhs; }
   constexpr Pixel & operator -= (Pixel const & Rhs) { return *this = *this - Rhs; }
   constexpr Pixel & operator *= (Pixel const & Rhs) { return *this = *this * Rhs; }
   constexpr Pixel & operator /= (Pixel const & Rhs) { return *this = *this / Rhs; }
   constexpr Pixel & operator ^= (Pixel const & Rhs) { return *this = *this ^ Rhs; }

   dim_t r; // red
   dim_t g; // green
   dim_t b; // blue
   dim_t a; // alpha
};

/** Pixel
 *
 * @brief Constructor.
 */
constexpr Pixel::Pixel(void)
   : Pixel(0.0)
{
}

/** Pixel
 *
 * @brief Constructor.
 * 
 * @param R_ -- Initial red value.
 * @param G_ -- Initial green value.
 * @param B_ -- Initial blue value.
 * @param A_ -- Initial alpha value.
 */
constexpr Pixel::Pixel(dim_t const R_,
                       dim_t const G_,
                       dim_t const B_,
                       dim_t const A_)
   : r{R_}, g{G_}, b{B_}, a{A_}
{
}

/** Pixel
 *
 * @brief Constructor.
 * 
 * @note This constructor is used (and why it is implicit) to perform operations with scalars.
 * 
 * @param RGBA_ -- Initial value of r, g, b, and a.
 */
constexpr Pixel::Pixel(dim_t const RGBA_)
   : Pixel(RGBA_, RGBA_, RGBA_, RGBA_)
{
}

} // flame
