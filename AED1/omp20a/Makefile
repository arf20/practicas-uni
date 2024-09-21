PROJECT := omp20a

CXX := g++
CXXFLAGS := -Wall -pedantic -g -O0


all: test

$(PROJECT): main.cpp
	$(CXX) -o $(PROJECT) $(CXXFLAGS) main.cpp

run: $(PROJECT)
	./$(PROJECT)

test: $(PROJECT)
	./$(PROJECT) < test_stdin.txt > run_stdout.txt
	cmp -s test_stdout.txt run_stdout.txt && echo "PASS" || echo "FAIL"

clean:
	rm $(PROJECT) run_stdout.txt

