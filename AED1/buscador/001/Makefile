PROJECT := buscador
CXX := g++
CFLAGS := -Wall -pedantic -g -O0

SRC := $(wildcard *.cpp)

all: test

$(PROJECT): $(SRC)
	$(CXX) $(CFLAGS) -o $(PROJECT) *.cpp

.PHONY: test
test: $(PROJECT)
	./$(PROJECT) < test_stdin.txt > run_stdout.txt
	cmp -s test_stdout.txt run_stdout.txt && echo "PASS" || echo "FAIL"

.PHONY: clean
clean:
	rm $(PROJECT) run* 
