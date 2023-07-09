/*
*   Any grid bigger than 34x34 will overflow,
*   for bigger numbers use Python or Rust :)  
*/
#include <stdio.h>

/* Data variables */
int columns, rows;

int main() {

    /* Getting data */ 
    printf("\nEnter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    /* Creating the matrix(grid) */
    unsigned long long square[rows][columns];

    /* Executing the algorithm described in solution */
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (j == 0 || i == 0) {
                square[i][j] = 1ULL;
            } 
            else {
                square[i][j] = square[i - 1][j] + square[i][j - 1];
            }
        }
    }

    /* Printing the result */
    printf("\nThe different paths are: %lld", square[--rows][--columns]);
    return 0;
}