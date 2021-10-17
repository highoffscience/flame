/**
 * @author Forrest Jablonski
 */

#include "VariablesMap_UnitTest.h"

#include "SignalHandler.h"

// ---------------------------------------------------------------------
// ----------------------------- Test List -----------------------------
// ---------------------------------------------------------------------

/**
 * Asserts if command line arguments are incorrectly formatted (<key> <value>+)
 */
void VariablesMap_UnitTest::test_Constructor_001()
{
   const char* argv[] = {"program_name", "invalid_key"};

   gSignalTower = SignalTower_T::Default;

   const VariablesMap vm = VariablesMap(1, argv);

   ADD_FAILING_TEST_IF(
      gSignalTower != SignalTower_T::AssertWithSigAbort,
      "No assert generated when one was expected");

   gSignalTower = SignalTower_T::Default;

   const VariablesMap vm2 = VariablesMap(2, argv);

   ADD_FAILING_TEST_IF(
      gSignalTower != SignalTower_T::AssertWithSigAbort,
      "No assert generated when one was expected");
}

/**
 * Asserts if key has no value
 */
void VariablesMap_UnitTest::test_Constructor_002()
{
   const char* argv[] = {"program_name", "--key_with_no_params"};

   gSignalTower = SignalTower_T::Default;

   const VariablesMap vm = VariablesMap(2, argv);

   ADD_FAILING_TEST_IF(
      gSignalTower != SignalTower_T::AssertWithSigAbort,
      "No assert generated when one was expected");

   const char* argv2[] = {"program_name",
                          "--key", "1",
                          "--key_with_no_params"};

   gSignalTower = SignalTower_T::Default;

   const VariablesMap vm2 = VariablesMap(4, argv2);

   ADD_FAILING_TEST_IF(
      gSignalTower != SignalTower_T::AssertWithSigAbort,
      "No assert generated when one was expected");
}

/**
 * Adds the key and associated values into the internal dictionary
 */
void VariablesMap_UnitTest::test_Constructor_003()
{
   const char* argv[] = {"program_name",
                         "--key1", "1",
                         "--key2", "2", "3", "4"};

   const VariablesMap vm = VariablesMap(7, argv);

   ADD_FAILING_TEST_IF(
      vm.asInt("key1") != 1,
      "Keys did not store expected values");

   ADD_FAILING_TEST_IF(
      vm.asInt("key2", 0) != 2 ||
      vm.asInt("key2", 1) != 3 ||
      vm.asInt("key2", 2) != 4,
      "Keys did not store expected values");
}

/**
 * Sets value(s) for a key
 */
void VariablesMap_UnitTest::test_set_001()
{
   const char* argv[] = {"program_name"};

   VariablesMap vm = VariablesMap(1, argv);

   vm.set("key", {"1"});

   ADD_FAILING_TEST_IF(
      vm.asInt("key") != 1,
      "Key did not store expected value");

   vm.set("key", {"2", "3"});

   ADD_FAILING_TEST_IF(
      vm.asInt("key")    != 2 ||
      vm.asInt("key", 1) != 3,
      "Key did not store expected values");
}

/**
 * Returns true if the given key exists, false otherwise
 */
void VariablesMap_UnitTest::test_exists_001()
{
   const char* argv[] = {"program_name",
                         "--key", "1"};

   VariablesMap vm = VariablesMap(3, argv);

   vm.set("key", {"1"});

   ADD_FAILING_TEST_IF(
      vm.exists("key") == false,
      "Key should exist");

   ADD_FAILING_TEST_IF(
      vm.exists("no_key") == true,
      "Key should not exist");
}

/**
 * Return all the values (implemented as a vector) associated with the given key
 */
void VariablesMap_UnitTest::test_asVector_001()
{
   const char* argv[] = {"program_name",
                         "--key", "0", "1", "2"};

   VariablesMap vm = VariablesMap(5, argv);

   ADD_FAILING_TEST_IF(
      vm.asVector("key")[0] != "0" ||
      vm.asVector("key")[1] != "1" ||
      vm.asVector("key")[2] != "2",
      "Values of key not correctly stored as vector");
}

