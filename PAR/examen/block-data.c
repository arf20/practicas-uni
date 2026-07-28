P4

#define N 100000003
// Arbitrary size (not divisible by thread count)
int vin[N];
int vout[N];

#pragma omp parallel
{
    int id = omp_get_thread_id();
    int nth = omp_get_num_threads();
    int bs = (N / nth) + (N % nth);
    int end = (id == nth - 1) ? N : (id + 1) * bs;

    for (int i = id * bs; i < end; i++) {
        vout[i] = vin[i] * vin[i];
    }
}

1.

#pragma omp parallel
{
    int id = omp_get_thread_id();
    int nth = omp_get_num_threads();
    int bs = (N / nth) + (N % nth);
    int end = (id == nth - 1) ? N : (id + 1) * bs;

    for (int i = id * bs; i < end; i++) {
        vout[i] = vin[i] * vin[i];
    }
}

2.

int bs = get_cache_line_size() / sizeof(int);
#pragma omp parallel
{
    int id = omp_get_thread_id();
    int nth = omp_get_num_threads();

    for (int i = bs * id; i < N; i += nth * bs) {
        for (int j = i; j < min(i + bs, N); i++) {
            vout[i] = vin[i] * vin[i];
        }
    }
}

3.

int sums[NUM_THREADS][BYTES_PER_CACHE_LINE/sizeof(int)];

