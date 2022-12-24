#include <stdio.h>
#define MAXEXP 8

int main() {

    int mertens_bound = 19;
    int mertens_zp = 0;
    int mertens_prev = 0;
    int j = 0;

    for (int i = 1; i <= MAXEXP; i++) {
        while (j < mertens_bound) {

            j++;

            if(j % 4 == 0 || j % 9 == 0 || j % 25 == 0 || j % 49 == 0) {
                if (mertens_prev == 0) {
                    mertens_zp++;
                }
                if (mertens_bound - 18 <= j) {
                    printf("M(%d) = %d\n", j, mertens_prev);
                }
                continue;
            }

            int mobius_temp = j;
            int mobius_factor = 11;
            int mobius_factor_count = 0;
            int mobius_bool = 1;

            if(mobius_temp % 2 == 0) {
                mobius_temp /= 2;
                mobius_factor_count++;
            }
            if(mobius_temp % 3 == 0) {
                mobius_temp /= 3;
                mobius_factor_count++;
            }
            if(mobius_temp % 5 == 0) {
                mobius_temp /= 5;
                mobius_factor_count++;
            }
            if(mobius_temp % 7 == 0) {
                mobius_temp /= 7;
                mobius_factor_count++;
            }

            while (mobius_factor * mobius_factor <= mobius_temp) {
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 2;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 4;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 2;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 4;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 6;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 2;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 6;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 4;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 2;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 4;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 6;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 6;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 2;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 6;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 4;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 2;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 6;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 4;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 6;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 8;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 4;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 2;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 4;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 2;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 4;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 8;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 6;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 4;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 6;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 2;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 4;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 6;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 2;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 6;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 6;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 4;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 2;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 4;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 6;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 2;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 6;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 4;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 2;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 4;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 2;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 10;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 2;
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 10;
            }
            if (mobius_temp != 1) {
                mobius_factor_count++;
            }

            if (mobius_bool) {
                if (mobius_factor_count % 2 == 0) {
                    mertens_prev++;
                } else {
                    mertens_prev--;
                }
            }

            if (mertens_prev == 0) {
                mertens_zp++;
            }
            if (mertens_bound - 18 <= j) {
                printf("M(%d) = %d\n", j, mertens_prev);
            }
        }
        if(i != MAXEXP) {
            printf("..........\n");
        }
        mertens_bound = mertens_bound * 10 - 81;
    }
    printf("\nFound %d zero points of the Mertens function\n\n", mertens_zp);

    int perfect_bound = mertens_zp * 1000;
    int abundant_counter = 0;
    int deficient_counter = 0;

    printf("Checking numbers in the range [2,%d]\n\n", perfect_bound);

    for (int i = 2; i <= perfect_bound; i++) {

        int divisor = 2;
        int divisor_sum = 1;
        int before;

        int temp = i;

        before = divisor_sum;
        while (temp % divisor == 0) {
            divisor_sum = divisor_sum * divisor + before;
            temp /= divisor;
        }
        divisor = 3;

        before = divisor_sum;
        while (temp % divisor == 0) {
            divisor_sum = divisor_sum * divisor + before;
            temp /= divisor;
        }
        divisor = 5;

        before = divisor_sum;
        while (temp % divisor == 0) {
            divisor_sum = divisor_sum * divisor + before;
            temp /= divisor;
        }
        divisor = 7;

        before = divisor_sum;
        while (temp % divisor == 0) {
            divisor_sum = divisor_sum * divisor + before;
            temp /= divisor;
        }
        divisor = 11;

        while (divisor * divisor <= temp) {
            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 2;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 4;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 2;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 4;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 6;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 2;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 6;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 4;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 2;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 4;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 6;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 6;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 2;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 6;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 4;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 2;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 6;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 4;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 6;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 8;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 4;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 2;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 4;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 2;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 4;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 8;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 6;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 4;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 6;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 2;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 4;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 6;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 2;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 6;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 6;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 4;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 2;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 4;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 6;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 2;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 6;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 4;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 2;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 4;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 2;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 10;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 2;

            before = divisor_sum;
            while (temp % divisor == 0) {
                divisor_sum = divisor_sum * divisor + before;
                temp /= divisor;
            }
            divisor += 10;

        }
        if (temp != 1) {
            divisor_sum *= temp + 1;
        }
        divisor_sum -= i;

        if(divisor_sum == i) {
            printf("Found perfect number: %d\n", i);
        } else if (divisor_sum < i) {
            deficient_counter++;
        } else {
            abundant_counter++;
        }
    }

    printf("\nFound %d deficient numbers\n", deficient_counter);
    printf("Found %d abundant numbers\n", abundant_counter);
}
