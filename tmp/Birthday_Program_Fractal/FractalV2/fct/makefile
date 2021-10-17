#
# @author Forrest Jablonski
#

# .cpp files reside in src/
# .h   files reside in hdr/
# .lib files reside in lib/
# .o   files reside in obj/
# .p   files reside in dep/ (these are actually dependency files)

CC       = g++
INC      = hdr/
CFLAGS   = -Wall -Werror -Wreorder -std=c++17 -O3 -I$(INC)
DBGFLAGS = 
PNGFLAGS = `libpng-config --cflags` `libpng-config --ldflags`
EXE      = fractal

SRCS := $(wildcard src/*.cpp)
OBJS := $(patsubst src/%.cpp, obj/%.o, $(SRCS))

DEPS = obj/$*.d
PEPS = dep/$*.p

$(EXE): $(OBJS)
	@echo "Linking..."
	@$(CC) $(OBJS) -o $(EXE) $(PNGFLAGS)

obj/%.o: src/%.cpp
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $(DBGFLAGS) -MMD -c -o $@ $<
	@cp $(DEPS) $(PEPS); \
	 sed -e 's/#.*//' \
	     -e 's/^[^:]*: *//' \
	     -e 's/ *\\$$//' \
	     -e '/^$$/ d' \
	     -e 's/$$/ :/' < $(DEPS) >> $(PEPS); \
	 rm -rf $(DEPS)

-include dep/*.p

.PHONY: run
run:
	@./$(EXE)

.PHONY: gdb
gdb:
	@gdb ./$(EXE)

.PHONY: tar
tar:
	@rm -rf $(EXE).tar
	@tar cfv $(EXE).tar hdr/* src/* makefile

.PHONY: clean
clean:
	@rm -rf obj/* dep/* $(EXE) $(EXE).tar
