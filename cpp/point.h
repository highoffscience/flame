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
   typedef float32 dim_t;

   explicit constexpr Point(void);
   explicit constexpr Point(dim_t const X_,
                            dim_t const Y_);

   constexpr auto isZero(void) const;

   constexpr auto pls(Point const & Rhs) const;
   constexpr auto mns(Point const & Rhs) const;
   constexpr auto tms(Point const & Rhs) const;
   constexpr auto dvd(Point const & Rhs) const;

   constexpr auto pls(dim_t const Rhs) const;
   constexpr auto mns(dim_t const Rhs) const;
   constexpr auto tms(dim_t const Rhs) const;
   constexpr auto dvd(dim_t const Rhs) const;

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
constexpr auto Point::pls(Point const & Rhs) const
{
   return Point(x + Rhs.x,
                y + Rhs.y);
}

/**
 * 
 */
constexpr auto Point::mns(Point const & Rhs) const
{
   return Point(x - Rhs.x,
                y - Rhs.y);
}

/**
 * 
 */
constexpr auto Point::tms(Point const & Rhs) const
{
   return Point(x * Rhs.x,
                y * Rhs.y);
}

/**
 * 
 */
constexpr auto Point::dvd(Point const & Rhs) const
{
   return Point(x / Rhs.x,
                y / Rhs.y);
}

/**
 * 
 */
constexpr auto Point::pls(dim_t const Rhs) const
{
   return Point(x + Rhs,
                y + Rhs);
}

/**
 * 
 */
constexpr auto Point::mns(dim_t const Rhs) const
{
   return Point(x - Rhs,
                y - Rhs);
}

/**
 * 
 */
constexpr auto Point::tms(dim_t const Rhs) const
{
   return Point(x * Rhs,
                y * Rhs);
}

/**
 * 
 */
constexpr auto Point::dvd(dim_t const Rhs) const
{
   return Point(x / Rhs,
                y / Rhs);
}

} // hoso::flame
