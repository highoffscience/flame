/**
 * @author Forrest Jablonski
 */

#pragma once

#include <cmath>

#ifdef FCT_DEBUG_PIXEL
#include <iostream>
#endif // FCT_DEBUG_PIXEL

#include "Standard.h"

namespace fct
{

/**
 * Represents a pixel implemented by using the rgba color space
 */
struct Pixel
{
   float r; // red
   float g; // green
   float b; // blue
   float a; // alpha

   /**
    * Initializes all the channels to zero
    */
   constexpr Pixel()
      : Pixel(0.0F, // r
              0.0F, // g
              0.0F, // b
              0.0F) // a
   { }

   /**
    * Initializes all the channels to the corresponding parameters
    */
   constexpr Pixel(float r_,
                   float g_,
                   float b_,
                   float a_)
      : r(r_),
        g(g_),
        b(b_),
        a(a_)
   { }

   // default the big three
   inline ~Pixel() = default;
   constexpr Pixel(const Pixel& rhs) = default;
   constexpr Pixel& operator = (const Pixel& rhs) = default;

   // ------------------------------------------------------------------
   // -------------------------- Declarations --------------------------
   // ------------------------------------------------------------------

   constexpr Pixel operator + (const Pixel& rhs) const;
   constexpr Pixel operator - (const Pixel& rhs) const;
   constexpr Pixel operator * (const Pixel& rhs) const;
   constexpr Pixel operator / (const Pixel& rhs) const;
   constexpr Pixel operator ^ (const Pixel& rhs) const;

   constexpr Pixel operator + (const float  rhs) const;
   constexpr Pixel operator - (const float  rhs) const;
   constexpr Pixel operator * (const float  rhs) const;
   constexpr Pixel operator / (const float  rhs) const;
   constexpr Pixel operator ^ (const float  rhs) const;

   /**
    * Self assigns the result of the given operation
    */
   constexpr void operator += (const Pixel& rhs) { *this = *this + rhs; }
   constexpr void operator -= (const Pixel& rhs) { *this = *this - rhs; }
   constexpr void operator *= (const Pixel& rhs) { *this = *this * rhs; }
   constexpr void operator /= (const Pixel& rhs) { *this = *this / rhs; }
   constexpr void operator ^= (const Pixel& rhs) { *this = *this ^ rhs; }

   /**
    * Self assigns the result of the given operation
    */
   constexpr void operator += (const float  rhs) { *this = *this + rhs; }
   constexpr void operator -= (const float  rhs) { *this = *this - rhs; }
   constexpr void operator *= (const float  rhs) { *this = *this * rhs; }
   constexpr void operator /= (const float  rhs) { *this = *this / rhs; }
   constexpr void operator ^= (const float  rhs) { *this = *this ^ rhs; }

}; // Pixel

// ------------------------------- Debug -------------------------------

#ifdef FCT_DEBUG_PIXEL
   /**
    * Prints the channels in a human-readable form
    */
   inline std::ostream& operator << (std::ostream& os, const Pixel& pxl)
   {
      os << "(" << pxl.r << ", "
                << pxl.g << ", "
                << pxl.b << ", "
                << pxl.a << ")";

      return os;
   }
#endif // FCT_DEBUG_PIXEL

// ---------------------------------------------------------------------
// ---------------------------- Definitions ----------------------------
// ---------------------------------------------------------------------

/**
 * Adds this pixel with rhs color channel wise and returns the result
 */
constexpr Pixel Pixel::operator + (const Pixel& rhs) const
{
   return Pixel(r + rhs.r,
                g + rhs.g,
                b + rhs.b,
                a + rhs.a);
}

/**
 * Subtracts this pixel with rhs color channel wise and returns the result
 */
constexpr Pixel Pixel::operator - (const Pixel& rhs) const
{
   return Pixel(r - rhs.r,
                g - rhs.g,
                b - rhs.b,
                a - rhs.a);
}

/**
 * Multiplies this pixel with rhs color channel wise and returns the result
 */
constexpr Pixel Pixel::operator * (const Pixel& rhs) const
{
   return Pixel(r * rhs.r,
                g * rhs.g,
                b * rhs.b,
                a * rhs.a);
}

/**
 * Divides this pixel with rhs color channel wise and returns the result
 */
constexpr Pixel Pixel::operator / (const Pixel& rhs) const
{
   return Pixel(r / rhs.r,
                g / rhs.g,
                b / rhs.b,
                a / rhs.a);
}

/**
 * Exponentiates this pixel with rhs color channel wise and returns the result
 */
constexpr Pixel Pixel::operator ^ (const Pixel& rhs) const
{
   return Pixel(std::pow(r, rhs.r),
                std::pow(g, rhs.g),
                std::pow(b, rhs.b),
                std::pow(a, rhs.a));
}

/**
 * Adds each color channel with rhs and returns the result
 */
constexpr Pixel Pixel::operator + (const float rhs) const
{
   return Pixel(r + rhs,
                g + rhs,
                b + rhs,
                a + rhs);
}

/**
 * Subtracts each color channel with rhs and returns the result
 */
constexpr Pixel Pixel::operator - (const float rhs) const
{
   return Pixel(r - rhs,
                g - rhs,
                b - rhs,
                a - rhs);
}

/**
 * Multiplies each color channel with rhs and returns the result
 */
constexpr Pixel Pixel::operator * (const float rhs) const
{
   return Pixel(r * rhs,
                g * rhs,
                b * rhs,
                a * rhs);
}

/**
 * Divides each color channel with rhs and returns the result
 */
constexpr Pixel Pixel::operator / (const float rhs) const
{
   return Pixel(r / rhs,
                g / rhs,
                b / rhs,
                a / rhs);
}

/**
 * Exponentiates each color channel with rhs and returns the result
 */
constexpr Pixel Pixel::operator ^ (const float rhs) const
{
   return Pixel(std::pow(r, rhs),
                std::pow(g, rhs),
                std::pow(b, rhs),
                std::pow(a, rhs));
}

} // fct
