/**
 * @author Forrest Jablonski
 */

#ifndef _FCT_UNITTEST_TESTSUITEFRAMEWORK_H_
#define _FCT_UNITTEST_TESTSUITEFRAMEWORK_H_

#define ADD_FAILING_TEST(desc)        addFailingTest      (__FUNCTION__, __LINE__, (desc))
#define PRINT_FAILURE_AND_ABORT(desc) printFailureAndAbort(__FUNCTION__, __LINE__, (desc))

#define ADD_FAILING_TEST_IF(cond, desc)    \
   if (cond)                               \
   {                                       \
      ADD_FAILING_TEST(desc); \
   } (void)0 // to force semicolon

#define PRINT_FAILURE_AND_ABORT_IF(cond, desc)    \
   if (cond)                                      \
   {                                              \
      PRINT_FAILURE_AND_ABORT(desc); \
   } (void)0 // to force semicolon

#include <string>
#include <list>

/**
 *
 */
class TestSuiteFramework
{

private:

   struct FailingTestInformation
   {
      const std::string  functionName;
      const unsigned int lineNumber;
      const std::string  description;
   };

private:

   std::list<FailingTestInformation> _failingTests;

public:

   explicit TestSuiteFramework() = default;
   virtual ~TestSuiteFramework() = default;

   void printFailingTests();

protected:

   void addFailingTest(const std::string& functionName,
                       const unsigned int lineNumber,
                       const std::string& description);

   void printFailureAndAbort(const std::string& functionName,
                             const unsigned int lineNumber,
                             const std::string& description);

   void areStringsInFile(const std::string& fileName,
                         const std::string& errorMessage,
                         const std::list<std::string>& stringsToFind);

}; // TestSuiteFramework

#endif // _FCT_UNITTEST_TESTSUITEFRAMEWORK_H_
