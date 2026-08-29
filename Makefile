CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra

all: printRange

printRange: printRange.cpp
	$(CXX) $(CXXFLAGS) -o printRange printRange.cpp

clean:
	rm -f printRange

.PHONY: all clean
