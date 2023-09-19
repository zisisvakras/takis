#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int digitSum(int n) {
    if (n == 0) return 0;
    return n % 10 + digitSum(n / 10);
}

int main(int argc, char** argv) {
    if (argc != 2) return 1;
    int count = atoi(argv[1]);
    if (count <= 0) return 1;
    ++count; // adding one extra for loop
    srand(time(NULL));
    while (--count) {
        int random = rand();
        printf("digitSum(%d)=%d\n", random, digitSum(random));
    }
    return 0;
}