#include <stdio.h>
#include <stdlib.h>

int modular_pow(int base, int exp, int mod) {
    if (mod == 1) return 0;
    int res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

int main(int argc, char** argv) {
    if (argc != 4) return 1;
    int base = atoi(argv[1]);
    int exp = atoi(argv[2]);
    int mod = atoi(argv[3]);
    if (base < 1 || exp < 1 || mod < 1) return 1;
    int res = modular_pow(base, exp, mod);
    printf("%d\n", res);
    return 0;
}