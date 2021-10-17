/**
 * @author Forrest Jablonski
 */

#include "ColorSchemeLibrary_UnitTest.h"

#include "SignalHandler.h"
#include "VariablesMap.h"
#include "ColorScheme.h"
#include "Pixel.h"

#include <typeinfo>

// ---------------------------------------------------------------------
// ----------------------------- Test List -----------------------------
// ---------------------------------------------------------------------

/**
 * Initialize the internal data members according to information in 'vm'
 * The returned pixel is always the same color (independent of 'clr')
 */
void ColorSchemeLibrary_UnitTest::test_CSUniform_001()
{
   ADD_FAILING_TEST_IF(
      true,
      "");
}

/**
 * Initialize the internal data members according to information in 'vm'
 * The returned pixel is always the same color, but the brightness is
 *  linearly dependent on 'clr'
 */
void ColorSchemeLibrary_UnitTest::test_CSShade_001()
{
   ADD_FAILING_TEST_IF(
      true,
      "");
}

/**
 * Initialize the internal data members according to information in 'vm'
 * The returned pixel is linearly dependent on 'clr'
 */
void ColorSchemeLibrary_UnitTest::test_CSSpectrum_001()
{
   ADD_FAILING_TEST_IF(
      true,
      "");
}

/**
 * Returns the requested color scheme
 * Asserts if requested color scheme does not existed
 */
void ColorSchemeLibrary_UnitTest::test_createColorScheme_001()
{
   const char* argv[] = {"program_name", "--colorscheme", "Uniform"};
   VariablesMap vm = VariablesMap(3, argv);

   const ColorScheme* const cs = createColorScheme(vm);

   //std::cout << dynamic_cast<const CSUniform* const>(cs) << std::endl;

   ADD_FAILING_TEST_IF(
      false,
      "Type of color scheme is not as expected");

   gSignalTower = SignalTower_T::Default;

   ADD_FAILING_TEST_IF(
      false,//gSignalTower != SignalTower_T::AssertWithSigAbort,
      "");
}

// ---------------------------------------------------------------------
// -------------------------------- main -------------------------------
// ---------------------------------------------------------------------

/**
 *
 */
int main(int argc, char* argv[])
{
   registerSignalHandler();

   ColorSchemeLibrary_UnitTest cut;

   //cut.test_CSUniform_001();
   //cut.test_CSShade_001();
   //cut.test_CSSpectrum_001();
   cut.test_createColorScheme_001();

   cut.printFailingTests();

   return 0;
}
