/**
 * @author Forrest Jablonski
 */

#pragma once

#include "colorscheme.h"
#include "hoso.h"
#include "strangeattractor.h"
#include "varblend.h"

namespace hoso::flame
{

/**
 *
 */
class Render
{
public:
   Render(uint64 const NIters,
          uint32 const Width,
          uint32 const Height);

   class Pixel * flame(void);

private:
   void populate(class Pixel * const histo_Ptr,
                       uint32  const JumpNumber) const;

   void postProcess(class Pixel * const histo_Ptr,
                          uint32  const HistoSize) const;

   ColorScheme      const _Cs;
   StrangeAttractor const _Sa;
   VarBlend         const _Vb;

   uint64 const _NIters;
   uint32 const _Width;
   uint32 const _Height;
};

} // hoso::flame
