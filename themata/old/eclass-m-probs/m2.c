#include <stdio.h>
#include <stdlib.h>

int div_sum(int num) {
    int div = 5, sum = 1, temp = num, term = 1, step = 4;
    while (temp % 2 == 0) {
        term = term * 2 + 1;
        temp /= 2;
    }
    sum *= term;
    term = 1;
    while (temp % 3 == 0) {
        term = term * 3 + 1;
        temp /= 3;
    }
    sum *= term;

    while (div * div <= temp && sum < num + 1) {
        term = 1;
        while (temp % div == 0) {
            term = term * div + 1;
            temp /= div;
        }
        sum *= term;
        div += step ^= 6;
    }
    if (temp != 1) {
        sum *= temp + 1;
    }
    return sum - num;
}

int main(int argc, char** argv) {
    if (argc != 2) return 1;
    int bound = atoi(argv[1]);
    if (bound < 284) return 0;
    for (int i = 2 ; i <= bound ; ++i) {
        int sum;
        if ((sum = div_sum(i)) > i) {
            if (sum <= bound && div_sum(sum) == i) {
                printf("%d - %d\n", i, sum);
            }
        }
    }
    return 0;
}