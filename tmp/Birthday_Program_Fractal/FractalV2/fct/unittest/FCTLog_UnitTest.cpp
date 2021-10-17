/**
 * @author Forrest Jablonski
 */

#include "FCTLog_UnitTest.h"

// ---------------------------------------------------------------------
// ------------------------------ Helpers ------------------------------
// ---------------------------------------------------------------------

/**
 *
 */
void FCTLog_UnitTest::openOutfile()
{
   gOutfile = std::fopen("temp/fctlog.txt", "w");

   PRINT_FAILURE_AND_ABORT_IF(
      gOutfile == nullptr,
      "Could not open temp/fctlog.txt during unittest");
}

/**
 *
 */
void FCTLog_UnitTest::closeOutfile()
{
   std::fclose(gOutfile);
   gOutfile = nullptr;
}

// ---------------------------------------------------------------------
// ----------------------------- Test List -----------------------------
// ---------------------------------------------------------------------

/**
 * Prints fmt as the logging message
 */
void FCTLog_UnitTest::test_FCT_LOG_001()
{
   const int a = 11;
   const int b = 13;

   openOutfile();

   const std::string message =
           "A=11 and B=13";
   FCT_LOG("A=%d and B=%d\n", a, b);

   closeOutfile();

   areStringsInFile("temp/fctlog.txt",
                    "Log did not give expected information",
                    {message});
}

/**
 * Prints fmt as the logging message immediately
 */
void FCTLog_UnitTest::test_FCT_LOG_NOW_001()
{
   const int a = 11;
   const int b = 13;

   openOutfile();

   const std::string message =
               "A=11 and B=13";
   FCT_LOG_NOW("A=%d and B=%d\n", a, b);

   closeOutfile();

   areStringsInFile("temp/fctlog.txt",
                    "Log did not give expected information",
                    {message});
}

// ---------------------------------------------------------------------
// -------------------------------- main -------------------------------
// ---------------------------------------------------------------------

/**
 *
 */
int main(int argc, char* argv[])
{
   FCTLog_UnitTest cut;

   cut.test_FCT_LOG_001();
   cut.test_FCT_LOG_NOW_001();

   cut.printFailingTests();

   return 0;
}
