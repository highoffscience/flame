/**
 * @author Forrest Jablonski
 */

#include "fastmath.h"

#include <cmath>

/**
 * TODO wrap X_rad, add check for negation
 */
auto hoso::FastMath::sin(float32 x_rad) -> float32
{
   x_rad = std::fmod(x_rad, FastMath::Pi);
   if (x_rad < 0.0f)
   {
      auto const T = 4.0f * -x_rad * (Pi + x_rad);
      return -(4.0f * T) / ((5.0f * Pi * Pi) - T);
   }
   else
   {
      auto const T = 4.0f * x_rad * (Pi - x_rad);
      return (4.0f * T) / ((5.0f * Pi * Pi) - T);
   }
}

/**
 *
 */
#if defined(DRIVE_HOSO_FASTMATH)
#include <cstdio>
#include <cmath>
int main(void)
{
   using hoso::FastMath;
   using hoso::float32;
   // this is the only interval the approx is good for
   float32 const Range = 2.0f*FastMath::Pi;
   for (auto x = -Range; x <= Range; x += 0.1f)
   {
      std::printf("%.7f -- %.7f\n", std::sin(x), FastMath::sin(x));
   }
   return 0;
}
#endif // DRIVE_HOSO_FASTMATH
