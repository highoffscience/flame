/**
 * @author Forrest Jablonski
 */

#ifndef _FCT_UNITTEST_FITTERUNITTEST_H_
#define _FCT_UNITTEST_FITTERUNITTEST_H_

// class under test
// ----------------------
#include "Fitter.h"  // -
using namespace fct; // -
// ----------------------

// place all #includes after CUT so we don't
//  pollute the header file
#include "TestSuiteFramework.h"

/**
 *
 */
class Fitter_UnitTest : public TestSuiteFramework
{

public:

   explicit Fitter_UnitTest() = default;
   virtual ~Fitter_UnitTest() = default;

// ---------------------------------------------------------------------
// ----------------------------- Test List -----------------------------
// ---------------------------------------------------------------------

   void test_Constructor_001();
   void test_Constructor_002();
   void test_transform_001();

}; // Fitter_UnitTest

#endif // hdr guard
