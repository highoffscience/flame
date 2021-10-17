/**
 * @author Forrest Jablonski
 */

#ifndef _FCT_UNITTEST_FCTLOGUNITTEST_H_
#define _FCT_UNITTEST_FCTLOGUNITTEST_H_

// class under test
// ----------------------
#include "FCTLog.h"  // -
// ----------------------

// place all #includes after CUT so we don't
//  pollute the header file
#include "TestSuiteFramework.h"

/**
 *
 */
class FCTLog_UnitTest : public TestSuiteFramework
{

public:

   explicit FCTLog_UnitTest() = default;
   virtual ~FCTLog_UnitTest() = default;

// ---------------------------------------------------------------------
// ------------------------------ Helpers ------------------------------
// ---------------------------------------------------------------------

protected:

   void openOutfile();
   void closeOutfile();

public:

// ---------------------------------------------------------------------
// ----------------------------- Test List -----------------------------
// ---------------------------------------------------------------------

   void test_FCT_LOG_001();
   void test_FCT_LOG_NOW_001();

}; // FCTLog_UnitTest

#endif // hdr guard
