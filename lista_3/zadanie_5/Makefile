CXX ?= g++
CXXFLAGS ?= -std=c++14 -Wall -Wextra -pedantic

all: hamming

hamming: hamming.cpp finite_field.h polynomial.h
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f test *.o
