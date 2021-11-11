/**
 * @author Forrest Jablonski
 */

#include "colorscheme.h"
#include "fastmath.h"
#include "fitter.h"
#include "pixel.h"
#include "point.h"
#include "random.h"
#include "render.h"
#include "strangeattractor.h"
#include "varblend.h"

#include <cmath>
#include <iostream>

hoso::flame::Render::Render(uint32 const Width,
                            uint32 const Height)
   : _Width  {Width },
     _Height {Height}
{
}

/**
 *
 */
inline auto hoso::flame::Render::getIndex(uint32 const X,
                                          uint32 const Y) const -> uint32
{
   return X * _Height + Y;
}

/**
 *
 */
void hoso::flame::Render::populate(Pixel * const histo_Ptr) const
{
   Random rand;

   Point pnt((2.0 * rand.gen<Point::dim_t>()) - 1.0,  // x
             (2.0 * rand.gen<Point::dim_t>()) - 1.0); // y
   auto clr = rand.gen<Pixel::dim_t>();

   StrangeAttractor sa;
   VarBlend vb;

   for (uint i = 0; i < 100; ++i)
   {
      auto const Transform_idx = sa.preTransform(pnt, clr);
      pnt = vb.apply(Transform_idx, pnt);
      sa.postTransform(pnt, clr);
   }

   auto minFitPnt = pnt;
   auto maxFitPnt = pnt;
   for (uint i = 0; i < 10'000; ++i)
   {
      auto const Transform_idx = sa.preTransform(pnt, clr);
      pnt = vb.apply(Transform_idx, pnt);
      sa.postTransform(pnt, clr);

      if (pnt.x < minFitPnt.x) { minFitPnt.x = pnt.x; }
      if (pnt.x > maxFitPnt.x) { maxFitPnt.x = pnt.x; }
      if (pnt.y < minFitPnt.y) { minFitPnt.y = pnt.y; }
      if (pnt.y > maxFitPnt.y) { maxFitPnt.y = pnt.y; }
   }
   Fitter const Fit(_Width, _Height, minFitPnt, maxFitPnt);

   ColorScheme cs;

   constexpr uint64 NIters = 10'000'000ull;
   for (uint64 i = 0; i < NIters; ++i)
   {
      auto const Transform_idx = sa.preTransform(pnt, clr);
      pnt = vb.apply(Transform_idx, pnt);
      sa.postTransform(pnt, clr);

      auto const FitPnt = Fit.apply(pnt);

      auto const X =           static_cast<int32>(FitPnt.x);
      auto const Y = _Height - static_cast<int32>(FitPnt.y);

      if (X >= 0 && X < _Width &&
          Y >= 0 && Y < _Height)
      {
         histo_Ptr[getIndex(X, Y)]   += cs.apply(clr);
         histo_Ptr[getIndex(X, Y)].a += 1.0;
      }
   }

   // TODO following should be in another class?

   float64 alphaMax = 0.0;
   for (uint i = 0; i < _Width * _Height; ++i)
   {
      auto & pxl = histo_Ptr[i];

      if (pxl.a > Pixel::Zero)
      {
         pxl      *= std::log(pxl.a) / pxl.a;
         alphaMax  = FastMath::max(alphaMax, pxl.a);
      }
   }

   constexpr auto InvGamma = static_cast<Pixel::dim_t>(1.0 / (2.2)); // 2.2 - 4.0 is baseline
   for (uint i = 0; i < _Width * _Height; ++i)
   {
      auto & pxl = histo_Ptr[i];

      if (pxl.a > Pixel::Zero)
      {
         pxl /= alphaMax;
         pxl ^= InvGamma;
      }
   }
}
