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
#include <cstdio>
#include <cstdlib>

hoso::flame::Render::Render(uint64 const NIters,
                            uint32 const Width,
                            uint32 const Height)
   : _executors {      },
     _Cs        {      },
     _Sa        {      },
     _Vb        {      },
     _NIters    {NIters},
     _Width     {Width },
     _Height    {Height}
{
}

/**
 * TODO need to calculate center of mass,
 *      or perform best fit
 */
auto hoso::flame::Render::flame(void) -> Pixel *
{
   // TODO image is fuzzier with more threads
   //      The image across different threads actually produce slightly different images.
   //      I loaded them in gimp and tried to overlay them and there are slight
   //      differences. Unless I can someone jump ahead in the attractor I don't think
   //      multiple threads will produce better results. Unfortunately.
   //      Even if the starting points and color is the same, the images produced are different
   //      and cannot be overlayed.
   auto const HC = std::thread::hardware_concurrency();
   auto const NThreads = 1; //(HC == 0) ? 2 : HC;

   auto   const HistoSize  = _Width * _Height;
   auto * const histos_Ptr = Pixel::createHisto(HistoSize * NThreads);

   _executors.reserve(NThreads);
   for (uint32 i = 0; i < NThreads; ++i)
   {
      _executors.emplace_back(&Render::populate, this, histos_Ptr + (i * HistoSize), i);
   }
   for (auto & executor_ref : _executors)
   {
      executor_ref.join();
   }

   auto * const mainHisto_Ptr = Pixel::createHisto(HistoSize);
   for (uint32 i = 0; i < NThreads; ++i)
   {
      // // TODO fix this
      auto * const tmpHisto_Ptr = histos_Ptr + (i * HistoSize);
      // Point com; // centre of mass
      // auto mass = Point::Zero;
      // for (uint32 y = 0; y < _Height; ++y)
      // {
      //    for (uint32 x = 0; x < _Width; ++x)
      //    {
      //       auto const Idx = y * _Width + x;
      //       com.x += (x + 0.5) * tmpHisto_Ptr[Idx].a;
      //       com.y += (y + 0.5) * tmpHisto_Ptr[Idx].a;
      //       mass += tmpHisto_Ptr[Idx].a;
      //    }
      // }
      // com.x /= mass;
      // com.y /= mass;
      for (uint32 j = 0; j < HistoSize; ++j)
      {
         // TODO +=
         mainHisto_Ptr[j] = tmpHisto_Ptr[j];
      }
   }

   Pixel::destroyHisto(histos_Ptr);

   postProcess(mainHisto_Ptr, HistoSize);

   return mainHisto_Ptr;
}

/**
 *
 */
void hoso::flame::Render::populate(Pixel * const histo_Ptr,
                                   uint32  const JumpNumber) const
{
   Random rand;
   rand.jump(JumpNumber);

   // TODO I don't think this works if it comes out 0, 0
   // Point pnt((2.0 * rand.gen<Point::dim_t>()) - 1.0,  // x
   //           (2.0 * rand.gen<Point::dim_t>()) - 1.0); // y
   // auto clr = rand.gen<Pixel::dim_t>();

   // TODO I don't think this works if it comes out 0, 0
   Point pnt(0.5,  // x
             0.5); // y
   Pixel::dim_t clr = 0.5;

   for (uint i = 0; i < 100; ++i)
   {
      auto const Transform_idx = _Sa.preTransform(pnt, clr, rand);
      pnt = _Vb.apply(Transform_idx, pnt);
      _Sa.postTransform(pnt, clr, rand);
   }

   auto minFitPnt = pnt;
   auto maxFitPnt = pnt;
   for (uint i = 0; i < 10'000; ++i)
   {
      auto const Transform_idx = _Sa.preTransform(pnt, clr, rand);
      pnt = _Vb.apply(Transform_idx, pnt);
      _Sa.postTransform(pnt, clr, rand);

           if (pnt.x < minFitPnt.x) { minFitPnt.x = pnt.x; }
      else if (pnt.x > maxFitPnt.x) { maxFitPnt.x = pnt.x; }

           if (pnt.y < minFitPnt.y) { minFitPnt.y = pnt.y; }
      else if (pnt.y > maxFitPnt.y) { maxFitPnt.y = pnt.y; }
   }
   Fitter const Fit(_Width, _Height, minFitPnt, maxFitPnt);

   for (uint64 i = 0; i < _NIters; ++i)
   {
      auto const Transform_idx = _Sa.preTransform(pnt, clr, rand);
      pnt = _Vb.apply(Transform_idx, pnt);
      _Sa.postTransform(pnt, clr, rand);

      auto const FitPnt = Fit.apply(pnt);

      auto const X =           static_cast<int32>(FitPnt.x);
      auto const Y = _Height - static_cast<int32>(FitPnt.y);

      // TODO I think this can be optimized by only comparing the bounds
      //      on Idx (ie Idx > 0 && Idx < HistoSize)
      //      Further, exploiting int -> uint, maybe just Idx < HistoSize?
      if (X >= 0 && X < _Width &&
          Y >= 0 && Y < _Height)
      {
         auto const Idx = Y * _Width + X;
         histo_Ptr[Idx]   += _Cs.apply(clr);
         histo_Ptr[Idx].a += Pixel::One;
      }
   }
}

/**
 *
 */
void hoso::flame::Render::postProcess(Pixel * const histo_Ptr,
                                      uint32  const HistoSize) const
{
   auto alphaMax = Pixel::Zero;
   for (uint i = 0; i < HistoSize; ++i)
   {
      auto & pxl = histo_Ptr[i];

      if (pxl.a > Pixel::Zero)
      {
         pxl      *= std::log(pxl.a) / pxl.a;
         alphaMax  = FastMath::max(alphaMax, pxl.a);
      }
   }

   constexpr auto InvGamma = static_cast<Pixel::dim_t>(1.0 / (2.2)); // 2.2 - 4.0 is baseline
   for (uint i = 0; i < HistoSize; ++i)
   {
      auto & pxl = histo_Ptr[i];

      if (pxl.a > Pixel::Zero)
      {
         pxl /= alphaMax;
         pxl ^= InvGamma;
      }
   }
}
