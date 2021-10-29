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

   static constexpr float32 Pi = 3.1415926536f;

   static float32 sin(float32 x_rad);
};

} // hoso
