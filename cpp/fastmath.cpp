/**
 * @author Forrest Jablonski
 */

#include "fastmath.h"

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
