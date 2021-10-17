/**
 * @author Forrest Jablonski
 */

#include "Random_UnitTest.h"

// ---------------------------------------------------------------------
// ----------------------------- Test List -----------------------------
// ---------------------------------------------------------------------

/**
 * Initialzes the structure (constructs internal pseudo-random number generator)
 */
void Random_UnitTest::test_Constructor_001()
{
   Random rand = Random(); // this is a compile-time test ;)
}

/**
 * Generates 0..1 inclusive, ie. [0..1]
 */
void Random_UnitTest::test_genUniformReal_001()
{
   Random rand = Random();

   const uint nSamples = 1000000;
   double sum = 0.0;

   for (uint i = 0; i < nSamples; ++i)
   {
      sum += rand.genUniformReal();
   }

   const double ave = sum / nSamples;

   ADD_FAILING_TEST_IF(
      ave < (0.5 - 0.01) ||
      ave > (0.5 + 0.01),
      "Random did not generated expected range of uniform real numbers");
}

// ---------------------------------------------------------------------
// -------------------------------- main -------------------------------
// ---------------------------------------------------------------------

/**
 *
 */
int main(int argc, char* argv[])
{
   Random_UnitTest cut;

   cut.test_Constructor_001();
   cut.test_genUniformReal_001();

   cut.printFailingTests();

   return 0;
}
