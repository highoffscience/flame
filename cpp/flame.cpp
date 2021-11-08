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

   constexpr uint32 width  = 960;
   constexpr uint32 height = 540;

   Pixel** histo = new Pixel*[height];
   for (uint i = 0U; i < height; ++i)
   {
      histo[i] = new Pixel[width];
   }

   Render rend;
   rend.populate(histo, width, height);

   png::image<png::rgba_pixel> image(width, height);

   for (uint i = 0U; i < height; ++i)
   {
      for (uint j = 0U; j < width; ++j)
      {
         const Pixel& pxl = histo[i][j];

         const uint8 r = (uint8) ((pxl.r * 255.0F) + 0.5F);
         const uint8 g = (uint8) ((pxl.g * 255.0F) + 0.5F);
         const uint8 b = (uint8) ((pxl.b * 255.0F) + 0.5F);
         const uint8 a = (uint8) ((pxl.a * 255.0F) + 0.5F);

         image[i][j] = png::rgba_pixel(r, g, b, a);
      }
   }

   image.write("./pics/fractal-1.0.png");

   for (uint i = 0U; i < height; ++i)
   {
      delete[] histo[i];
   }
   delete[] histo;

   return 0;
}
