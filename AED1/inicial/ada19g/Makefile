CC := gcc
CXX := g++
CFLAGS := -Wall -pedantic -g -O0

OUTPUT := ada19g

all: $(OUTPUT) test

$(OUTPUT): main.cpp
	$(CXX) $(CFLAGS) -o $(OUTPUT) *.cpp

test:
	./$(OUTPUT) < test_stdin.txt > run_stdout.txt
	cmp -s test_stdout.txt run_stdout.txt && echo "PASS" || echo "FAIL"

clean:
	rm $(OUTPUT) run* 

