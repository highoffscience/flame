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
 * Representation of a point in 2D space
 * Either cartesian plane or imaginary plane
 * Or polar coordinates, whatever
 */
struct Point
{
   using dim_t = float64;
   static_assert(std::is_floating_point_v<dim_t>, "Point coordinates must be floating points!");

   static constexpr auto Zero = static_cast<dim_t>(0.0);

   explicit constexpr Point(void);
   explicit constexpr Point(dim_t const X_,
                            dim_t const Y_);
   implicit constexpr Point(dim_t const XY_);

   constexpr auto isZero(void) const;

   constexpr auto operator +  (Point const & Rhs) const;
   constexpr auto operator -  (Point const & Rhs) const;
   constexpr auto operator *  (Point const & Rhs) const;
   constexpr auto operator /  (Point const & Rhs) const;
   constexpr auto operator ^  (Point const & Rhs) const;

   constexpr void operator += (Point const & Rhs);
   constexpr void operator -= (Point const & Rhs);
   constexpr void operator *= (Point const & Rhs);
   constexpr void operator /= (Point const & Rhs);
   constexpr void operator ^= (Point const & Rhs);

   dim_t x;
   dim_t y;
};

/**
 *
 */
constexpr Point::Point(void)
   : Point(Zero)
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
constexpr Point::Point(dim_t const XY_)
   : Point(XY_)
{
}

/**
 *
 */
constexpr auto Point::isZero(void) const
{
   return x == Zero &&
          y == Zero;
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
constexpr auto Point::operator ^ (Point const & Rhs) const
{
   return Point(std::pow(x, Rhs.x),
                std::pow(y, Rhs.y));
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
constexpr void Point::operator ^= (Point const & Rhs)
{
   *this = *this ^ Rhs;
}

} // hoso::flame
