/**
 * @author Forrest Jablonski
 */

#pragma once

#include "hoso.h"

namespace hoso
{

/**
 *
 */
class FastMath
{
public:
   explicit FastMath(void) = delete;

   static constexpr float32 Pi  = 3.1415926536f;
   static constexpr float32 Tau = 2.0f * Pi;

   static constexpr float32 fmod(float32 const X,
                                 float32 const Y);

   static constexpr float32 fabs(float32 const X);

   static float32 sin(float32 x_rad);
   static float32 cos(float32 x_rad);
};

/**
 *
 */
constexpr float32 FastMath::fmod(float32 const X,
                                 float32 const Y)
{
   return X - (static_cast<long>(X / Y) * Y);
}

/**
 *
 */
constexpr float32 FastMath::fabs(float32 const X)
{
   return (X < 0.0f) ? -X : X;
}

} // hoso
