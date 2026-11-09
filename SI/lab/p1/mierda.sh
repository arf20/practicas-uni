#!/bin/bash

# fixed
NG=10000
CROSS=ONEP
MUT=FLIP
SEL=TOUR

# var
# ./nreinas 8 100 1000 ROUL ONEP FLIP 0.85 0.025


for TP in 100 150
do
    for PC in 0.85 0.9
    do
        for PM in 0.05 0.025 0.01375 0.0125
        do
            for NREINAS in 7 8 23 28 40 41 61 68 72 73
            do
                jaques=$(./nreinas $NREINAS $TP $NG $SEL $CROSS $MUT $PC $PM)
                printf "%d,%d,%d,%s,%s,%s,%f,%f,%d\n" $NREINAS $TP $NG $SEL $CROSS $MUT $PC $PM "$jaques" >> resultados.csv
            done
        done
    done
done

