PROJECT := buscador
BINARY := a.out
CXX := g++
CXXFLAGS := --std=c++17 -Wall -pedantic -g -O0
LDFLAGS := 

SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp,%.o,$(SRC))

all: $(BINARY)

$(BINARY): $(OBJ)
	$(CXX) -o $(BINARY) $(OBJ) $(LDFLAGS)

%.o: %.cpp %.hpp
	$(CXX) -c $(CXXFLAGS) $<

.PHONY: test
test: $(BINARY)
	./$(BINARY) < test_stdin.txt > run_stdout.txt
	cmp -s test_stdout.txt run_stdout.txt && echo "PASS" || echo "FAIL"

.PHONY: clean
clean:
	rm $(BINARY) *.o run* *.tar

.PHONY: tar
tar: $(PROJECT).tar

$(PROJECT).tar: $(SRC) Makefile
	tar cf $(PROJECT).tar *.cpp *.hpp Makefile

.PHONY: submit
submit: tar
	python3 submit.py
