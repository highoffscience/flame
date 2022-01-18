/**
 * @author Forrest Jablonski
 */

/*
 * g++ -std=c++2a -Ofast *.cpp -pthread `libpng-config --cflags --ldflags`
 */

#include "hoso.h"
#include "pixel.h"
#include "render.h"

#include <memory>
#include <png++/png.hpp>

/**
 *
 */
int main(const int argc, const char* const* const argv)
{
   using namespace hoso;
   using namespace flame;

   constexpr uint64 NIters = 1'000'000ull;
   constexpr uint32 Width  = 1920;
   constexpr uint32 Height = 1080;

   Render rend(NIters, Width, Height);
   auto * const histo_Ptr = rend.flame();

   /*
    *              Width
    *           x0 x1 x2 x3 x4 x5
    *        y0
    * Height y1
    *        y2
    */

   png::image<png::rgba_pixel> image(Width, Height);

   for (uint y = 0; y < Height; ++y)
   {
      for (uint x = 0; x < Width; ++x)
      {
         auto const & pxl = histo_Ptr[y * Width + x];

         auto const R = static_cast<uint8>((pxl.r * 255.0) + 0.5);
         auto const G = static_cast<uint8>((pxl.g * 255.0) + 0.5);
         auto const B = static_cast<uint8>((pxl.b * 255.0) + 0.5);
         auto const A = static_cast<uint8>((pxl.a * 255.0) + 0.5);

         // TODO is this correct? or do I want x, y?
         image[y][x] = png::rgba_pixel(R, G, B, A);
      }
   }

   Pixel::destroyHisto(histo_Ptr);

   image.write("./pics/fractal-1.0.png");

   return 0;
}
