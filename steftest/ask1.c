#include <stdio.h>

int main(void) {
    int ch;
    int counter[2] = {0, 0}; // 0 for lower 1 for upper
    int max[2] = {1, 0}; // 0 holds longest line 1 its counter
    int curr = 0; // hold current line char count
    int line = 1; // holds current line index
    int flag = 0; // stop print when #
    while ((ch = getchar()) != EOF) {
        if ('a' <= ch && ch <= 'z') ++counter[0];
        if ('A' <= ch && ch <= 'Z') ++counter[1];
        if (ch == '#') flag = 1;
        if (!flag || ch == '\n') putchar(ch);
        ++curr;
        if (ch == '\n') {
            flag = 0; // reset # flag
            if (curr > max[1]) {
                max[0] = line;
                max[1] = curr;
            }
            curr = 0; // reset counter
            ++line; // goto next line
        }
    }
    printf("Input had %d lowercase and %d uppercase characters\n", counter[0], counter[1]);
    printf("Longest line was %d\n", max[0]);
    return 0;
}