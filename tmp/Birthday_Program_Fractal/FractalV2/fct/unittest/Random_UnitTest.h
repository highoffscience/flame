/**
 * @author Forrest Jablonski
 */

#ifndef _FCT_UNITTEST_RANDOMUNITTEST_H_
#define _FCT_UNITTEST_RANDOMUNITTEST_H_

// class under test
// ----------------------
#include "Random.h"  // -
using namespace fct; // -
// ----------------------

// place all #includes after CUT so we don't
//  pollute the header file
#include "TestSuiteFramework.h"

/**
 *
 */
class Random_UnitTest : public TestSuiteFramework
{

public:

   explicit Random_UnitTest() = default;
   virtual ~Random_UnitTest() = default;

// ---------------------------------------------------------------------
// ----------------------------- Test List -----------------------------
// ---------------------------------------------------------------------

   void test_Constructor_001();
   void test_genUniformReal_001();

}; // Random_UnitTest

#endif // hdr guard
