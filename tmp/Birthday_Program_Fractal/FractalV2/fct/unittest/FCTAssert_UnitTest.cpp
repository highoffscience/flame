/**
 * @author Forrest Jablonski
 */

#include "FCTAssert_UnitTest.h"

//#include "SignalHandler.h"

// ---------------------------------------------------------------------
// ----------------------------- Test List -----------------------------
// ---------------------------------------------------------------------

/**
 * Generates exception (assertion) if cond is false
 * Does nothing if cond is true
 * Prints fmt as the failing message explaining the exception (assertion)
 */
void FCTAssert_UnitTest::test_FCT_ASSERT_001()
{
   const int a = 11;
   const int b = 13;

   try
   {
      FCT_ASSERT(a != b, "A (=%d) and B (=%d) equal", a, b);
   }
   catch (const FCTException& e)
   {
      ADD_FAILING_TEST_IF(
         e.what() != "A (=11) and B (=13) equal",
         "True condition generated assert when none was expected");
   }

   

   ADD_FAILING_TEST_IF(
      gSignalTower != SignalTower_T::Default,
      "True condition generated assert when none was expected");

   gSignalTower = SignalTower_T::Default;

   FCT_ASSERT(a == b, "A (=%d) and B (=%d) do not equal", a, b); // false

   ADD_FAILING_TEST_IF(
      gSignalTower != SignalTower_T::AssertWithSigAbort,
      "False condition did not generate assert when one was expected");
}

/**
 * Prints fmt as the failing message explaining the exception (assertion)
 */
void FCTAssert_UnitTest::test_FCT_ASSERT_002()
{
   //
   // Message with parameters
   //

   const int a = 11;
   const int b = 13;

   const std::string message =
                     "A=11 and B=13";
   FCT_ASSERT(false, "A=%d and B=%d", a, b); // take note of this line number

   areStringsInFile("temp/fctassert.txt",
                    "Assert did not give expected information",
                    {"FCTAssert_UnitTest.cpp#53", message});

   //
   // Message without parameters
   //

   const std::string message2 = "A=15 and B=15";

   FCT_ASSERT(false, message2); // take note of this line number

   areStringsInFile("temp/fctassert.txt",
                    "Assert did not give expected information",
                    {"FCTAssert_UnitTest.cpp#65", message2});
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

   FCTAssert_UnitTest cut;

   cut.test_FCT_ASSERT_001();
   cut.test_FCT_ASSERT_002();

   cut.printFailingTests();

   return 0;
}
