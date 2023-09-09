/**
 * @file    flame.h
 * @version 1.0.0
 * @author  Forrest Jablonski
 */

/*
 * g++ -std=c++2a -Ofast *.cpp -pthread `libpng-config --cflags --ldflags`
 */

#include "ymdefs.h"

#include "pixel.h"
#include "render.h"

#include <png++/png.hpp>

/** main
 *
 * @brief kick-off.
 */
int main([[maybe_unused]] int             const Argc,
         [[maybe_unused]] ym::str const * const Argv)
{
   constexpr ym::uint64 NIters      = 1'000'000'000ul;
   constexpr ym::uint32 Width_pxls  = 1920u / 4u;
   constexpr ym::uint32 Height_pxls = 1080u / 4u;

   auto const * const Histo_Ptr = flame::Render::lightFlame(NIters, Width_pxls, Height_pxls);

   // 
   //                 Width
   //           x0 x1 x2 x3 x4 x5
   //        y0
   // Height y1
   //        y2
   // 

   png::image<png::rgba_pixel> image(Width_pxls, Height_pxls);

   for (ym::uint32 y = 0u; y < Height_pxls; ++y)
   {
      for (ym::uint32 x = 0u; x < Width_pxls; ++x)
      {
         auto const & Pxl = Histo_Ptr[(y * Width_pxls) + x];

         auto const R = static_cast<ym::uint8>((Pxl.r * 255.0) + 0.5);
         auto const G = static_cast<ym::uint8>((Pxl.g * 255.0) + 0.5);
         auto const B = static_cast<ym::uint8>((Pxl.b * 255.0) + 0.5);
         auto const A = static_cast<ym::uint8>((Pxl.a * 255.0) + 0.5);

         image[y][x] = png::rgba_pixel(R, G, B, A);
      }
   }

   flame::Render::destroyHisto(Histo_Ptr);

   image.write("./pics/fractal-1.0.png");

   return 0;
}
