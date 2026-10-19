#!/bin/bash

# fixed
TP=100
NG=10000
CROSS=ONEP
MUT=FLIP
SEL=TOUR
PC=0.85

# programa
PROG=./nreinas2

# var
# ./nreinas 8 100 1000 ROUL ONEP FLIP 0.85 0.025


for NREINAS in 7 8 23 28 40 41 61 68 72 73
do
    if [ $NREINAS -le 8 ]; then
        PM=0.05
    elif [ $NREINAS -ge 9 ] && [ $NREINAS -le 60 ]; then
        PM=0.0125
    elif [ $NREINAS -eq 61 ]; then
        PM=0.01375
    elif [ $NREINAS -ge 62 ] && [ $NREINAS -le 70 ]; then
        PM=0.0125
    fi

    time ./nreinas2 $NREINAS $TP $NG $SEL $CROSS $MUT $PC $PM > test_$NREINAS.txt
    echo $NREINAS completed.
done

