/* khperf.c */

#include <stdio.h>
#include <stdlib.h>

int modified_div_sum(int num) {
    int div = 5, sum = 1, temp = num, term = 1;
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
        div += 2;
        term = 1;
        while (temp % div == 0) {
            term = term * div + 1;
            temp /= div;
        }
        sum *= term;
        div += 4;
    }
    if (temp != 1) sum *= temp + 1;
    return sum - num - 1;
}

int main(int argc, char** argv) {
    if (argc != 3) return 1;
    int low = atoi(argv[1]);
    int up = atoi(argv[2]);
    if (low <= 1 || up <= 1) return 1;
    if (up < low) return 0;
    for (int i = low ; i <= up ; ++i) {
        int sum = modified_div_sum(i), k = 2;
        if (sum == 0) continue;
        while (k * sum + 1 < i) ++k;
        if (k * sum + 1 == i) {
            printf("%d is %d-hyperperfect\n", i, k);
        }
    }
    return 0;
}