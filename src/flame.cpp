/**
 * @file    flame.h
 * @version 1.0.0
 * @author  Forrest Jablonski
 */

#include "ymdefs.h"

#include "pixel.h"
#include "render.h"

#include "argparser.h"
#include "ops.h"

#include <png++/png.hpp>

/** main
 *
 * @brief Kick-off.
 */
int main(int             const Argc,
         ym::str const * const Argv)
{
   auto * const ap_Ptr = ym::ArgParser::getInstancePtr();
   ap_Ptr->parse({
      ap_Ptr->arg("niters").desc("# of iterations" ).abbr('n').val("1000000"),
      ap_Ptr->arg("width" ).desc("Width in pixels" ).abbr('w').val("480"    ),
      ap_Ptr->arg("height").desc("Height in pixels").abbr('t').val("270"    ),
   },
   Argc, Argv);

   auto const NIters      = ym::Ops::castTo<ym::uint64>(ap_Ptr->get("niters")->getVal());
   auto const Width_pxls  = ym::Ops::castTo<ym::uint32>(ap_Ptr->get("width" )->getVal());
   auto const Height_pxls = ym::Ops::castTo<ym::uint32>(ap_Ptr->get("height")->getVal());

   auto * const histo_Ptr = flame::Render::lightFlame(NIters, Width_pxls, Height_pxls);

   png::image<png::rgba_pixel> image(Width_pxls, Height_pxls);

   for (ym::uint32 y = 0u; y < Height_pxls; ++y)
   {
      for (ym::uint32 x = 0u; x < Width_pxls; ++x)
      {
         auto const & Pxl = histo_Ptr[(y * Width_pxls) + x];

         auto const R = static_cast<ym::uint8>((Pxl.r * 255.0) + 0.5);
         auto const G = static_cast<ym::uint8>((Pxl.g * 255.0) + 0.5);
         auto const B = static_cast<ym::uint8>((Pxl.b * 255.0) + 0.5);
         auto const A = static_cast<ym::uint8>((Pxl.a * 255.0) + 0.5);

         image[y][x] = png::rgba_pixel(R, G, B, A);
      }
   }

   flame::Render::destroyHisto(histo_Ptr, Width_pxls, Height_pxls);

   image.write("./pics/flame-1.0.png");

   return 0;
}
