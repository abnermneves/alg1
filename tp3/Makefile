CC := g++
SRCDIR := src
OBJDIR := build
BINDIR := bin

MAIN := program/main.cpp

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

# -g debug, --coverage para cobertura
CFLAGS := --coverage -g -Wall -O3 -std=c++11
INC := -I include/ -I third_party/

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

main: $(OBJECTS)
	$(CC) $(CFLAGS) $(INC) $(MAIN) $^ -o tp3

all: main

run: main
	./tp3

clean:
	$(RM) -r $(OBJDIR) $(BINDIR) coverage/* *.gcda *.gcno *.gcov tp3

.PHONY: clean coverage
