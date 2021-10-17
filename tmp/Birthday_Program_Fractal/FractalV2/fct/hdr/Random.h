/**
 * @author Forrest Jablonski
 */

#pragma once

#include <boost/random.hpp>

#include "Standard.h"

namespace fct
{

/**
 * A pseudo-random number generator
 */
class Random
{

private:

   boost::random::mt19937 _randGen;
   const double _randMax; // doubles are faster than floats (discovered during unittesting)

public:

   explicit Random();

   inline double genUniformReal();

}; // Random

/**
 * Generates 0..1 inclusive, ie. [0..1]
 */
inline double Random::genUniformReal()
{
   return _randGen() / _randMax;
}

} // fct
