/**
 * @file    point.h
 * @version 1.0.0
 * @author  Forrest Jablonski
 */

#pragma once

#include "ymdefs.h"

#include "fastmath.h"

#include <cmath>

namespace flame
{

/** Point
 * 
 * @brief Representation of a point in 2D space: either cartesian plane, imaginary plane,
 *        polar coordinates, whatever.
 * 
 * @note This class is specific for this program, it is the users responsibility to avoid
 *       dividing by 0, or doing anything as dangerous.
 */
struct Point
{
   using dim_t = ym::float64;

   explicit    constexpr Point(void);
   explicit    constexpr Point(dim_t const X_,
                               dim_t const Y_);
   YM_IMPLICIT constexpr Point(dim_t const XY_);

   constexpr auto isZero(void) const { return x == 0.0 && y == 0.0; }

   constexpr Point operator + (Point const & Rhs) const { return Point(x + Rhs.x, y + Rhs.y); }
   constexpr Point operator - (Point const & Rhs) const { return Point(x - Rhs.x, y - Rhs.y); }
   constexpr Point operator * (Point const & Rhs) const { return Point(x * Rhs.x, y * Rhs.y); }
   constexpr Point operator / (Point const & Rhs) const { return Point(x / Rhs.x, y / Rhs.y); }
   constexpr Point operator ^ (Point const & Rhs) const { return Point(std::pow(x, Rhs.x),
                                                                       std::pow(y, Rhs.y)); }

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
constexpr Point::Point(void)
   : Point(0.0)
{
}

/** Point
 *
 * @brief Constructor.
 * 
 * @param X_ -- Initial value of x.
 * @param Y_ -- Initial value of y.
 */
constexpr Point::Point(dim_t const X_,
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
 * @param XY_ -- Initial value of x and y.
 */
constexpr Point::Point(dim_t const XY_)
   : Point(XY_, XY_)
{
}

} // flame
