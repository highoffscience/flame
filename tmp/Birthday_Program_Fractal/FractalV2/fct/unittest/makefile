##
# @author Forrest Jablonski
#

# The following flags are for use with gcov
#  -fprofile-arcs -ftest-coverage -g

# When adding a target, update Regression.py!
# It is recommended to use Regression.py instead of calling this makefile
#  directly to minimize chances of forgetting to sync the two files
# TODO fix above concerns

CC     = g++
INCS   = -I../hdr/ -Icommon/
LFLAGS = 
CFLAGS = -Ofast -std=c++14 -DFCT_UNITTEST

COMMON_SRCS = $(wildcard common/*.cpp)

all:
	@$(error Must call with class identifier)

fctassert: FCTAssert_UnitTest.cpp ../src/FCTAssert.cpp $(COMMON_SRCS)
	@$(CC) $(CFLAGS) $(INCS) -o bin/$@.out $^ $(LFLAGS)

fctlog: FCTLog_UnitTest.cpp ../src/FCTLog.cpp $(COMMON_SRCS)
	@$(CC) $(CFLAGS) $(INCS) -o bin/$@.out $^ $(LFLAGS)

pixel: Pixel_UnitTest.cpp ../src/Pixel.cpp $(COMMON_SRCS)
	@$(CC) $(CFLAGS) $(INCS) -o bin/$@.out $^ $(LFLAGS)

point: Point_UnitTest.cpp ../src/Point.cpp $(COMMON_SRCS)
	@$(CC) $(CFLAGS) $(INCS) -o bin/$@.out $^ $(LFLAGS)

variablesmap: VariablesMap_UnitTest.cpp ../src/VariablesMap.cpp ../src/FCTAssert.cpp $(COMMON_SRCS)
	@$(CC) $(CFLAGS) -DFCT_UNITTEST_ASSERT_RETURN $(INCS) -o bin/$@.out $^ $(LFLAGS)

random: Random_UnitTest.cpp ../src/Random.cpp $(COMMON_SRCS)
	@$(CC) $(CFLAGS) $(INCS) -o bin/$@.out $^ $(LFLAGS)

fitter: Fitter_UnitTest.cpp ../src/Fitter.cpp ../src/VariablesMap.cpp ../src/FCTAssert.cpp $(COMMON_SRCS)
	@$(CC) $(CFLAGS) $(INCS) -o bin/$@.out $^ $(LFLAGS)

colorschemelib: ColorSchemeLibrary_UnitTest.cpp ../src/ColorSchemeLibrary.cpp ../src/ColorScheme.cpp ../src/Pixel.cpp ../src/VariablesMap.cpp ../src/FCTAssert.cpp $(COMMON_SRCS)
	@$(CC) $(CFLAGS) $(INCS) -o bin/$@.out $^ $(LFLAGS)

#
# Cleaning up
#
clean:
	@rm -rf bin/*.out *.~
