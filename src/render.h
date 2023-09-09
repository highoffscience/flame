/**
 * @file    render.h
 * @version 1.0.0
 * @author  Forrest Jablonski
 */

#pragma once

#include "ymdefs.h"

#include "pixel.h"

namespace flame
{

/** Render
 *
 * @brief Renders the fractal flame.
 */
class Render
{
public:
   YM_NO_DEFAULT(Render)

   static Pixel * lightFlame(ym::uint64 const NIters,
                             ym::uint32 const Width_pxls,
                             ym::uint32 const Height_pxls);

   static void destroyHisto(Pixel const * const Histo_Ptr,
                            ym::uint32    const Width_pxls,
                            ym::uint32    const Height_pxls);

private:
   static void postProcess(Pixel *    const histo_Ptr,
                           ym::uint32 const HistoSize_pxls);
};

} // flame
