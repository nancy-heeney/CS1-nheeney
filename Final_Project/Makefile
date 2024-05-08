# This is a comment in a make file
CXX = clang++
PROGRAM = final_project.exe
FLAGS = -c -g -Wall -std=c++17
CPPFILES = final_project.cpp final_project_visual.cpp

all:
	$(CXX) $(FLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

run:
	./$(PROGRAM)

# A clean rule clears object and binary files for fresh compilation
# If in windows, use 'del' instead of 'rm'
clean:
	rm $(PROGRAM) *.o