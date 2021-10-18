/**
 * @author Forrest Jablonski
 */

#pragma once

#include "Standard.h"

#include <chrono>
#include <random>
#include <utility>

namespace ym
{

/**
 * A pseudo-random number generator.
 *
 * <https://en.cppreference.com/w/cpp/numeric/random>
 */
template <typename                  ResultType_T,
          template <typename> class Distribution_T>
class Random
{
public:
   template <typename... Params_T>
   explicit Random(Params_T &&... params);

   inline ResultType_T get(void);

   inline void seed(uint64 const Seed);

private:
   std::mt19937_64              _gen;
   Distribution_T<ResultType_T> _dist;
};

/**
 * Initializes the structure (constructs internal pseudo-random number generator).
 * 
 * Seeds the RNG with the current system time.
 */
template <typename                  ResultType_T,
          template <typename> class Distribution_T>
template <typename...               Params_T>
Random<ResultType_T, Distribution_T>::Random(Params_T &&... params)
   : _gen  {std::chrono::system_clock::now().time_since_epoch().count()},
     _dist {std::forward<Params_T>(params)...                          }
{
}

/**
 * Pools and returns the next number in the RNG.
 *
 * The range of the distribution is initialized in the constructor.
 */
template <typename                  ResultType_T,
          template <typename> class Distribution_T>
inline ResultType_T Random<ResultType_T, Distribution_T>::get(void)
{
   return _dist(_gen);
}

/**
 * Seeds the RNG.
 */
template <typename                  ResultType_T,
          template <typename> class Distribution_T>
inline void Random<ResultType_T, Distribution_T>::seed(uint64 const Seed)
{
   _gen.seed(Seed);
}

} // ym
