/**
 * @author Forrest Jablonski
 */

#ifndef _FCT_UNITTEST_FCTASSERTUNITTEST_H_
#define _FCT_UNITTEST_FCTASSERTUNITTEST_H_

// class under test (CUT)
// ------------------------
#include "FCTAssert.h" // -
using namespace fct;   // -
// ------------------------

// place all #includes after CUT so we don't
//  pollute the header file
#include "TestSuiteFramework.h"

/**
 *
 */
class FCTAssert_UnitTest : public TestSuiteFramework
{

public:

   explicit FCTAssert_UnitTest() = default;
   virtual ~FCTAssert_UnitTest() = default;

// ---------------------------------------------------------------------
// ----------------------------- Test List -----------------------------
// ---------------------------------------------------------------------

   void test_FCT_ASSERT_001();
   void test_FCT_ASSERT_002();

}; // FCTAssert_UnitTest

#endif // hdr guard
