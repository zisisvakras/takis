#include <stdio.h>
#include <stdlib.h>

int isprime(int num) {
    if (num & 1) return 0;
    for (int i = 3 ; i * i <= num ; i+=2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main(int argc, char** argv) {
    if (argc != 2) return 1;
    int bound = atoi(argv[1]);
    if (bound < 4) return 1;
    printf("4 = 2 + 2\n"); // getting rid of 2 forever :)
    for (int i = 4 ; i <= bound ; i+=2) {
        for (int j = 3 ; (j << 1) <= i ; j+=2) {
            if (isprime(j) && isprime(i - j)) {
                printf("%d = %d + %d\n", i, j, i-j);
            }
        }
    }
    return 0;
}