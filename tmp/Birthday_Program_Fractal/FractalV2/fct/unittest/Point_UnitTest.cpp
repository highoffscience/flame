/**
 * @author Forrest Jablonski
 */

#include "Point_UnitTest.h"

#include <cmath>

// ---------------------------------------------------------------------
// ------------------------------ Helpers ------------------------------
// ---------------------------------------------------------------------

/**
 * Return the applicable coordinate
 *
 * Notes:
 *  Equates x and y within the given tolerance
 */
bool Point_UnitTest::confirmValuesFromGetters(const Point& pnt,
                                              const pnt_t  x,
                                              const pnt_t  y,
                                              const pnt_t  tolerance)
{
   return (std::abs(pnt.getX() - x) <= tolerance) &&
          (std::abs(pnt.getY() - y) <= tolerance);
}

/**
 * ---
 *
 * Notes:
 *  Equates lhs and rhs within the given tolerance
 */
bool Point_UnitTest::equatePntTWithTolerance(const pnt_t lhs,
                                             const pnt_t rhs,
                                             const pnt_t tolerance)
{
   return std::abs(lhs - rhs) <= tolerance;
}

bool Point_UnitTest::equatePntAndStdComplexWithTolerance(const Point&               lhs,
                                                         const std::complex<pnt_t>& rhs,
                                                         const pnt_t                tolerance)
{
   return equatePntTWithTolerance(lhs.getX(), std::real(rhs), tolerance) &&
          equatePntTWithTolerance(lhs.getY(), std::imag(rhs), tolerance);
}

// ---------------------------------------------------------------------
// ----------------------------- Test List -----------------------------
// ---------------------------------------------------------------------

/**
 * Initializes the coordinates to zero
 */
void Point_UnitTest::test_Constructor_001()
{
   const pnt_t x = 0.0;
   const pnt_t y = 0.0;

   const Point pnt = Point();

   ADD_FAILING_TEST_IF(
      confirmValuesFromGetters(pnt, x, y) == false,
      "Default constructor did not perform as expected");
}

/**
 * Initializes the coordinates to the corresponding parameters
 */
void Point_UnitTest::test_Constructor_002()
{
   const pnt_t x = 1.1;
   const pnt_t y = 2.2;

   const Point pnt = Point(x, y);

   ADD_FAILING_TEST_IF(
      confirmValuesFromGetters(pnt, x, y) == false,
      "Value constructor did not perform as expected");
}

/**
 * Return the applicable coordinate
 * Set the applicable coordinate to the passed in value
 */
void Point_UnitTest::test_Setters_001()
{
   const pnt_t x = 1.1;
   const pnt_t y = 2.2;

   Point pnt = Point();

   pnt.setX(x);
   pnt.setY(y);

   ADD_FAILING_TEST_IF(
      confirmValuesFromGetters(pnt, x, y) == false,
      "Setter functions are not consistent with getter functions");
}

/**
 * Negates this point coordinate wise and returns the result
 */
void Point_UnitTest::test_Neg_001()
{
   const Point pnt = Point(0.1, 0.2);

   const Point negPnt = -pnt;

   const bool confirmNeg = confirmValuesFromGetters(
                              negPnt,
                              -pnt.getX(),
                              -pnt.getY());

   ADD_FAILING_TEST_IF(
      confirmNeg == false,
      "Exponentiation did not yield expected results");
}

/**
 * Adds this point with rhs coordinate wise and returns the result
 * Subtracts this point with rhs coordinate wise and returns the result
 * Multiplies this point with rhs coordinate wise and returns the result
 * Divides this point with rhs coordinate wise and returns the result
 * Exponentiates this point with rhs coordinate wise and returns the result
 */
