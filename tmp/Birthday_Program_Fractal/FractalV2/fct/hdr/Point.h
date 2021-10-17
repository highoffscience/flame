/**
 * @author Forrest Jablonski
 */

#pragma once

#include <cmath>

#ifdef FCT_DEBUG_POINT
#include <iostream>
#endif // FCT_DEBUG_POINT

#include "Standard.h"

namespace fct
{

/**
 * Representation of a point in 2D space
 * Either cartesian plane or imaginary plane
 */
struct Point
{
   double x; // x-coordinate (real)
   double y; // y-coordinate (imaginary)

   /**
    * Initializes the coordinates to zero
    */
   constexpr Point()
      : Point(0.0, // x
              0.0) // y
   { }

   /**
    * Initializes the coordinates to the corresponding parameters
    */
   constexpr Point(double x_,
                   double y_)
      : x(x_),
        y(y_)
   { }

   // default the big three
   inline ~Point() = default;
   constexpr Point(const Point& rhs) = default;
   constexpr Point& operator = (const Point& rhs) = default;

   // ------------------------------------------------------------------
   // -------------------------- declarations --------------------------
   // ------------------------------------------------------------------

   // ---------------------------
   // Cartesian plane functions -
   // ---------------------------

   constexpr Point operator - () const;

   constexpr Point operator + (const Point& rhs) const;
   constexpr Point operator - (const Point& rhs) const;
   constexpr Point operator * (const Point& rhs) const;
   constexpr Point operator / (const Point& rhs) const;
   constexpr Point operator ^ (const Point& rhs) const;

   constexpr Point operator + (const double rhs) const;
   constexpr Point operator - (const double rhs) const;
   constexpr Point operator * (const double rhs) const;
   constexpr Point operator / (const double rhs) const;
   constexpr Point operator ^ (const double rhs) const;

   /**
    * Self assigns the result of the given operation
    */
   constexpr void operator += (const Point& rhs) { *this = *this + rhs; }
   constexpr void operator -= (const Point& rhs) { *this = *this - rhs; }
   constexpr void operator *= (const Point& rhs) { *this = *this * rhs; }
   constexpr void operator /= (const Point& rhs) { *this = *this / rhs; }
   constexpr void operator ^= (const Point& rhs) { *this = *this ^ rhs; }

   /**
    * Self assigns the result of the given operation
    */
   constexpr void operator += (const double rhs) { *this = *this + rhs; }
   constexpr void operator -= (const double rhs) { *this = *this - rhs; }
   constexpr void operator *= (const double rhs) { *this = *this * rhs; }
   constexpr void operator /= (const double rhs) { *this = *this / rhs; }
   constexpr void operator ^= (const double rhs) { *this = *this ^ rhs; }

   constexpr Point rev() const;

   // -------------------------
   // Complex plane functions -
   // -------------------------

   constexpr double cMod () const;
   constexpr double cMod2() const;
   constexpr double cArg () const;

   constexpr Point cPls(const Point& p) const;
   constexpr Point cMns(const Point& p) const;
   constexpr Point cTms(const Point& p) const;
   constexpr Point cDvd(const Point& p) const;

