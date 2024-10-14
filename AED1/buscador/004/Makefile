PROJECT := buscador
CXX := g++
CFLAGS := --std=c++17 -Wall -pedantic -g -O0

SRC := $(wildcard *.cpp)

all: $(PROJECT)

$(PROJECT): $(SRC)
	$(CXX) $(CFLAGS) -o $(PROJECT) *.cpp

.PHONY: test
test: $(PROJECT)
	./$(PROJECT) < test_stdin.txt > run_stdout.txt
	cmp -s test_stdout.txt run_stdout.txt && echo "PASS" || echo "FAIL"

.PHONY: clean
clean:
	rm $(PROJECT) run* 

.PHONY: tar
tar: $(PROJECT).tar

$(PROJECT).tar: $(PROJECT)
	tar cf $(PROJECT).tar *.cpp *.hpp Makefile

.PHONY: submit
submit: tar
	python3 submit.py