void Point_UnitTest::test_Arithmetic_001()
{
   const Point lhs = Point(0.1, 0.2);
   const Point rhs = Point(0.4, 0.6);

   const Point sum        = lhs + rhs;
   const Point difference = lhs - rhs;
   const Point product    = lhs * rhs;
   const Point quotient   = lhs / rhs;
   const Point power      = lhs ^ rhs;

   const bool confirmSum        = confirmValuesFromGetters(
                                    sum,
                                    lhs.getX() + rhs.getX(),
                                    lhs.getY() + rhs.getY());

   const bool confirmDifference = confirmValuesFromGetters(
                                    difference,
                                    lhs.getX() - rhs.getX(),
                                    lhs.getY() - rhs.getY());

   const bool confirmProduct    = confirmValuesFromGetters(
                                    product,
                                    lhs.getX() * rhs.getX(),
                                    lhs.getY() * rhs.getY());

   const bool confirmQuotient   = confirmValuesFromGetters(
                                    quotient,
                                    lhs.getX() / rhs.getX(),
                                    lhs.getY() / rhs.getY());

   const bool confirmPower      = confirmValuesFromGetters(
                                    power,
                                    std::pow(lhs.getX(), rhs.getX()),
                                    std::pow(lhs.getY(), rhs.getY()));

   ADD_FAILING_TEST_IF(
      confirmSum == false,
      "Addition did not yield expected results");

   ADD_FAILING_TEST_IF(
      confirmDifference == false,
      "Subtraction did not yield expected results");

   ADD_FAILING_TEST_IF(
      confirmProduct == false,
      "Multiplication did not yield expected results");

   ADD_FAILING_TEST_IF(
      confirmQuotient == false,
      "Division did not yield expected results");

   ADD_FAILING_TEST_IF(
      confirmPower == false,
      "Exponentiation did not yield expected results");
}

/**
 * Self assigns the result of the given operation
 */
void Point_UnitTest::test_Arithmetic_002()
{
   const Point lhs = Point(0.1, 0.2);
   const Point rhs = Point(0.4, 0.6);

   Point sum        = lhs;
   Point difference = lhs;
   Point product    = lhs;
   Point quotient   = lhs;
   Point power      = lhs;

   sum        += rhs;
   difference -= rhs;
   product    *= rhs;
   quotient   /= rhs;
   power      ^= rhs;

   const bool confirmSum        = confirmValuesFromGetters(
                                    sum,
                                    lhs.getX() + rhs.getX(),
                                    lhs.getY() + rhs.getY());

   const bool confirmDifference = confirmValuesFromGetters(
                                    difference,
                                    lhs.getX() - rhs.getX(),
                                    lhs.getY() - rhs.getY());

   const bool confirmProduct    = confirmValuesFromGetters(
                                    product,
                                    lhs.getX() * rhs.getX(),
                                    lhs.getY() * rhs.getY());

   const bool confirmQuotient   = confirmValuesFromGetters(
                                    quotient,
                                    lhs.getX() / rhs.getX(),
                                    lhs.getY() / rhs.getY());

   const bool confirmPower      = confirmValuesFromGetters(
                                    power,
                                    std::pow(lhs.getX(), rhs.getX()),
                                    std::pow(lhs.getY(), rhs.getY()));

   ADD_FAILING_TEST_IF(
      confirmSum == false,
      "Addition did not yield expected results");

   ADD_FAILING_TEST_IF(
      confirmDifference == false,
      "Subtraction did not yield expected results");

   ADD_FAILING_TEST_IF(
      confirmProduct == false,
      "Multiplication did not yield expected results");

   ADD_FAILING_TEST_IF(
      confirmQuotient == false,
      "Division did not yield expected results");

   ADD_FAILING_TEST_IF(
      confirmPower == false,
      "Exponentiation did not yield expected results");
}

/**
 * Adds each coordinate of this point with rhs
 * Subtracts each coordinate of this point with rhs
 * Multiplies each coordinate of this point with rhs
 * Divides each coordinate of this point with rhs
 * Exponentiates each coordinate of this point with rhs
 */
void Point_UnitTest::test_Arithmetic_003()
{
   const Point lhs = Point(0.1, 0.2);
   const pnt_t rhs = 0.5;

   const Point sum        = lhs + rhs;
   const Point difference = lhs - rhs;
   const Point product    = lhs * rhs;
   const Point quotient   = lhs / rhs;
   const Point power      = lhs ^ rhs;

   const bool confirmSum        = confirmValuesFromGetters(
                                    sum,
                                    lhs.getX() + rhs,
                                    lhs.getY() + rhs);

   const bool confirmDifference = confirmValuesFromGetters(
                                    difference,
                                    lhs.getX() - rhs,
                                    lhs.getY() - rhs);

   const bool confirmProduct    = confirmValuesFromGetters(
                                    product,
                                    lhs.getX() * rhs,
                                    lhs.getY() * rhs);

   const bool confirmQuotient   = confirmValuesFromGetters(
                                    quotient,
                                    lhs.getX() / rhs,
                                    lhs.getY() / rhs);

   const bool confirmPower      = confirmValuesFromGetters(
                                    power,
                                    std::pow(lhs.getX(), rhs),
                                    std::pow(lhs.getY(), rhs));

   ADD_FAILING_TEST_IF(
      confirmSum == false,
      "Addition did not yield expected results");

   ADD_FAILING_TEST_IF(
      confirmDifference == false,
      "Subtraction did not yield expected results");

   ADD_FAILING_TEST_IF(
      confirmProduct == false,
      "Multiplication did not yield expected results");

   ADD_FAILING_TEST_IF(
      confirmQuotient == false,
      "Division did not yield expected results");

   ADD_FAILING_TEST_IF(
      confirmPower == false,
      "Exponentiation did not yield expected results");
}

