CC := gcc
CXX := g++
CFLAGS := -Wall -pedantic

all: omp19a test

omp19a: main.cpp
	$(CXX) $(CFLAGS) -o omp19a *.cpp

test:
	./omp19a < test_stdin.txt > run_stdout.txt
	cmp -s test_stdout.txt run_stdout.txt && echo "PASS" || echo "FAIL"

clean:
	rm omp19a run* 

