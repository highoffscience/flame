/**
 * @author Forrest Jablonski
 */

#include "fastmath.h"

#include <cstdio>

// /**
//  * TODO doesn't work
//  */
// auto hoso::FastMath::cos(float32 x_rad) -> float32
// {
//    return 0.0f;
//
//    // // wrap into interval [-Tau..Tau]
//    // x_rad = fmod(x_rad, Tau);
// //
//    // // map into interval [-Pi..Pi]
//    //      if (x_rad < -Pi) { x_rad += Tau; }
//    // else if (x_rad > +Pi) { x_rad -= Tau; }
// //
//    // // method only works in interval [-Pi/2..Pi/2]
//    // constexpr auto Pi2     = Pi * Pi;
//    // constexpr auto Pi_by_2 = 0.5f * Pi;
//    // auto b = fabs(x_rad) - Pi_by_2;
//    // b = (Pi2 - (4.0f * b * b)) / (Pi2 + (b * b));
// //
//    // return (x_rad < 0.0f) ? -b : b;
// }

/**
 *
 */
#if defined(DRIVE_HOSO_FASTMATH)
#include <cstdio>
#include <cmath>
int main(void)
{
   using hoso::flame::FastMath;
   using hoso::float32;
   auto const Begin = -1.0f * FastMath::Pi;
   auto const End   = 0;
   auto const Delta = 1.0f;
   auto max = 0.0f;
   for (auto x = Begin; x < End + Delta; x += Delta)
   {
      auto const Me = FastMath::cos(x);
      auto const Them = std::cos(x);
      auto const Diff = FastMath::fabs(Me - Them);
      if (Diff > max)
      {
         max = Diff;
      }
      std::printf("%+.7f <> %+.7f <> %.7f\n", Them, Me, Diff);
   }
   std::printf("max diff = %+.7f\n", max);
   return 0;
}
#endif // DRIVE_HOSO_FASTMATH
