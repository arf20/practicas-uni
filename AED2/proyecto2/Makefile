all: bt

bt: main.cpp
	g++ -Wall -pedantic -g -O0 -o bt main.cpp

.PHONY: clean test

clean:
	rm bt

test:
	./bt < test.stdin > run.stdout
	cmp -s test.stdout run.stdout && echo "PASS" || echo "FAIL"

