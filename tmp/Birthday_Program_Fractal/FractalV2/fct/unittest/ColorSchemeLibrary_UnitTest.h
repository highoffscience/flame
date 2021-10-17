/**
 * @author Forrest Jablonski
 */

#ifndef _FCT_UNITTEST_COLORSCHEMELIBRARYUNITTEST_H_
#define _FCT_UNITTEST_COLORSCHEMELIBRARYUNITTEST_H_

// class under test
// ---------------------------------
#include "ColorSchemeLibrary.h" // -
using namespace fct;            // -
// ---------------------------------

// place all #includes after CUT so we don't
//  pollute the header file
#include "TestSuiteFramework.h"

/**
 *
 */
class ColorSchemeLibrary_UnitTest : public TestSuiteFramework
{

public:

   explicit ColorSchemeLibrary_UnitTest() = default;
   virtual ~ColorSchemeLibrary_UnitTest() = default;

// ---------------------------------------------------------------------
// ----------------------------- Test List -----------------------------
// ---------------------------------------------------------------------

   void test_CSUniform_001();
   void test_CSShade_001();
   void test_CSSpectrum_001();
   void test_createColorScheme_001();

}; // ColorSchemeLibrary_UnitTest

#endif // hdr guard
