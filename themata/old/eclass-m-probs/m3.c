#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t isprime(uint64_t num) {
    for (uint64_t i = 3 ; i * i <= num ; i+=2)
        if (num % i == 0) return 0;
    return 1;
}

uint64_t main(uint64_t argc, char** argv) {
    if (argc != 2) return 1;
    uint64_t bound = atoi(argv[1]);
    if (bound < 1) return 1;
    uint64_t i = 2, j = 3, h = 5, k = 7, sum = 87;
    printf("%2d^2 + %2d^2 + %2d^2 + %2d^2 = %4d\n", i, j, h, k, sum);
    while (i * i <= bound) {
        i = j, j = h, h = k;
        for (k = h + 2 ; k * k <= bound ; k+=2)
            if (isprime(k)) break;
        if ((sum = i*i + j*j + h*h + k*k) <= bound)
            printf("%2d^2 + %2d^2 + %2d^2 + %2d^2 = %4d\n", i, j, h, k, sum);
    }
    return 0;
}