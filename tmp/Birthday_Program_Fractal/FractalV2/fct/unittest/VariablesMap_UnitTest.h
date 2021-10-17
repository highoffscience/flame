/**
 * @author Forrest Jablonski
 */

#ifndef _FCT_UNITTEST_VARIABLESMAPUNITTEST_H_
#define _FCT_UNITTEST_VARIABLESMAPUNITTEST_H_

// class under test
// ---------------------------
#include "VariablesMap.h" // -
using namespace fct;      // -
// ---------------------------

// place all #includes after CUT so we don't
//  pollute the header file
#include "TestSuiteFramework.h"

/**
 *
 */
class VariablesMap_UnitTest : public TestSuiteFramework
{

public:

   explicit VariablesMap_UnitTest() = default;
   virtual ~VariablesMap_UnitTest() = default;

// ---------------------------------------------------------------------
// ----------------------------- Test List -----------------------------
// ---------------------------------------------------------------------

   void test_Constructor_001();
   void test_Constructor_002();
   void test_Constructor_003();
   void test_set_001();
   void test_exists_001();
   void test_asVector_001();
   void test_asString_001();
   void test_asBool_001();
   void test_asInt_001();
   void test_asUInt_001();
   void test_asLong_001();
   void test_asULong_001();
   void test_asFloat_001();
   void test_asDouble_001();

}; // VariablesMap_UnitTest

#endif // hdr guard