/**
 * Self assigns the result of the given operation
 */
void Point_UnitTest::test_Arithmetic_004()
{
   const Point lhs = Point(0.1, 0.2);
   const pnt_t rhs = 0.5;

   Point sum        = lhs;
   Point difference = lhs;
   Point product    = lhs;
   Point quotient   = lhs;
   Point power      = lhs;

   sum        += rhs;
   difference -= rhs;
   product    *= rhs;
   quotient   /= rhs;
   power      ^= rhs;

   const bool confirmSum        = confirmValuesFromGetters(
                                    sum,
                                    lhs.getX() + rhs,
                                    lhs.getY() + rhs);

   const bool confirmDifference = confirmValuesFromGetters(
                                    difference,
                                    lhs.getX() - rhs,
                                    lhs.getY() - rhs);

   const bool confirmProduct    = confirmValuesFromGetters(
                                    product,
                                    lhs.getX() * rhs,
                                    lhs.getY() * rhs);

   const bool confirmQuotient   = confirmValuesFromGetters(
                                    quotient,
                                    lhs.getX() / rhs,
                                    lhs.getY() / rhs);

   const bool confirmPower      = confirmValuesFromGetters(
                                    power,
                                    std::pow(lhs.getX(), rhs),
                                    std::pow(lhs.getY(), rhs));

   ADD_FAILING_TEST_IF(
      confirmSum == false,
      "Addition did not yield expected results");

   ADD_FAILING_TEST_IF(
      confirmDifference == false,
      "Subtraction did not yield expected results");

   ADD_FAILING_TEST_IF(
      confirmProduct == false,
      "Multiplication did not yield expected results");

   ADD_FAILING_TEST_IF(
      confirmQuotient == false,
      "Division did not yield expected results");

   ADD_FAILING_TEST_IF(
      confirmPower == false,
      "Exponentiation did not yield expected results");
}

/**
 * Reverses the coordinates and returns the result and returns the result
 */
void Point_UnitTest::test_Rev_001()
{
   const Point pnt = Point(1.49, 2.32);

   const Point rev = pnt.rev();

   const bool confirmRev = confirmValuesFromGetters(
                              rev,
                              pnt.getY(),
                              pnt.getX());

   ADD_FAILING_TEST_IF(
      confirmRev == false,
      "Complex reversal did not yield expected results");
}

/**
 * Computes the complex modulus and returns the result
 */
void Point_UnitTest::test_cMod_001()
{
   const Point pnt = Point(1.49, 2.32);

   const std::complex<pnt_t> cPnt = std::complex<pnt_t>(pnt.getX(), pnt.getY());

   ADD_FAILING_TEST_IF(
      equatePntTWithTolerance(pnt.cMod(), std::abs(cPnt), 0.000001) == false,
      "Complex modulus did not yield expected results");
}

/**
 * Computes the square of the complex modulus and returns the result
 */
void Point_UnitTest::test_cMod2_001()
{
   const Point pnt = Point(1.49, 2.32);

   const std::complex<pnt_t> cPnt = std::complex<pnt_t>(pnt.getX(), pnt.getY());

   ADD_FAILING_TEST_IF(
      equatePntTWithTolerance(pnt.cMod2(), std::norm(cPnt), 0.000001) == false,
      "Square of the complex modulus did not yield expected results");
}

/**
 * Computes the complex argument and returns the result
 */
void Point_UnitTest::test_cArg_001()
{
   const Point pnt = Point(1.49, 2.32);

   const std::complex<pnt_t> cPnt = std::complex<pnt_t>(pnt.getX(), pnt.getY());

   ADD_FAILING_TEST_IF(
      equatePntTWithTolerance(pnt.cArg(), std::arg(cPnt), 0.000001) == false,
      "Complex argument did not yield expected results");
}

/**
 * Performs complex addition with this point and rhs and returns the result
 */
