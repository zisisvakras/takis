#include <stdio.h>
#include <stdint.h>

int get_digits(uint32_t num) {
    int count = 1;
    while ((num /= 10) != 0) ++count;
    return count;
}

int power_ten(int power) {
    int res = 1;
    for (int i = 1 ; i <= power ; ++i) res *= 10;
    return res;
}

void print_by_digit(uint32_t num, int digits) {
    for (int i = 31 ; i >= 0 ; --i) {
        if ((digits >> i) & 1) {
            putchar((num / power_ten(i)) % 10 + '0');
        }
    }
    putchar(' ');
}

int main(void) {
    uint32_t num;
    printf("Please, give a positive integer: ");
    if (scanf("%u", &num) != 1) return 1;
    if (num == 0) return 1;
    printf("All subsequences of %u are: ", num);
    int digits = get_digits(num);
    uint32_t bound = 0xFFFFFFFF;
    bound >>= (32U - digits);
    for (int i = bound ; i > 0 ; --i) {
        print_by_digit(num, i);
    }
    putchar('\n');
    return 0;
}