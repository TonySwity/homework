#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>

enum { N = 10 };

static inline int is_even64(int64_t x) { return (x & 1) == 0; }

static inline int64_t sat_mul_ll(int64_t a, int64_t b) {
    if (a == 0 || b == 0) return 0;
    __int128 prod = (__int128)a * (__int128)b;
    if (prod > LLONG_MAX) return LLONG_MAX;
    return (int64_t)prod;
}

static int64_t prod_digits_by_parity(int64_t x, int want_even) {
    uint64_t v = (x < 0) ? (uint64_t)(-(uint64_t)x) : (uint64_t)x;
    int64_t p = 1;

    do {
        int d = (int)(v % 10u);
        if (((d & 1) == 0) == (want_even != 0)) {
            p = sat_mul_ll(p, d);
            if (p == LLONG_MAX) return p;
        }
        v /= 10u;
    } while (v != 0u);

    return p;
}

static void transform_array(int64_t a[], size_t n) {
    size_t even = 0;
    for (size_t i = 0; i < n; ++i) if (is_even64(a[i])) ++even;
    size_t odd = n - even;

    const int change_even = (odd >= even);
    for (size_t i = 0; i < n; ++i) {
        if (is_even64(a[i]) == change_even) {
            a[i] = prod_digits_by_parity(a[i], change_even);
        }
    }
}

int main(void) {
    int64_t a[N];
    for (size_t i = 0; i < N; ++i) {
        if (scanf("%" SCNd64, &a[i]) != 1) return 0;
    }

    transform_array(a, N);

    for (size_t i = 0; i < N; ++i) {
        printf("%" PRId64 "%c", a[i], (i + 1 == N) ? '\n' : ' ');
    }
    return 0;
}
