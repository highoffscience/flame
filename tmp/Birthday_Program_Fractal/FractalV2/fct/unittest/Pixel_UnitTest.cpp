/**
 * @author Forrest Jablonski
 */

#include "Pixel_UnitTest.h"

#include <cmath>

// ---------------------------------------------------------------------
// ------------------------------ Helpers ------------------------------
// ---------------------------------------------------------------------

/**
 * Return the applicable color channel value
 *
 * Notes:
 *  Equates potential floating point values within a given tolerance band
 */
bool Pixel_UnitTest::confirmValuesFromGetters(const Pixel& pxl,
                                              const pxl_t r,
                                              const pxl_t g,
                                              const pxl_t b,
                                              const pxl_t a,
                                              const pxl_t tolerance)
{
   return (std::abs(pxl.getR() - r) <= tolerance) &&
          (std::abs(pxl.getG() - g) <= tolerance) &&
          (std::abs(pxl.getB() - b) <= tolerance) &&
          (std::abs(pxl.getA() - a) <= tolerance);
}

// ---------------------------------------------------------------------
// ----------------------------- Test List -----------------------------
// ---------------------------------------------------------------------

/**
 * Initializes all the channels to zero
 */
void Pixel_UnitTest::test_Constructor_001()
{
   const pxl_t r = 0.0;
   const pxl_t g = 0.0;
   const pxl_t b = 0.0;
   const pxl_t a = 0.0;

   const Pixel pxl = Pixel();

   ADD_FAILING_TEST_IF(
      confirmValuesFromGetters(pxl, r, g, b, a) == false,
      "Default constructor did not perform as expected");
}

/**
 * Initializes all the channels to the corresponding parameters
 */
void Pixel_UnitTest::test_Constructor_002()
{
   const pxl_t r = 0.1;
   const pxl_t g = 0.2;
   const pxl_t b = 0.3;
   const pxl_t a = 0.4;

   const Pixel pxl = Pixel(r, g, b, a);

   ADD_FAILING_TEST_IF(
      confirmValuesFromGetters(pxl, r, g, b, a) == false,
      "Value constructor did not perform as expected");
}

/**
 * Return the applicable color channel value
 * Set the applicable color channel to the passed in value
 */
void Pixel_UnitTest::test_Setters_001()
{
   const pxl_t r = 0.1;
   const pxl_t g = 0.2;
   const pxl_t b = 0.3;
   const pxl_t a = 0.4;

   Pixel pxl = Pixel();

   pxl.setR(r);
   pxl.setG(g);
   pxl.setB(b);
   pxl.setA(a);

   ADD_FAILING_TEST_IF(
      confirmValuesFromGetters(pxl, r, g, b, a) == false,
      "Setter functions are not consistent with getter functions");
}

/**
 * Adds this pixel with rhs color channel wise and returns the result
 * Subtracts this pixel with rhs color channel wise and returns the result
 * Multiplies this pixel with rhs color channel wise and returns the result
 * Divides this pixel with rhs color channel wise and returns the result
 * Exponentiates this pixel with rhs color channel wise and returns the result
 */
