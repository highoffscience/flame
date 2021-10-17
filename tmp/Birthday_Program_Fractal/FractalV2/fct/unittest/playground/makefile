#
# @author Forrest Jablonski
#

# the following is for use with gcov
# -fprofile-arcs -ftest-coverage -g

CC = g++
INC = ../hdr/
CFLAGS = -Ofast -std=c++11 -I$(INC)
PNGFLAGS = `libpng-config --cflags` `libpng-config --ldflags`

all:
	@echo "Must call with class identifier"

pixel: PixelUnitDriver.cpp
	@$(CC) $(CFLAGS) -o $@.out $<

random: RandomUnitDriver.cpp
	@$(CC) $(CFLAGS) -o $@.out $<

vector: ArrayVectorUnitDriver.cpp
	@$(CC) $(CFLAGS) -o $@.out $<

variablesmap: VariablesMapUnitDriver.cpp
	@$(CC) $(CFLAGS) -o $@.out $<

assert: FCTAssertUnitDriver.cpp ../src/FCTAssert.cpp
	@$(CC) $(CFLAGS) -o $@.out $^

#
# Cleaning up
#
clean:
	@rm -rf *.out *.~
