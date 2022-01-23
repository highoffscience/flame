/**
 * @author Forrest Jablonski
 */

#include "colorscheme.h"
#include "dim.h"
#include "fastmath.h"
#include "fitter.h"
#include "pixel.h"
#include "point.h"
#include "random.h"
#include "render.h"
#include "strangeattractor.h"
#include "varblend.h"

#include <cmath>
#include <cstdio>
#include <cstdlib>

hoso::flame::Render::Render(uint64 const NIters,
                            uint32 const Width,
                            uint32 const Height)
   : _Cs        {      },
     _Sa        {      },
     _Vb        {      },
     _NIters    {NIters},
     _Width     {Width },
     _Height    {Height}
{
}

/**
 * Images produced by different rngs generate different images, they cannot be overlayed
 *
 * TODO often times I want to rescale the image, so maybe multithreaded would be useful,
 *      record the states at opportune times and rerun
 *      After testing the speed benefits are as good as I thought. And fastforwarding
 *      the particle isn't significantly faster than iterating AND rendering. I thought
 *      I could have a rabbit and turtle thread but the rabbit isn't that much faster
 *      than the turtle.
 */
auto hoso::flame::Render::flame(void) -> Pixel *
{
   auto   const HistoSize = _Width * _Height;
   auto * const histo_Ptr = Pixel::createHisto(HistoSize);

   populate(histo_Ptr, 0);
   postProcess(histo_Ptr, HistoSize);

   return histo_Ptr;
}

/**
 *
 */
void hoso::flame::Render::populate(Pixel * const histo_Ptr,
                                   uint32  const JumpNumber) const
{
   Random rand;
   rand.jump(JumpNumber);

   Point pnt(0.5, 0.5);
   dim_t clr = 0.5;

   constexpr uint32 NFastForwards = 100;
   for (uint32 i = 0; i < NFastForwards; ++i)
   {
      auto const Transform_idx = _Sa.preTransform(pnt, clr, rand);
      pnt = _Vb.apply(Transform_idx, pnt);
      _Sa.postTransform(pnt, clr, rand);
   }

   auto minFitPnt = pnt;
   auto maxFitPnt = pnt;
   for (uint32 i = 0; i < 10'000; ++i)
   {
      auto const Transform_idx = _Sa.preTransform(pnt, clr, rand);
      pnt = _Vb.apply(Transform_idx, pnt);
      _Sa.postTransform(pnt, clr, rand);

           if (pnt.x < minFitPnt.x) { minFitPnt.x = pnt.x; }
      else if (pnt.x > maxFitPnt.x) { maxFitPnt.x = pnt.x; }

           if (pnt.y < minFitPnt.y) { minFitPnt.y = pnt.y; }
      else if (pnt.y > maxFitPnt.y) { maxFitPnt.y = pnt.y; }
   }
   std::printf("W %u, H %u, min (%f, %f), max (%f, %f)\n",
               _Width, _Height, minFitPnt.x, minFitPnt.y, maxFitPnt.x, maxFitPnt.y);
   minFitPnt.x = -2.0;
   minFitPnt.y = -2.0;
   maxFitPnt.x =  2.0;
   maxFitPnt.y =  2.0;
   Fitter const Fit(_Width, _Height, minFitPnt, maxFitPnt);

   for (uint64 i = 0; i < _NIters; ++i)
   {
      auto const Transform_idx = _Sa.preTransform(pnt, clr, rand);
      pnt = _Vb.apply(Transform_idx, pnt);
      _Sa.postTransform(pnt, clr, rand);

      auto const FitPnt = Fit.apply(pnt);

      auto const X =           static_cast<int32>(FitPnt.x);
      auto const Y = _Height - static_cast<int32>(FitPnt.y);

      if (X >= 0 && X < _Width &&
          Y >= 0 && Y < _Height)
      {
         auto const Idx = Y * _Width + X;
         histo_Ptr[Idx]   += _Cs.apply(clr);
         histo_Ptr[Idx].a += One;
      }
   }
}

/**
 *
 */
void hoso::flame::Render::postProcess(Pixel * const histo_Ptr,
                                      uint32  const HistoSize) const
{
   auto alphaMax = Zero;
   for (uint i = 0; i < HistoSize; ++i)
   {
      auto & pxl = histo_Ptr[i];

      if (pxl.a > Zero)
      {
         pxl      *= std::log(pxl.a) / pxl.a;
         alphaMax  = FastMath::max(alphaMax, pxl.a);
      }
   }

   constexpr auto InvGamma = 1.0_f / (2.2_f); // 2.2 - 4.0 is baseline
   for (uint i = 0; i < HistoSize; ++i)
   {
      auto & pxl = histo_Ptr[i];

      if (pxl.a > Zero)
      {
         pxl /= alphaMax;
         pxl ^= InvGamma;
      }
   }
}
