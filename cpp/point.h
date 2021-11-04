/**
 * @author Forrest Jablonski
 */

#pragma once

#include "hoso.h"

namespace hoso::flame
{

/**
 * Representation of a point in 2D space
 * Either cartesian plane or imaginary plane
 */
struct Point
{
   typedef float64 dim_t;

   explicit constexpr Point(void);
   explicit constexpr Point(dim_t const X_,
                            dim_t const Y_);

   constexpr auto isZero(void) const;

   constexpr auto operator + (Point const & Rhs) const;
   constexpr auto operator - (Point const & Rhs) const;
   constexpr auto operator * (Point const & Rhs) const;
   constexpr auto operator / (Point const & Rhs) const;

   constexpr auto operator + (dim_t const Rhs) const;
   constexpr auto operator - (dim_t const Rhs) const;
   constexpr auto operator * (dim_t const Rhs) const;
   constexpr auto operator / (dim_t const Rhs) const;

   constexpr void operator += (Point const & Rhs);
   constexpr void operator -= (Point const & Rhs);
   constexpr void operator *= (Point const & Rhs);
   constexpr void operator /= (Point const & Rhs);

   constexpr void operator += (dim_t const Rhs);
   constexpr void operator -= (dim_t const Rhs);
   constexpr void operator *= (dim_t const Rhs);
   constexpr void operator /= (dim_t const Rhs);

   dim_t x; // x-coordinate (real)
   dim_t y; // y-coordinate (imaginary)
};

/**
 *
 */
constexpr Point::Point(void)
   : Point(0.0, 0.0)
{
}

/**
 *
 */
constexpr Point::Point(dim_t const X_,
                       dim_t const Y_)
   : x {X_},
     y {Y_}
{
}

/**
 *
 */
constexpr auto Point::isZero(void) const
{
   return x == static_cast<dim_t>(0.0) &&
          y == static_cast<dim_t>(0.0);
}

/**
 *
 */
constexpr auto Point::operator + (Point const & Rhs) const
{
   return Point(x + Rhs.x,
                y + Rhs.y);
}

/**
 *
 */
constexpr auto Point::operator - (Point const & Rhs) const
{
   return Point(x - Rhs.x,
                y - Rhs.y);
}

/**
 *
 */
constexpr auto Point::operator * (Point const & Rhs) const
{
   return Point(x * Rhs.x,
                y * Rhs.y);
}

/**
 *
 */
constexpr auto Point::operator / (Point const & Rhs) const
{
   return Point(x / Rhs.x,
                y / Rhs.y);
}

/**
 *
 */
constexpr auto Point::operator + (dim_t const Rhs) const
{
   return Point(x + Rhs,
                y + Rhs);
}

/**
 *
 */
constexpr auto Point::operator - (dim_t const Rhs) const
{
   return Point(x - Rhs,
                y - Rhs);
}

/**
 *
 */
constexpr auto Point::operator * (dim_t const Rhs) const
{
   return Point(x * Rhs,
                y * Rhs);
}

/**
 *
 */
constexpr auto Point::operator / (dim_t const Rhs) const
{
   return Point(x / Rhs,
                y / Rhs);
}

/**
 *
 */
constexpr void Point::operator += (Point const & Rhs)
{
   *this = *this + Rhs;
}

/**
 *
 */
constexpr void Point::operator -= (Point const & Rhs)
{
   *this = *this - Rhs;
}

/**
 *
 */
constexpr void Point::operator *= (Point const & Rhs)
{
   *this = *this * Rhs;
}

/**
 *
 */
constexpr void Point::operator /= (Point const & Rhs)
{
   *this = *this / Rhs;
}

/**
 *
 */
constexpr void Point::operator += (dim_t const Rhs)
{
   *this = *this + Rhs;
}

/**
 *
 */
constexpr void Point::operator -= (dim_t const Rhs)
{
   *this = *this - Rhs;
}

/**
 *
 */
constexpr void Point::operator *= (dim_t const Rhs)
{
   *this = *this * Rhs;
}

/**
 *
 */
constexpr void Point::operator /= (dim_t const Rhs)
{
   *this = *this / Rhs;
}

} // hoso::flame
