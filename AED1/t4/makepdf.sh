#!/bin/sh
iconv -f utf8 -t latin1 memoria.txt | enscript -l -M A4 -f Courier@11 -p - | ps2pdf - - > memoria.pdf

