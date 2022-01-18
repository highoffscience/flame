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
 */
auto hoso::flame::Render::flame(void) -> Pixel *
{
   auto   const HistoSize  = _Width * _Height;
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

   Point pnt(0.5,  // x
             0.5); // y
   dim_t clr = 0.5;

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

   constexpr auto InvGamma = static_cast<dim_t>(1.0 / (2.2)); // 2.2 - 4.0 is baseline
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
