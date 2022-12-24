#include <stdio.h>

int main(void) {
    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch == '\r') {
            fprintf(stderr, "\'\\r\' found\n");
        }
        else {
            putchar(ch);
        }
    }
        
    return 0;
}