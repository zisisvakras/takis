#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if (argc != 2) return 1;
    int bound = atoi(argv[1]);
    if (bound < 1729) return 1;
    int i, j, k, h, temp, flag;
    for (int num = 1 ; num <= bound ; ++num) {

        flag = 0;
        for (i = 1 ; i*i*i < num ; ++i) {
            temp = i*i*i;
            for (j = i + 1 ; temp + j*j*j <= num ; ++j) {
                if (temp + j*j*j == num) {
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }

        flag = 0;
        for (k = i + 1 ; k*k*k < num ; ++k) {
            temp = k*k*k;
            for (h = k ; temp + h*h*h <= num ; ++h) {
                if (temp + h*h*h == num) {
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        } 

        if (i*i*i + j*j*j == num && k*k*k + h*h*h == num) {
            printf("%5d = %2d^3 + %2d^3 = %2d^3 + %2d^3\n", num, i, j, k, h);
        }
    }
    return 0;
}