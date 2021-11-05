/**
 * @author Forrest Jablonski
 */

#include "colorscheme.h"
#include "pixel.h"
#include "point.h"
#include "random.h"
#include "render.h"
#include "strangeattractor.h"
#include "varblend.h"

#include <cmath>
#include <iostream>
#include <limits>

/**
 *
 */
void hoso::flame::Render::populate(Pixel * const * const histo_Ptr_Ptr) const
{
   constexpr uint32 Width  = 960;
   constexpr uint32 Height = 540;

   Random rand;

   Point pnt((2.0 * rand.gen<Point::dim_t>()) - 1.0,  // x
             (2.0 * rand.gen<Point::dim_t>()) - 1.0); // y
   auto clr = rand.gen<Pixel::dim_t>();

   StrangeAttractor sa;
   VarBlend vb;

   for (uint i = 0U; i < 100U; ++i)
   {
      auto const Transform_idx = sa.preTransform(pnt, clr);
      pnt = vb.apply(Transform_idx, pnt);
      sa.postTransform(pnt, clr);
   }

   // { // create fitter
   //    Point minFitPnt = Point(std::numeric_limits<double>::max(),
   //                            std::numeric_limits<double>::max());
   //    Point maxFitPnt = Point(std::numeric_limits<double>::lowest(),
   //                            std::numeric_limits<double>::lowest());
//
   //    for (uint i = 0U; i < 10000U; ++i)
   //    {
   //       const uint index = sa::preTransform(pnt, clr);
   //       vb::transform(index, pnt);
   //       sa::postTransform(pnt, clr);
//
   //       if      (pnt.x < minFitPnt.x) { minFitPnt.x = pnt.x; }
   //       else if (pnt.x > maxFitPnt.x) { maxFitPnt.x = pnt.x; }
//
   //       if      (pnt.y < minFitPnt.y) { minFitPnt.y = pnt.y; }
   //       else if (pnt.y > maxFitPnt.y) { maxFitPnt.y = pnt.y; }
   //    }
//
   //    fit::init(minFitPnt, maxFitPnt);
   // } // end create fitter

   ColorScheme cs;

   constexpr uint64 NIters = 10'000'000ull;
   for (uint64 i = 0; i < NIters; ++i)
   {
      auto const Transform_idx = sa.preTransform(pnt, clr);
      pnt = vb.apply(Transform_idx, pnt);
      sa.postTransform(pnt, clr);

      // const Point fittedPnt = fit::transform(pnt);

      auto const X =          static_cast<int32>(75.0 * pnt.x + Width/2);
      auto const Y = Height - static_cast<int32>(75.0 * pnt.y + Height/2);

      if (X >= 0 && X < Width &&
          Y >= 0 && Y < Height)
      {
         histo_Ptr_Ptr[Y][X]   += cs.apply(clr);
         histo_Ptr_Ptr[Y][X].a += 1.0;
      }
   }

   float64 alphaMax = 0.0;
   for (uint i = 0; i < Height; ++i)
   {
      for (uint j = 0; j < Width; ++j)
      {
         Pixel& pxl = histo_Ptr_Ptr[i][j];

         if (pxl.a > 0.0f)
         {
            pxl *= std::log1p(pxl.a) / pxl.a;

            if (pxl.a > alphaMax)
            {
               alphaMax = pxl.a;
            }
         }
      }
   }

   // constexpr float64 invGamma = 1.0 / (2.2); // 2.2F..4.0F is baseline
   // for (uint i = 0; i < Height; ++i)
   // {
   //    for (uint j = 0; j < Width; ++j)
   //    {
   //       Pixel& pxl = histo_Ptr_Ptr[i][j];
//
   //       if (pxl.a > 0.0)
   //       {
   //          pxl /= alphaMax;
   //          pxl ^= invGamma;
   //       }
   //    }
   // }
}
