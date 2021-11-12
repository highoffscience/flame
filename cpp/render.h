/**
 * @author Forrest Jablonski
 */

#pragma once

#include "colorscheme.h"
#include "hoso.h"
#include "strangeattractor.h"
#include "varblend.h"

#include <thread>
#include <vector>

namespace hoso::flame
{

/**
 *
 */
class Render
{
public:
   Render(uint32 const Width,
          uint32 const Height);

   void populate(class Pixel * const histo_Ptr) const;

private:
   std::vector<std::thread> _executors; // coming for their baby executes I'm sure

   ColorScheme      const _Cs;
   StrangeAttractor const _Sa;
   VarBlend         const _Vb;

   uint32 const _Width;
   uint32 const _Height;
};

} // hoso::flame
