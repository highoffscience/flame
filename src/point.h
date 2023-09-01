/**
 * @file    point.h
 * @version 1.0.0
 * @author  Forrest Jablonski
 */

#pragma once

#include "ym/common/ymdefs.h"

#include <cmath>
#include <type_traits>

namespace flame
{

/**
 * Representation of a point in 2D space
 * Either cartesian plane or imaginary plane
 * Or polar coordinates, whatever
 */
template <typename dim_t = ym::float64>
requires(std::is_floating_point_v<dim_t>)
struct Point
{
   explicit    constexpr Point(void);
   explicit    constexpr Point(dim_t const X_,
                               dim_t const Y_);
   YM_IMPLICIT constexpr Point(dim_t const XY_);

   constexpr auto isZero(void) const { return x == 0.0 && y == 0.0; }

   constexpr Point operator + (Point const & Rhs) const { return Point(x + Rhs.x, y + Rhs.y); }
   constexpr Point operator - (Point const & Rhs) const { return Point(x - Rhs.x, y - Rhs.y); }
   constexpr Point operator * (Point const & Rhs) const { return Point(x * Rhs.x, y * Rhs.y); }
   constexpr Point operator / (Point const & Rhs) const { return Point(x / Rhs.x, y / Rhs.y); }
   constexpr Point operator ^ (Point const & Rhs) const { return Point(std::pow(x, Rhs.x), std::pow(y + Rhs.y)); }

   constexpr Point & operator += (Point const & Rhs) { return *this = *this + Rhs; }
   constexpr Point & operator -= (Point const & Rhs) { return *this = *this - Rhs; }
   constexpr Point & operator *= (Point const & Rhs) { return *this = *this * Rhs; }
   constexpr Point & operator /= (Point const & Rhs) { return *this = *this / Rhs; }
   constexpr Point & operator ^= (Point const & Rhs) { return *this = *this ^ Rhs; }

   dim_t x;
   dim_t y;
};

/** Point
 *
 * @brief Constructor.
 */
template <typename dim_t>
constexpr Point<dim_t>::Point(void)
   : Point(0.0, 0.0)
{
}

/** Point
 *
 * @brief Constructor.
 * 
 * @param X_ -- Initial value of x.
 * @param Y_ -- Initial value of y.
 */
template <typename dim_t>
constexpr Point<dim_t>::Point(dim_t const X_,
                              dim_t const Y_)
   : x {X_},
     y {Y_}
{
}

/** Point
 *
 * @brief Constructor.
 * 
 * @note This constructor is used (and why it is implicit) to perform operations with scalars.
 * 
 * @todo Is this approach just as fast as implementing functions that do scalar math directly?
 *       godbolt.org but be able to assist.
 * 
 * @param XY_ -- Initial value of x and y.
 */
template <typename dim_t>
constexpr Point<dim_t>::Point(dim_t const XY_)
   : Point(XY_, XY_)
{
}

} // flame
