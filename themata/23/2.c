#include <stdio.h>
#include <stdlib.h>

int isOre(int num) {
    int sum = 1 + num, count = 2, i;
    for (i = 2 ; i * i < num ; ++i) {
        if (num % i == 0) {
            sum += i;
            sum += num / i ;
            count += 2;
        }
    }
    if (i * i == num) {
        sum += i;
        count++;
    }
    return (num * count) % sum == 0 ? 1 : 0;
}

int main(int argc, char** argv) {
    if (argc != 2) return 1;
    int bound = atoi(argv[1]);
    if (bound < 1) return 1;
    for (int i = 1 ; i <= bound ; ++i)
        if (isOre(i)) printf("%d ", i);
    putchar('\n');
    return 0;
}
