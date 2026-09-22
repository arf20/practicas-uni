# Practica 1

## 1. Caracteristicas

```
Microarquitectura: Ivy-Bridge
Tecnología: 22nm
Turbo: 3.1GHz
Cores/Threads: 2/4
AVX: Sí
Cache L1i/L1d/L2/L3: 32K/32K/256K/3MB

Memoria: 16GB
Canales:
Ancho: 64 bit
Velocidad: PC3-1600
```

## 2. Rendimiento pico

Rp\_1(sp) = 8 * 2 * 1 * 3.1\*10^9 = 49 GFLOPS
Rp\_2,1(sp) = 8 * 2 * 1 * 3.1\*10^9 * 2 * 1 = 98 GFOPS

## 3.

Ab_1 = 1 * 2 * 8 * 1600*10^6 = 25.6 GB/s

## 4.

Peakperf (1): Average performance:      27.48 +- 1.84 GFLOP/s
Peakperf (N): Average performance:      85.23 +- 3.19 GFLOP/s
peak-flops-gcc (1): Average time (s):    2.66±0.00  GFLOPS:   48.11±0.08    threads = 1 inner_iterations = 32
peak-flops-gcc (2): Average time (s):    1.40±0.00  GFLOPS:   91.15±0.03    threads = 2 inner_iterations = 64



## 5.

peak-mem-gcc (1): Average GiB/s:      15.76±0.52      threads = 1
peak-mem-gcc (N): Average GiB/s:      16.42±0.24      threads = 2

