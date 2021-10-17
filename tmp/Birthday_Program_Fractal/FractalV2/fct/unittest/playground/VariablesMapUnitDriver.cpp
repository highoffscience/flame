/**
 * @author Forrest Jablonski
 */

#define FCT_UNITTEST

// class under test
// ---------------------------
#include "VariablesMap.h" // -
using namespace fct;      // -
// ---------------------------

#pragma GCC push_options
#pragma GCC optimize ("O2") // don't optimize the testing suite too much

#include <iostream>
#include <string>
#include <vector>

////////////////////////////////////////////////////////////////////////
//                            Declarations                            //
////////////////////////////////////////////////////////////////////////

/**
 *
 */
class VariablesMapUnitTest
{

private:

   std::vector<std::string> _failingTests;

public:

   void test_Constructor_001();

};

////////////////////////////////////////////////////////////////////////
//                             Definitions                            //
////////////////////////////////////////////////////////////////////////

/**
 *
 */
void test_Constructor_001()
{
   const int argc = 10; // this number depends on variable below
   const char* const argv[] = {{"name_of_program"},
                               {"--shape"  }, {"triangle" },
                               {"--cities" }, {"Hong-Kong"}, {"Castlebar"},
                               {"--planets"}, {"Mercury"  }, {"Venus"    }, {"Earth"}};

   VariablesMap vm = VariablesMap(argc, argv);


}

////////////////////////////////////////////////////////////////////////
//                                Start                               //
////////////////////////////////////////////////////////////////////////

/**
 *
 */
int main(int argc, char* argv[])
{
   VariablesMapUnitTest cut;

   cut.test_Constructor_001();

   return 0;
}

#pragma GCC pop_options
