CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++20
# CXXFLAGS = -std=c++20
CPPFLAGS = -Isrc/

GLIB = graphslib.a

ARFLAGS ?= rcs

OBJ = src/graphslib/graphs.o

GAD_OBJ = src/main.o $(OBJ) $(GLIB)
GAD_BIN = gad

TESTS_OBJ = tests/test_main.o $(OBJ) $(GLIB)
TESTS_BIN = unit_tests

all: $(GLIB) $(GAD_BIN)

library: $(GLIB)

$(GLIB): $(OBJ)

%.a:
	$(AR) $(ARFLAGS) $@ $^

$(GAD_BIN): $(GAD_OBJ)
	$(LINK.cc) $^ $(LDLIBS) -o $@

$(TESTS_BIN): LDLIBS += -lgtest
$(TESTS_BIN): $(TESTS_OBJ)
	$(LINK.cc) $^ $(LDLIBS) -o $@

check: $(TESTS_BIN)
	./$(TESTS_BIN)

clean:
	$(RM) $(GLIB) $(OBJ) $(GAD_OBJ) $(GAD_BIN)

.PHONY: all check clean
