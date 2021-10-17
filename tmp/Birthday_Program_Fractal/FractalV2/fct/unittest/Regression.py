#!/usr/bin/python3.5

##
# @author Forrest Jablonski
#

# Script outputs nothing if everything passed

import sys
import subprocess

##
# openProcess
#
def openProcess(command):
   proc = subprocess.Popen([command],
                           shell  = True, # no external input should be allowed, only hard-coded commands
                           stdout = subprocess.PIPE,
                           stderr = subprocess.PIPE,
                           universal_newlines = True)
   return proc

##
# printOutAndErr
#
def printOutputAndError(out, err):
   print("<> stdout yields <>")
   print(out, end=""          )
   print("<> stdout end <>"   )

   print("<> stderr yields <>")
   print(err, end=""          )
   print("<> stderr end <>"   )

##
# main
#
def main():
   availableTests = ["fctassert",
                     "fctlog",
                     "pixel",
                     "point",
                     "variablesmap",
                     "random",
                     "fitter",
                     "colorschemelib"]

   testsToRun = []
   if len(sys.argv) == 1: # the first arg is always the program name
      testsToRun = availableTests
   else:
      requestedTestsToRun = sys.argv[1:]
      for test in requestedTestsToRun:
         if test not in availableTests:
            print("Error: Test %s not an available test" % test)
            sys.exit(1)
         testsToRun.append(test)

   for test in testsToRun:
      # build the test
      proc = openProcess("make %s" % test)
      out, err = proc.communicate()

      if proc.returncode != 0:
         print("Making %s failed!" % test)
         printOutputAndError(out, err)
         sys.exit(1)

      # run the test
      proc = openProcess("bin/%s.out" % test)
      out, err = proc.communicate()

      if proc.returncode != 0:
         print("Running %s failed!" % test)
         printOutputAndError(out, err)
         sys.exit(1)

      if ("*FAIL*" in out) and ("*LIAF*" in out):
         printOutputAndError(out, err)
         sys.exit(1)

#
# main procedure
#

if __name__ == "__main__":
   main()
else:
   print("Error: Module meant to be run stand-alone, not imported!")
   sys.exit(1)
