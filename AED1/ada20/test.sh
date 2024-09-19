#!/bin/bash

build/ada20 < test_stdin.txt > run_stdout.txt

cmp -s test_stdout.txt run_stdout.txt && echo "PASS" || echo "FAIL"


