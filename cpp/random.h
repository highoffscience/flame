/**
 * @author Forrest Jablonski
 */

#pragma once

#include "hoso.h"

namespace hoso::flame
{

/**
 * PRNG
 */
class Random
{
public:
   explicit Random(void);

   uint32 gen(void);

   void jump(uint32 const NJumps);

private:
   uint64 _s0;
   uint64 _s1;
   uint64 _s2;
   uint64 _s3;
};

} // hoso::flame
