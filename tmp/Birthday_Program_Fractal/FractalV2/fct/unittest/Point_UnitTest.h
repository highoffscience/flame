/**
 * @author Forrest Jablonski
 */

#ifndef _FCT_UNITTEST_POINTUNITTEST_H_
#define _FCT_UNITTEST_POINTUNITTEST_H_

// class under test
// ----------------------
#include "Point.h"   // -
using namespace fct; // -
// ----------------------

// place all #includes after CUT so we don't
//  pollute the header file
#include "TestSuiteFramework.h"

#include <complex>

/**
 *
 */
class Point_UnitTest : public TestSuiteFramework
{

public:

   explicit Point_UnitTest() = default;
   virtual ~Point_UnitTest() = default;

// ---------------------------------------------------------------------
// ------------------------------ Helpers ------------------------------
// ---------------------------------------------------------------------

   bool confirmValuesFromGetters(const Point& pnt,
                                 const pnt_t  x,
                                 const pnt_t  y,
                                 const pnt_t  tolerance = 0.0);

   bool equatePntTWithTolerance(const pnt_t lhs,
                                const pnt_t rhs,
                                const pnt_t tolerance = 0.0);

   bool equatePntAndStdComplexWithTolerance(const Point&               lhs,
                                            const std::complex<pnt_t>& rhs,
                                            const pnt_t                tolerance = 0.0);

// ---------------------------------------------------------------------
// ----------------------------- Test List -----------------------------
// ---------------------------------------------------------------------

   void test_Constructor_001();
   void test_Constructor_002();
   void test_Setters_001(); // getters also tested via helper method
   void test_Neg_001();
   void test_Arithmetic_001();
   void test_Arithmetic_002();
   void test_Arithmetic_003();
   void test_Arithmetic_004();
   void test_Rev_001();
   void test_cMod_001();
   void test_cMod2_001();
   void test_cArg_001();
   void test_cPls_001();
   void test_cMns_001();
   void test_cTms_001();
   void test_cDvd_001();
   void test_cConj_001();
   void test_cInv_001();

}; // Point_UnitTest

#endif // hdr guard
