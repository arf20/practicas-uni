#!/bin/sh
iconv -f utf8 -t latin1 memoria.txt | enscript -B -f Courier11 -p - | ps2pdf - - > memoria.enscript.pdf