/**
 * Return the requested value associated with the given key as a string
 */
void VariablesMap_UnitTest::test_asString_001()
{
   const char* argv[] = {"program_name",
                         "--key", "hello"};

   VariablesMap vm = VariablesMap(3, argv);

   ADD_FAILING_TEST_IF(
      vm.asString("key") != "hello",
      "Value of key not correctly stored as a string");
}

/**
 * Return the requested value associated with the given key as a boolean
 */
void VariablesMap_UnitTest::test_asBool_001()
{
   const char* argv[] = {"program_name",
                         "--key_true",  "1",
                         "--key_false", "0"};

   VariablesMap vm = VariablesMap(5, argv);

   ADD_FAILING_TEST_IF(
      vm.asBool("key_true" ) != true ||
      vm.asBool("key_false") != false,
      "Value of key not correctly stored as a bool");
}

/**
 * Return the requested value associated with the given key as an integer
 */
void VariablesMap_UnitTest::test_asInt_001()
{
   const char* argv[] = {"program_name",
                         "--key",  "1"};

   VariablesMap vm = VariablesMap(3, argv);

   ADD_FAILING_TEST_IF(
      vm.asInt("key") != 1,
      "Value of key not correctly stored as an int");
}

/**
 * Return the requested value associated with the given key as an unsigned integer
 */
void VariablesMap_UnitTest::test_asUInt_001()
{
   const char* argv[] = {"program_name",
                         "--key", "2147483648"}; // outside bounds of int

   VariablesMap vm = VariablesMap(3, argv);

   ADD_FAILING_TEST_IF(
      vm.asUInt("key") != 2147483648U,
      "Value of key not correctly stored as an uint");
}

/**
 * Return the requested value associated with the given key as a long integer
 */
void VariablesMap_UnitTest::test_asLong_001()
{
   const char* argv[] = {"program_name",
                         "--key", "4294967296"}; // outside bounds of uint

   VariablesMap vm = VariablesMap(3, argv);

   ADD_FAILING_TEST_IF(
      vm.asLong("key") != 4294967296L,
      "Value of key not correctly stored as a long");
}

/**
 * Return the requested value associated with the given key as an unsigned long integer
 */
void VariablesMap_UnitTest::test_asULong_001()
{
   const char* argv[] = {"program_name",
                         "--key", "9223372036854775808"}; // outside bounds of long

   VariablesMap vm = VariablesMap(3, argv);

   ADD_FAILING_TEST_IF(
      vm.asULong("key") != 9223372036854775808UL,
      "Value of key not correctly stored as an ulong");
}

/**
 * Return the requested value associated with the given key as a float
 */
void VariablesMap_UnitTest::test_asFloat_001()
{
   const char* argv[] = {"program_name",
                         "--key", "1.23"};

   VariablesMap vm = VariablesMap(3, argv);

   ADD_FAILING_TEST_IF(
      vm.asFloat("key") != 1.23F,
      "Value of key not correctly stored as a float");
}

/**
 * Return the requested value associated with the given key as a double
 */
void VariablesMap_UnitTest::test_asDouble_001()
{
   const char* argv[] = {"program_name",
                         "--key", "1.123456789876"}; // outside precision of float

   VariablesMap vm = VariablesMap(3, argv);

   ADD_FAILING_TEST_IF(
      // the subtraction is to confuse 4-byte floating operations
      vm.asDouble("key") - 0.000000001 != 1.123456789876 - 0.000000001,
      "Value of key not correctly stored as a double");
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

   VariablesMap_UnitTest cut;

   cut.test_Constructor_001();
   cut.test_Constructor_002();
   cut.test_Constructor_003();
   cut.test_set_001();
   cut.test_exists_001();
   cut.test_asVector_001();
   cut.test_asString_001();
   cut.test_asBool_001();
   cut.test_asInt_001();
   cut.test_asUInt_001();
   cut.test_asLong_001();
   cut.test_asULong_001();
   cut.test_asFloat_001();
   cut.test_asDouble_001();

   cut.printFailingTests();

   return 0;
}
