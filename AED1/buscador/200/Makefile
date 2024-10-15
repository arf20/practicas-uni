PROJECT := buscador
BINARY := a.out
CXX := g++
CFLAGS := --std=c++17 -Wall -pedantic -g -O0

SRC := $(wildcard *.cpp)

all: $(BINARY)

$(BINARY): $(SRC)
	$(CXX) $(CFLAGS) *.cpp

.PHONY: test
test: $(BINARY)
	./$(PROJECT) < test_stdin.txt > run_stdout.txt
	cmp -s test_stdout.txt run_stdout.txt && echo "PASS" || echo "FAIL"

.PHONY: clean
clean:
	rm $(BINARY) run* 

.PHONY: tar
tar: $(PROJECT).tar

$(PROJECT).tar: $(SRC) Makefile
	tar cf $(PROJECT).tar *.cpp *.hpp Makefile

.PHONY: submit
submit: tar
	python3 submit.py
