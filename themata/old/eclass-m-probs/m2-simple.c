/* m2-simple.c */

#include <stdio.h>
#include <stdlib.h>

int div_sum(int num) {
    int sum = 1, i = 2;
    for ( ; i * i < num ; ++i) {
        if (num % i == 0) {
            sum += i;
            sum += num / i ;
        }
    }
    if (num % i == 0) sum += i;
    return sum;
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