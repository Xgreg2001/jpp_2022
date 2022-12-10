CXX ?= g++
CXXFLAGS ?= -std=c++14 -Wall -Wextra -pedantic -O2

all: test

test: test.cpp finite_field.h
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f test
