/**
 * @author Forrest Jablonski
 */

#include "TestSuiteFramework.h"

#include <iostream>
#include <cstdio>
#include <fstream>

/**
 *
 */
void TestSuiteFramework::printFailingTests()
{
   for (const auto& failingTest : _failingTests)
   {
      std::cout << "*FAIL* --- "
                << failingTest.functionName << "#" << failingTest.lineNumber << " --- "
                << failingTest.description << " --- *LIAF*"
                << std::endl;
   }
}

/**
 *
 */
void TestSuiteFramework::addFailingTest(const std::string& functionName,
                                        const unsigned int lineNumber,
                                        const std::string& description)
{
   _failingTests.push_back({functionName, lineNumber, description});
}

/**
 *
 */
void TestSuiteFramework::printFailureAndAbort(const std::string& functionName,
                                              const unsigned int lineNumber,
                                              const std::string& description)
{
	std::cerr << "!!! Unittest Internal Failure!!!!" << std::endl
	          << functionName << "#" << lineNumber << std::endl
             << description << std::endl;

	std::exit(1);
}

/**
 *
 */
void TestSuiteFramework::areStringsInFile(const std::string& fileName,
                                          const std::string& errorMessage,
                                          const std::list<std::string>& stringsToFind)
{
   std::ifstream infile = std::ifstream(fileName);

   PRINT_FAILURE_AND_ABORT_IF(
      infile.is_open() == false,
      "Could not open " + fileName + " during unittest");

   std::string line;
   std::string fileContents;
   while (std::getline(infile, line))
   {
      fileContents += line;
   }
   
   for (const std::string& stringToFind : stringsToFind)
   {
      std::cout << stringToFind << std::endl;
      if (fileContents.find(stringToFind) == std::string::npos)
      { // couldn't find string
         ADD_FAILING_TEST(errorMessage);
      }
   }

   infile.close();
}
