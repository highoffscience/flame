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
#include <memory>

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
void hoso::flame::Render::flame(void)
{
   auto const HC = std::thread::hardware_concurrency();
   auto const NThreads = (HC == 0) ? 2 : HC;
   _executors.reserve(NThreads);

   // can call with std::free
   auto * const histos_Ptr =
      static_cast<Pixel *>(std::aligned_alloc(sizeof(Pixel),
                                              sizeof(Pixel) * _Width * _Height * NThreads));

   // this does not align!
   //auto * const hh = new Pixel[_Width * _Height * NThreads];

   // must call operator alignment delete[]
   //auto * const hh = new (std::align_val_t{sizeof(Pixel)}) Pixel[_Width * _Height * NThreads];

   // this does not align!
   std::allocator<Pixel> a;
   auto * const hh = a.allocate(_Width * _Height * NThreads);

   std::printf("%llu -- %llu\n", reinterpret_cast<uint64>(histos_Ptr)%sizeof(Pixel),
                                 reinterpret_cast<uint64>(hh)%sizeof(Pixel));
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

// /**
//  *
//  */
// void hoso::flame::Render::populate(Pixel * const histo_Ptr) const
// {
//    Random rand;
//
//    Point pnt((2.0 * rand.gen<Point::dim_t>()) - 1.0,  // x
//              (2.0 * rand.gen<Point::dim_t>()) - 1.0); // y
//    auto clr = rand.gen<Pixel::dim_t>();
//
//    StrangeAttractor sa;
//    VarBlend vb;
//
//    for (uint i = 0; i < 100; ++i)
//    {
//       auto const Transform_idx = sa.preTransform(pnt, clr);
//       pnt = vb.apply(Transform_idx, pnt);
//       sa.postTransform(pnt, clr);
//    }
//
//    auto minFitPnt = pnt;
//    auto maxFitPnt = pnt;
//    for (uint i = 0; i < 10'000; ++i)
//    {
//       auto const Transform_idx = sa.preTransform(pnt, clr);
//       pnt = vb.apply(Transform_idx, pnt);
//       sa.postTransform(pnt, clr);
//
//            if (pnt.x < minFitPnt.x) { minFitPnt.x = pnt.x; }
//       else if (pnt.x > maxFitPnt.x) { maxFitPnt.x = pnt.x; }
//
//            if (pnt.y < minFitPnt.y) { minFitPnt.y = pnt.y; }
//       else if (pnt.y > maxFitPnt.y) { maxFitPnt.y = pnt.y; }
//    }
//    Fitter const Fit(_Width, _Height, minFitPnt, maxFitPnt);
//
//    ColorScheme cs;
//
//    constexpr uint64 NIters = 1'000'000ull;
//    for (uint64 i = 0; i < NIters; ++i)
//    {
//       auto const Transform_idx = sa.preTransform(pnt, clr);
//       pnt = vb.apply(Transform_idx, pnt);
//       sa.postTransform(pnt, clr);
//
//       auto const FitPnt = Fit.apply(pnt);
//
//       auto const X =           static_cast<int32>(FitPnt.x);
//       auto const Y = _Height - static_cast<int32>(FitPnt.y);
//
//       if (X >= 0 && X < _Width &&
//           Y >= 0 && Y < _Height)
//       {
//          auto const Idx = Y * _Width + X;
//          histo_Ptr[Idx]   += cs.apply(clr);
//          histo_Ptr[Idx].a += 1.0;
//       }
//    }
//
//    // TODO following should be in another class?
//
//    float64 alphaMax = 0.0;
//    for (uint i = 0; i < _Width * _Height; ++i)
//    {
//       auto & pxl = histo_Ptr[i];
//
//       if (pxl.a > Pixel::Zero)
//       {
//          pxl      *= std::log(pxl.a) / pxl.a;
//          alphaMax  = FastMath::max(alphaMax, pxl.a);
//       }
//    }
//
//    constexpr auto InvGamma = static_cast<Pixel::dim_t>(1.0 / (2.2)); // 2.2 - 4.0 is baseline
//    for (uint i = 0; i < _Width * _Height; ++i)
//    {
//       auto & pxl = histo_Ptr[i];
//
//       if (pxl.a > Pixel::Zero)
//       {
//          pxl /= alphaMax;
//          pxl ^= InvGamma;
//       }
//    }
// }
