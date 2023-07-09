#include <stdio.h>

/* Data variables */
int stairs, temp;
int a = 0;
int b = 1;

int main() {

    /* Getting data */ 
    printf("\nEnter the number of stairs: ");
    scanf("%d", &stairs);

    /* Calculating N + 2 number of the fibonacci sequence */
    for (int i = 0; i < stairs; ++i) {
        temp = a + b;
        a = b;
        b = temp;
    }

    /* Printing the result */
    printf("\nAnswer: %d ways", b);
    return 0;
}