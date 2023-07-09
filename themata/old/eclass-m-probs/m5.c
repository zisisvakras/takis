#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if (argc != 2) return 1;
    int size = atoi(argv[1]);
    if (size == 0) return 1;
    printf("Please, give %d integers: ", size);

    int max = 0;
    int begin = 1, begin_temp = 1;
    int end = 1;
    int temp = 0, num;
    for (int i = 0 ; i < size ; ++i) {
        if (scanf("%d", &num) != 1) return 1;
        temp += num;
        if (temp <= 0) {
            begin_temp = i + 2;
            temp = 0;
            continue;
        }
        if (temp > max) {
            max = temp;
            begin = begin_temp;
            end = i + 2;
        }
    }

    printf("Max sum = %d of numbers with indices in [%d,%d)\n", max, begin, end);
    return 0;
}
// -2 1 -3 4 -1 2 1 -5 4
// 3 8 1 4 8
// -5 -3 -2 -6
// -3 6 2 -9 4 1 3