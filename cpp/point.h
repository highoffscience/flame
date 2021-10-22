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

   explicit constexpr inline Point(void);
   explicit constexpr inline Point(dim_t const X_,
                                   dim_t const Y_);

   constexpr inline auto isZero(void) const;

   constexpr inline auto pls(Point const & Rhs) const;
   constexpr inline auto mns(Point const & Rhs) const;
   constexpr inline auto tms(Point const & Rhs) const;
   constexpr inline auto dvd(Point const & Rhs) const;

   constexpr inline auto pls(dim_t const Rhs) const;
   constexpr inline auto mns(dim_t const Rhs) const;
   constexpr inline auto tms(dim_t const Rhs) const;
   constexpr inline auto dvd(dim_t const Rhs) const;

   dim_t x; // x-coordinate (real)
   dim_t y; // y-coordinate (imaginary)
};

/**
 *
 */
constexpr inline Point::Point(void)
   : Point(0.0, 0.0)
{
}

/**
 *
 */
constexpr inline Point::Point(dim_t const X_,
                              dim_t const Y_)
   : x {X_},
     y {Y_}
{
}

/**
 *
 */
constexpr inline auto Point::isZero(void) const
{
   return x == static_cast<dim_t>(0.0) &&
          y == static_cast<dim_t>(0.0);
}

/**
 * 
 */
constexpr inline auto Point::pls(Point const & Rhs) const
{
   return Point(x + Rhs.x,
                y + Rhs.y);
}

} // hoso::flame
