/**
 * @author Forrest Jablonski
 */

#include "Fitter_UnitTest.h"

#include "VariablesMap.h"
#include "Point.h"

// ---------------------------------------------------------------------
// ----------------------------- Test List -----------------------------
// ---------------------------------------------------------------------

/**
 * Initializes the fitter using the parameters in 'vm'
 */
void Fitter_UnitTest::test_Constructor_001()
{
   const char* argv[] = {"program_name",
                         "--width" ,  "200",
                         "--height",  "100",
                         "--xmin"  , "-1.0",
                         "--xmax"  ,  "1.0",
                         "--ymin"  , "-1.0",
                         "--ymax"  ,  "1.0"};

   const VariablesMap vm = VariablesMap(13, argv);

   const Fitter fit = Fitter(vm);

   const Point rawPoint = Point(0.5, 0.5);
   const Point transPoint = fit.transform(rawPoint);

   ADD_FAILING_TEST_IF(
      transPoint.getX() != 125 || // not 150! it is 100 + 25
      transPoint.getY() != 75,    //                 50 + 25
      "Point was not correctly transformed");
}

/**
 * Initializes the fitter by using the coordinates of the window we wish to look
 *  at
 */
void Fitter_UnitTest::test_Constructor_002()
{
   const Fitter fit = Fitter( 200, 100,  // width, height
                             -1.0, 1.0,  // xmin, xmax
                             -1.0, 1.0); // ymin, ymax

   const Point rawPoint = Point(0.5, 0.5);
   const Point transPoint = fit.transform(rawPoint);

   ADD_FAILING_TEST_IF(
      transPoint.getX() != 125 || // not 150! it is 100 + 25
      transPoint.getY() != 75,    //                 50 + 25
      "Point was not correctly transformed");
}

/**
 * Generates 0..1 inclusive, ie. [0..1]
 *
 * Note:
 *  This test is the same as Constructor_002()
 */
void Fitter_UnitTest::test_transform_001()
{
   const Fitter fit = Fitter( 200, 100,  // width, height
                             -1.0, 1.0,  // xmin, xmax
                             -1.0, 1.0); // ymin, ymax

   const Point rawPoint = Point(0.5, 0.5);
   const Point transPoint = fit.transform(rawPoint);

   ADD_FAILING_TEST_IF(
      transPoint.getX() != 125 || // not 150! it is 100 + 25
      transPoint.getY() != 75,    //                 50 + 25
      "Point was not correctly transformed");
}

// ---------------------------------------------------------------------
// -------------------------------- main -------------------------------
// ---------------------------------------------------------------------

/**
 *
 */
int main(int argc, char* argv[])
{
   Fitter_UnitTest cut;

   cut.test_Constructor_001();
   cut.test_Constructor_002();
   cut.test_transform_001();

   cut.printFailingTests();

   return 0;
}
