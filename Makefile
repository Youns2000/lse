CXX = g++ -g
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++20 -fPIC -Isrc/
LIBS = -lgvc -lcgraph

ARFLAGS ?= rcs
GLIB = gad.a
OBJ = src/gad/gad.o

GAD_OBJ = src/main.o $(OBJ)
GAD_BIN = gad

TESTS_OBJ = tests/test_main.o $(OBJ) $(GLIB)
TESTS_BIN = unit_tests

# all and lib commands
all: $(GLIB) $(GAD_BIN)
library: $(GLIB)

# lib rules
$(GLIB): $(OBJ)

# .a rules
%.a:
	$(AR) $(ARFLAGS) $@ $^

# GAD exe rules
$(GAD_BIN): $(GAD_OBJ)
	$(LINK.cc) $^ $(LDLIBS) -o $@ $(LIBS)


# Tests Rules
$(TESTS_BIN): LDLIBS += -lgtest -lpthread
$(TESTS_BIN): $(TESTS_OBJ)
	$(LINK.cc) $^ $(LDLIBS) -o $@ $(LIBS)

# tests command
check: $(TESTS_BIN)
	./$(TESTS_BIN)

clean:
	$(RM) $(GLIB) $(OBJ) $(GAD_OBJ) $(GAD_BIN) $(TESTS_OBJ) *.dot *.png

.PHONY: all check clean