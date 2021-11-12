/**
 * @author Forrest Jablonski
 */

/*
 * g++ -std=c++2a -O2 *.cpp `libpng-config --cflags --ldflags`
 */

#include "hoso.h"
#include "pixel.h"
#include "render.h"

#include <png++/png.hpp>

/**
 *
 */
int main(const int argc, const char* const* const argv)
{
   using namespace hoso;
   using namespace flame;

   constexpr uint32 Width  = 1920;
   constexpr uint32 Height = 1080;

   /*
    *              Width
    *           x0 x1 x2 x3 x4 x5
    *        y0
    * Height y1
    *        y2
    */
   Pixel * const histo_Ptr = new Pixel[Width * Height];

   Render rend(Width, Height);
   rend.populate(histo_Ptr);

   png::image<png::rgba_pixel> image(Width, Height);

   for (uint y = 0; y < Height; ++y)
   {
      for (uint x = 0; x < Width; ++x)
      {
         // TODO I don't think I've done this correctly
         auto const & pxl = histo_Ptr[y * Width + x];

         auto const R = static_cast<uint8>((pxl.r * 255.0) + 0.5);
         auto const G = static_cast<uint8>((pxl.g * 255.0) + 0.5);
         auto const B = static_cast<uint8>((pxl.b * 255.0) + 0.5);
         auto const A = static_cast<uint8>((pxl.a * 255.0) + 0.5);

         image[y][x] = png::rgba_pixel(R, G, B, A);
      }
   }

   image.write("./pics/fractal-1.0.png");

   delete[] histo_Ptr;

   return 0;
}