void Point_UnitTest::test_cPls_001()
{
   const Point lhs = Point(1.49, 2.32);
   const Point rhs = Point(0.88, 3.01);

   const std::complex<pnt_t> cLhs = std::complex<pnt_t>(lhs.getX(), lhs.getY());
   const std::complex<pnt_t> cRhs = std::complex<pnt_t>(rhs.getX(), rhs.getY());

   ADD_FAILING_TEST_IF(
      equatePntAndStdComplexWithTolerance(lhs.cPls(rhs), cLhs + cRhs, 0.000001) == false,
      "Complex addition did not yield expected results");
}

/**
 * Performs complex subtraction with this point and rhs and returns the result
 */
void Point_UnitTest::test_cMns_001()
{
   const Point lhs = Point(1.49, 2.32);
   const Point rhs = Point(0.88, 3.01);

   const std::complex<pnt_t> cLhs = std::complex<pnt_t>(lhs.getX(), lhs.getY());
   const std::complex<pnt_t> cRhs = std::complex<pnt_t>(rhs.getX(), rhs.getY());

   ADD_FAILING_TEST_IF(
      equatePntAndStdComplexWithTolerance(lhs.cMns(rhs), cLhs - cRhs, 0.000001) == false,
      "Complex subtraction did not yield expected results");
}

/**
 * Performs complex multiplication with this point and rhs and returns the result
 */
void Point_UnitTest::test_cTms_001()
{
   const Point lhs = Point(1.49, 2.32);
   const Point rhs = Point(0.88, 3.01);

   const std::complex<pnt_t> cLhs = std::complex<pnt_t>(lhs.getX(), lhs.getY());
   const std::complex<pnt_t> cRhs = std::complex<pnt_t>(rhs.getX(), rhs.getY());

   ADD_FAILING_TEST_IF(
      equatePntAndStdComplexWithTolerance(lhs.cTms(rhs), cLhs * cRhs, 0.000001) == false,
      "Complex multiplication did not yield expected results");
}

/**
 * Performs complex division with this point and rhs and returns the result
 */
void Point_UnitTest::test_cDvd_001()
{
   const Point lhs = Point(1.49, 2.32);
   const Point rhs = Point(0.88, 3.01);

   const std::complex<pnt_t> cLhs = std::complex<pnt_t>(lhs.getX(), lhs.getY());
   const std::complex<pnt_t> cRhs = std::complex<pnt_t>(rhs.getX(), rhs.getY());

   ADD_FAILING_TEST_IF(
      equatePntAndStdComplexWithTolerance(lhs.cDvd(rhs), cLhs / cRhs, 0.000001) == false,
      "Complex division did not yield expected results");
}

/**
 * Performs the complex conjugate and returns the result
 */
void Point_UnitTest::test_cConj_001()
{
   const Point pnt = Point(1.49, 2.32);

   const Point cconj = pnt.cConj();

   const bool confirmConj = confirmValuesFromGetters(
                                cconj,
                                pnt.getX(),
                               -pnt.getY());

   ADD_FAILING_TEST_IF(
      confirmConj == false,
      "Complex conjugation did not yield expected results");
}

/**
 * Performs the complex inverse and returns the result
 */
void Point_UnitTest::test_cInv_001()
{
   const pnt_t x = 1.49;
   const pnt_t y = 2.32;

   const Point pnt = Point(x, y);

   const Point cinv = pnt.cInv();

   const bool confirmInv = confirmValuesFromGetters(
                               cinv,
                               x / (x*x + y*y),
                              -y / (x*x + y*y));

   ADD_FAILING_TEST_IF(
      confirmInv == false,
      "Complex inverse did not yield expected results");
}

// ---------------------------------------------------------------------
// -------------------------------- main -------------------------------
// ---------------------------------------------------------------------

/**
 *
 */
int main(int argc, char* argv[])
{
   Point_UnitTest cut;

   cut.test_Constructor_001();
   cut.test_Constructor_002();
   cut.test_Setters_001();
   cut.test_Neg_001();
   cut.test_Arithmetic_001();
   cut.test_Arithmetic_002();
   cut.test_Arithmetic_003();
   cut.test_Arithmetic_004();
   cut.test_Rev_001();
   cut.test_cMod_001();
   cut.test_cMod2_001();
   cut.test_cArg_001();
   cut.test_cPls_001();
   cut.test_cMns_001();
   cut.test_cTms_001();
   cut.test_cDvd_001();
   cut.test_cConj_001();
   cut.test_cInv_001();

   cut.printFailingTests();

   return 0;
}