   constexpr Point cConj() const;
   constexpr Point cInv () const;

}; // Point

// ------------------------------- Debug -------------------------------

#ifdef FCT_DEBUG_PIXEL
   /**
    * Prints the coordinates in a human-readable form
    */
   inline std::ostream& operator << (std::ostream& os, const Point& pnt)
   {
      os << "(" << pnt.x << ", "
                << pnt.y << ")";

      return os;
   }
#endif // FCT_DEBUG_PIXEL

// ---------------------------------------------------------------------
// ---------------------------- Definitions ----------------------------
// ---------------------------------------------------------------------

// ---------------------------
// Cartesian plane functions -
// ---------------------------

/**
 * Negates this point coordinate wise and returns the result
 */
constexpr Point Point::operator - () const
{
   return Point(-x, -y);
}

/**
 * Adds this point with rhs coordinate wise and returns the result
 */
constexpr Point Point::operator + (const Point& rhs) const
{
   return Point(x + rhs.x,
                y + rhs.y);
}

/**
 * Subtracts this point with rhs coordinate wise and returns the result
 */
constexpr Point Point::operator - (const Point& rhs) const
{
   return Point(x - rhs.x,
                y - rhs.y);
}

/**
 * Multiplies this point with rhs coordinate wise and returns the result
 */
constexpr Point Point::operator * (const Point& rhs) const
{
   return Point(x * rhs.x,
                y * rhs.y);
}

/**
 * Divides this point with rhs coordinate wise and returns the result
 */
constexpr Point Point::operator / (const Point& rhs) const
{
   return Point(x / rhs.x,
                y / rhs.y);
}

/**
 * Exponentiates this point with rhs coordinate wise and returns the result
 */
constexpr Point Point::operator ^ (const Point& rhs) const
{
   return Point(std::pow(x, rhs.x),
                std::pow(y, rhs.y));
}

/**
 * Adds each coordinate of this point with rhs and returns the result
 */
constexpr Point Point::operator + (const double rhs) const
{
   return Point(x + rhs,
                y + rhs);
}

/**
 * Subtracts each coordinate of this point with rhs and returns the result
 */
constexpr Point Point::operator - (const double rhs) const
{
   return Point(x - rhs,
                y - rhs);
}

/**
 * Multiplies each coordinate of this point with rhs and returns the result
 */
constexpr Point Point::operator * (const double rhs) const
{
   return Point(x * rhs,
                y * rhs);
}

/**
 * Divides each coordinate of this point with rhs and returns the result
 */
constexpr Point Point::operator / (const double rhs) const
{
   return Point(x / rhs,
                y / rhs);
}

/**
 * Exponentiates each coordinate of this point with rhs and returns the result
 */
constexpr Point Point::operator ^ (const double rhs) const
{
   return Point(std::pow(x, rhs),
                std::pow(y, rhs));
}

/**
 * Reverses the coordinates and returns the result and returns the result
 */
constexpr Point Point::rev() const
{
   return Point(y, x);
}

// -------------------------
// Complex plane functions -
// -------------------------

/**
 * Computes the complex modulus and returns the result
 */
constexpr double Point::cMod() const
{
   return std::sqrt((x * x) + (y * y));
}

/**
 * Computes the square of the complex modulus and returns the result
 */
constexpr double Point::cMod2() const
{
   return (x * x) + (y * y);
}

/**
 * Computes the complex argument and returns the result
 */
constexpr double Point::cArg() const
{
   return std::atan2(y, x);
}

/**
 * Performs complex addition with this point and rhs and returns the result
 */
constexpr Point Point::cPls(const Point& rhs) const
{
   return Point(x + rhs.x,
                y + rhs.y);
}

/**
 * Performs complex subtraction with this point and rhs and returns the result
 */
constexpr Point Point::cMns(const Point& rhs) const
{
   return Point(x - rhs.x,
                y - rhs.y);
}

/**
 * Performs complex multiplication with this point and rhs and returns the result
 */
constexpr Point Point::cTms(const Point& rhs) const
{
   return Point((x * rhs.x) - (y * rhs.y),
                (x * rhs.y) + (y * rhs.x));
}

/**
 * Performs complex division with this point and rhs and returns the result
 */
constexpr Point Point::cDvd(const Point& rhs) const
{
   // cTms(rhs.cConj()) / rhs.cMod2()

   const double cmod2 = (rhs.x * rhs.x) +
                       (rhs.y * rhs.y);

   return Point(((x * rhs.x) + (y * rhs.y)) / cmod2,
                ((y * rhs.x) - (x * rhs.y)) / cmod2);
}

/**
 * Performs the complex conjugate and returns the result
 */
constexpr Point Point::cConj() const
{
   return Point(x, -y);
}

/**
 * Performs the complex inverse and returns the result
 */
constexpr Point Point::cInv() const
{
   return cConj() / cMod2();
}

} // fct
