/**
 * @file    render.cpp
 * @version 1.0.0
 * @author  Forrest Jablonski
 */

#include "render.h"

#include "colorscheme.h"
#include "fastmath.h"
#include "fitter.h"
#include "pixel.h"
#include "point.h"
#include "strangor.h"
#include "varblend.h"

#include "memio.h"
#include "prng.h"

#include <cstdio>
#include <cstdlib>

/** lightFlame
 *
 * @brief Produces and returns buffer to flame.
 */
auto flame::Render::lightFlame(ym::uint64 const NIters,
                               ym::uint32 const Width_pxls,
                               ym::uint32 const Height_pxls) -> Pixel *
{
   if (Width_pxls < 2u || Height_pxls < 2u)
   {
      return nullptr;
   }

   auto   const HistoSize_pxls = Width_pxls * Height_pxls;
   auto * const histo_Ptr      = ym::MemIO::alloc<Pixel>(HistoSize_pxls);

   for (ym::uint32 i = 0u; i < HistoSize_pxls; ++i)
   {
      histo_Ptr[i] = Pixel();
   }

   ym::PRNG prng;

   Pixel::dim_t clr = prng.gen<Pixel::dim_t>();
   Point        pnt;

   while (pnt.isZero())
   {
      pnt.x = (2.0 * prng.gen<Point::dim_t>()) - 1.0;
      pnt.y = (2.0 * prng.gen<Point::dim_t>()) - 1.0;
   }

   auto minPnt = pnt;
   auto maxPnt = pnt;

   for (ym::uint32 i = 0u; i < 10'000u; ++i)
   {
      auto const Transform_idx = Strangor::apply(prng.gen<ym::float64>(), pnt, clr);
      pnt = VarBlend::apply(Transform_idx, pnt);

      if (i > 20u)
      {
         if (pnt.x < minPnt.x) { minPnt.x = pnt.x; }
         if (pnt.y < minPnt.y) { minPnt.y = pnt.y; }

         if (pnt.x > maxPnt.x) { maxPnt.x = pnt.x; }
         if (pnt.y > maxPnt.y) { maxPnt.y = pnt.y; }
      }
   }

   Fitter const Fit(Width_pxls, Height_pxls, maxPnt, minPnt);

   for (ym::uint64 i = 0u; i < NIters; ++i)
   {
      auto const Transform_idx = Strangor::apply(prng.gen<ym::float64>(), pnt, clr);
      pnt = VarBlend::apply(Transform_idx, pnt);
      pnt = Fit.apply(pnt);

      if (pnt.x >= 0.0 && pnt.y >= 0.0)
      {
         auto const X = static_cast<ym::uint32>(pnt.x);
         auto const Y = static_cast<ym::uint32>(pnt.y);

         if (X < Width_pxls && Y < Height_pxls)
         {
            auto const Idx    = (((Height_pxls - 1u) - Y) * Width_pxls) + X; // flip Y to get image right side up
            histo_Ptr[Idx]   += ColorScheme::apply(clr);
            histo_Ptr[Idx].a += 1.0;
         }
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
