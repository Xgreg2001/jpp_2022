CXX ?= g++
CXXFLAGS ?= -std=c++14 -Wall -Wextra -Werror -pedantic -O2

all: test

test: test.o finite_field.o
	$(CXX) $(CXXFLAGS) -o $@ $^

test.o: test.cpp finite_field.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

finite_field.o: finite_field.cpp finite_field.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f test *.o
