PROJECT := 403

.PHONY: clean test

all: $(PROJECT)

$(PROJECT): $(PROJECT).cpp
	g++ -g -O0 -Wall -pedantic -o $(PROJECT) $(PROJECT).cpp

clean:
	rm 402

test: $(PROJECT)
	./$(PROJECT) < test_stdin.txt > run_stdout.txt
	cmp -s test_stdout.txt run_stdout.txt && echo "PASS" || echo "FAIL"

