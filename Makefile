CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++20
# CXXFLAGS = -std=c++20
CPPFLAGS = -Isrc/

GLIB = graphslib.a

ARFLAGS ?= rcs

OBJ = src/graphslib/graphs.o

GAD_OBJ = src/main.o $(OBJ) $(GLIB)
GAD_BIN = gad

all: $(GLIB) $(GAD_BIN)

library: $(GLIB)

$(GLIB): $(OBJ)

%.a:
	$(AR) $(ARFLAGS) $@ $^

$(GAD_BIN): $(GAD_OBJ)
	$(LINK.cc) $^ $(LDLIBS) -o $@

clean:
	$(RM) $(GLIB) $(OBJ) $(CLI_OBJ) $(GAD_BIN) src/main.o

.PHONY: all check clean