void Pixel_UnitTest::test_Arithmetic_001()
{
   const Pixel lhs = Pixel(0.1, 0.2, 0.3, 0.4);
   const Pixel rhs = Pixel(0.5, 0.6, 0.7, 0.8);

   const Pixel sum        = lhs + rhs;
   const Pixel difference = lhs - rhs;
   const Pixel product    = lhs * rhs;
   const Pixel quotient   = lhs / rhs;
   const Pixel power      = lhs ^ rhs;

   const bool confirmSum        = confirmValuesFromGetters(
                                    sum,
                                    lhs.getR() + rhs.getR(),
                                    lhs.getG() + rhs.getG(),
                                    lhs.getB() + rhs.getB(),
                                    lhs.getA() + rhs.getA());

   const bool confirmDifference = confirmValuesFromGetters(
                                    difference,
                                    lhs.getR() - rhs.getR(),
                                    lhs.getG() - rhs.getG(),
                                    lhs.getB() - rhs.getB(),
                                    lhs.getA() - rhs.getA());

   const bool confirmProduct    = confirmValuesFromGetters(
                                    product,
                                    lhs.getR() * rhs.getR(),
                                    lhs.getG() * rhs.getG(),
                                    lhs.getB() * rhs.getB(),
                                    lhs.getA() * rhs.getA());

   const bool confirmQuotient   = confirmValuesFromGetters(
                                    quotient,
                                    lhs.getR() / rhs.getR(),
                                    lhs.getG() / rhs.getG(),
                                    lhs.getB() / rhs.getB(),
                                    lhs.getA() / rhs.getA());

   const bool confirmPower      = confirmValuesFromGetters(
                                    power,
                                    std::pow(lhs.getR(), rhs.getR()),
                                    std::pow(lhs.getG(), rhs.getG()),
                                    std::pow(lhs.getB(), rhs.getB()),
                                    std::pow(lhs.getA(), rhs.getA()));

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
void Pixel_UnitTest::test_Arithmetic_002()
{
   const Pixel lhs = Pixel(0.1, 0.2, 0.3, 0.4);
   const Pixel rhs = Pixel(0.5, 0.6, 0.7, 0.8);

   Pixel sum        = lhs;
   Pixel difference = lhs;
   Pixel product    = lhs;
   Pixel quotient   = lhs;
   Pixel power      = lhs;

   sum        += rhs;
   difference -= rhs;
   product    *= rhs;
   quotient   /= rhs;
   power      ^= rhs;

   const bool confirmSum        = confirmValuesFromGetters(
                                    sum,
                                    lhs.getR() + rhs.getR(),
                                    lhs.getG() + rhs.getG(),
                                    lhs.getB() + rhs.getB(),
                                    lhs.getA() + rhs.getA());

   const bool confirmDifference = confirmValuesFromGetters(
                                    difference,
                                    lhs.getR() - rhs.getR(),
                                    lhs.getG() - rhs.getG(),
                                    lhs.getB() - rhs.getB(),
                                    lhs.getA() - rhs.getA());

   const bool confirmProduct    = confirmValuesFromGetters(
                                    product,
                                    lhs.getR() * rhs.getR(),
                                    lhs.getG() * rhs.getG(),
                                    lhs.getB() * rhs.getB(),
                                    lhs.getA() * rhs.getA());

   const bool confirmQuotient   = confirmValuesFromGetters(
                                    quotient,
                                    lhs.getR() / rhs.getR(),
                                    lhs.getG() / rhs.getG(),
                                    lhs.getB() / rhs.getB(),
                                    lhs.getA() / rhs.getA());

   const bool confirmPower      = confirmValuesFromGetters(
                                    power,
                                    std::pow(lhs.getR(), rhs.getR()),
                                    std::pow(lhs.getG(), rhs.getG()),
                                    std::pow(lhs.getB(), rhs.getB()),
                                    std::pow(lhs.getA(), rhs.getA()));

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
 * Adds each color channel with rhs and returns the result
 * Subtracts each color channel with rhs and returns the result
 * Multiplies each color channel with rhs and returns the result
 * Divides each color channel with rhs and returns the result
 * Exponentiates each color channel with rhs and returns the result
 */
void Pixel_UnitTest::test_Arithmetic_003()
{
   const Pixel lhs = Pixel(0.1, 0.2, 0.3, 0.4);
   const pxl_t rhs = 0.5;

   const Pixel sum        = lhs + rhs;
   const Pixel difference = lhs - rhs;
   const Pixel product    = lhs * rhs;
   const Pixel quotient   = lhs / rhs;
   const Pixel power      = lhs ^ rhs;

   const bool confirmSum        = confirmValuesFromGetters(
                                    sum,
                                    lhs.getR() + rhs,
                                    lhs.getG() + rhs,
                                    lhs.getB() + rhs,
                                    lhs.getA() + rhs);

   const bool confirmDifference = confirmValuesFromGetters(
                                    difference,
                                    lhs.getR() - rhs,
                                    lhs.getG() - rhs,
                                    lhs.getB() - rhs,
                                    lhs.getA() - rhs);

   const bool confirmProduct    = confirmValuesFromGetters(
                                    product,
                                    lhs.getR() * rhs,
                                    lhs.getG() * rhs,
                                    lhs.getB() * rhs,
                                    lhs.getA() * rhs);

   const bool confirmQuotient   = confirmValuesFromGetters(
                                    quotient,
                                    lhs.getR() / rhs,
                                    lhs.getG() / rhs,
                                    lhs.getB() / rhs,
                                    lhs.getA() / rhs);

   const bool confirmPower      = confirmValuesFromGetters(
                                    power,
                                    std::pow(lhs.getR(), rhs),
                                    std::pow(lhs.getG(), rhs),
                                    std::pow(lhs.getB(), rhs),
                                    std::pow(lhs.getA(), rhs));

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
void Pixel_UnitTest::test_Arithmetic_004()
{
   const Pixel lhs = Pixel(0.1, 0.2, 0.3, 0.4);
   const pxl_t rhs = 0.5;

   Pixel sum        = lhs;
   Pixel difference = lhs;
   Pixel product    = lhs;
   Pixel quotient   = lhs;
   Pixel power      = lhs;

   sum        += rhs;
   difference -= rhs;
   product    *= rhs;
   quotient   /= rhs;
   power      ^= rhs;

   const bool confirmSum        = confirmValuesFromGetters(
                                    sum,
                                    lhs.getR() + rhs,
                                    lhs.getG() + rhs,
                                    lhs.getB() + rhs,
                                    lhs.getA() + rhs);

   const bool confirmDifference = confirmValuesFromGetters(
                                    difference,
                                    lhs.getR() - rhs,
                                    lhs.getG() - rhs,
                                    lhs.getB() - rhs,
                                    lhs.getA() - rhs);

   const bool confirmProduct    = confirmValuesFromGetters(
                                    product,
                                    lhs.getR() * rhs,
                                    lhs.getG() * rhs,
                                    lhs.getB() * rhs,
                                    lhs.getA() * rhs);

   const bool confirmQuotient   = confirmValuesFromGetters(
                                    quotient,
                                    lhs.getR() / rhs,
                                    lhs.getG() / rhs,
                                    lhs.getB() / rhs,
                                    lhs.getA() / rhs);

   const bool confirmPower      = confirmValuesFromGetters(
                                    power,
                                    std::pow(lhs.getR(), rhs),
                                    std::pow(lhs.getG(), rhs),
                                    std::pow(lhs.getB(), rhs),
                                    std::pow(lhs.getA(), rhs));

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

// ---------------------------------------------------------------------
// -------------------------------- main -------------------------------
// ---------------------------------------------------------------------

/**
 *
 */
int main(int argc, char* argv[])
{
   Pixel_UnitTest cut;

   cut.test_Constructor_001();
   cut.test_Constructor_002();
   cut.test_Setters_001();
   cut.test_Arithmetic_001();
   cut.test_Arithmetic_002();
   cut.test_Arithmetic_003();
   cut.test_Arithmetic_004();

   cut.printFailingTests();

   return 0;
}
