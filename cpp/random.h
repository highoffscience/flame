/**
 * @author Forrest Jablonski
 */

#pragma once

#include "hoso.h"

namespace hoso
{

/**
 * PRNG
 */
class Random
{
public:
   explicit Random(void);

   typedef float32 dim_t;

   template <typename float_t> // going swimming apparently
   float_t gen(void);

   void jump(uint32 const NJumps);

private:
   uint64 _s0;
   uint64 _s1;
   uint64 _s2;
   uint64 _s3;


};

// specializations must be declared outside of class scope
template <> float32 Random::gen<float32>(void);
template <> float64 Random::gen<float64>(void);

} // hoso
