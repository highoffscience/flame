/**
 * @author Forrest Jablonski
 */

#pragma once

#include "hoso.h"

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
   inline uint32 getIndex(uint32 const X,
                          uint32 const Y) const;

   uint32 const _Width;
   uint32 const _Height;
};

} // hoso::flame
