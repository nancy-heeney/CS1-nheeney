CXX = clang++
CPP = makefile.cpp
FLAGS = -c -g -Wall -std:c++17
PROGRAM = makefile.cpp

build:
	$(CXX) $(CPP) $(FLAGS)
	$(CXX) -o $(PROGRAM) *.o

clean:
	rm $(PROGRAM) *.object

test:
	$(PROGRAM) test

run:
	./a.out