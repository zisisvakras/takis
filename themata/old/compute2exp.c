#include <stdio.h>
#include <stdint.h>

uint64_t modular_pow(uint64_t b, uint64_t e, uint64_t m) {
    if (m == 1) return 0;
    uint64_t r = 1;
    b %= m;
    while (e > 0) {
        if (e % 2 == 1) r = (r * b) % m;
        b = (b * b) % m;
        e >>= 1;
    }
    return r;
}

int main(void) {
    for (int n = 1 ; n <= 9 ; ++n) {
        uint64_t m = 1, e = 2;
        for (int i = 0 ; i < n ; ++i, m*=3);
        for (int i = 0 ; i < n ; ++i, e*=10);
        uint64_t r = modular_pow(2, e, m);
        printf("n = %d, mod = %llu\n", n, r);
    }
    return 0;
}