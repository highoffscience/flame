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
 *
 */
auto hoso::flame::Render::flame(void) -> Pixel *
{
   // TODO image is dimmer with more threads
   auto const HC = std::thread::hardware_concurrency();
   auto const NThreads = 4; //(HC == 0) ? 2 : HC;

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
      auto * const tmpHisto_Ptr = histos_Ptr + (i * HistoSize);
      for (uint32 j = 0; j < HistoSize; ++j)
      {
         mainHisto_Ptr[j] += tmpHisto_Ptr[j];
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

   Point pnt((2.0 * rand.gen<Point::dim_t>()) - 1.0,  // x
             (2.0 * rand.gen<Point::dim_t>()) - 1.0); // y
   auto clr = rand.gen<Pixel::dim_t>();

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
