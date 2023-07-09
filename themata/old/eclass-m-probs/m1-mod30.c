#include <stdio.h>
#include <stdlib.h>

int isprime(int num) {
    if (num & 1) return 0;
    if (num % 3 == 0) return 0;
    if (num % 5 == 0) return 0;
    for (int i = 7 ; i * i <= num ; i+=30) {
        if (num % i == 0) return 0;
        if (num % (i + 4) == 0) return 0;
        if (num % (i + 6) == 0) return 0;
        if (num % (i + 10) == 0) return 0;
        if (num % (i + 12) == 0) return 0;
        if (num % (i + 16) == 0) return 0;
        if (num % (i + 22) == 0) return 0;
        if (num % (i + 24) == 0) return 0;
    }
    return 1;
}

int main(int argc, char** argv) {
    if (argc != 2) return 1;
    int bound = atoi(argv[1]);
    if (bound < 4) return 1;
    printf("4 = 2 + 2\n"); // getting rid of 2 forever :)
    for (int i = 4 ; i <= bound ; i+=2) {
        if (isprime(3) && isprime(i - 3)) {
            printf("%d = %d + %d\n", i, 3, i - 3);
        }
        for (int j = 5 ; (j << 1) <= i ; j+=6) {
            if (isprime(j) && isprime(i - j)) {
                printf("%d = %d + %d\n", i, j, i - j);
            }
            if (isprime(j + 2) && isprime(i - j - 2)) {
                printf("%d = %d + %d\n", i, j + 2, i - j - 2);
            }
        }
    }
    return 0;
}