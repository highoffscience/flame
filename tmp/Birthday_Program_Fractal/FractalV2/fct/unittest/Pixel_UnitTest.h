/**
 * @author Forrest Jablonski
 */

#ifndef _FCT_UNITTEST_PIXELUNITTEST_H_
#define _FCT_UNITTEST_PIXELUNITTEST_H_

// class under test
// ----------------------
#include "Pixel.h"   // -
using namespace fct; // -
// ----------------------

// place all #includes after CUT so we don't
//  pollute the header file
#include "TestSuiteFramework.h"

/**
 *
 */
class Pixel_UnitTest : public TestSuiteFramework
{

public:

   explicit Pixel_UnitTest() = default;
   virtual ~Pixel_UnitTest() = default;

// ---------------------------------------------------------------------
// ------------------------------ Helpers ------------------------------
// ---------------------------------------------------------------------

   bool confirmValuesFromGetters(const Pixel& pxl,
                                 const pxl_t r,
                                 const pxl_t g,
                                 const pxl_t b,
                                 const pxl_t a,
                                 const pxl_t tolerance = 0.0);

// ---------------------------------------------------------------------
// ----------------------------- Test List -----------------------------
// ---------------------------------------------------------------------

   void test_Constructor_001();
   void test_Constructor_002();
   void test_Setters_001();
   void test_Arithmetic_001();
   void test_Arithmetic_002();
   void test_Arithmetic_003();
   void test_Arithmetic_004();

}; // Pixel_UnitTest

#endif // hdr guard
