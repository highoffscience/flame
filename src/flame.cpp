/**
 * @file    flame.cpp
 * @version 1.0.0
 * @author  Forrest Jablonski
 */

#include "ymdefs.h"

#include "pixel.h"
#include "point.h"
#include "render.h"

#include "argparser.h"
#include "ops.h"
#include "textlogger.h"

#include <png++/png.hpp>

#include <string>

/** main
 *
 * @brief Kick-off.
 * 
 * @note (480, 270)  (960, 540)  (1920, 1080)
 */
int main(int             const Argc,
         ym::str const * const Argv)
{
   auto & ap = *ym::ArgParser::getInstancePtr();
   ap.parse({
      ap.arg("niters").desc("# of iterations"  ).abbr('n').val("1000000"  ),
      ap.arg("width" ).desc("Width in pixels"  ).abbr('w').val("480"      ),
      ap.arg("height").desc("Height in pixels" ).abbr('t').val("270"      ),
      ap.arg("output").desc("Output image name").abbr('o').val("flame-1.0"),
      ap.arg("sx"    ).desc("X scale"          )          .val("0"        ),
      ap.arg("sy"    ).desc("Y scale"          )          .val("0"        ),
      ap.arg("tx"    ).desc("X translation"    )          .val("0"        ),
      ap.arg("ty"    ).desc("Y translation"    )          .val("0"        ),
   },
   Argc, Argv);

   auto const NIters      = ym::Ops::castTo<ym::uint64>(ap["niters"]->getVal());
   auto const Width_pxls  = ym::Ops::castTo<ym::uint32>(ap["width" ]->getVal());
   auto const Height_pxls = ym::Ops::castTo<ym::uint32>(ap["height"]->getVal());

   auto const Sx = ym::Ops::castTo<ym::float64>(ap["sx"]->getVal());
   auto const Sy = ym::Ops::castTo<ym::float64>(ap["sy"]->getVal());
   auto const Tx = ym::Ops::castTo<ym::float64>(ap["tx"]->getVal());
   auto const Ty = ym::Ops::castTo<ym::float64>(ap["ty"]->getVal());

   auto * const histo_Ptr = flame::Render::lightFlame(
      NIters, Width_pxls, Height_pxls, flame::Point(Sx, Sy), flame::Point(Tx, Ty));

   if (!histo_Ptr)
   {
      ym::ymLog(ym::VG::Flame, "Failed to render flame!");
      return 1;
   }

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

   using namespace std::string_literals;
   image.write("./pics/"s + ap["output"]->getVal() + ".png"s);

   return 0;
}
