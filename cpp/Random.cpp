/**
 * @author Forrest Jablonski
 */

#include <ctime>

#include "Random.h"

/**
 * Initialzes the structure (constructs internal pseudo-random number generator)
 */
fct::Random::Random()
   : _randGen{(uint)std::time(nullptr)},
     _randMax(_randGen.max())
{ }
