#include <stdio.h>

/* Selection sorting */  
void ssort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/* Data variables */
int frds;

int main() {

    /* Getting necessary data */
    printf("\nNumber of friends in the grid: ");
    scanf("%d", &frds);

    /* Initiating the arrays and getting data */
    int c[frds], r[frds];
    for (int i = 0; i < frds; ++i) {
        printf("\nColumn of friend %d: ", i + 1);
        scanf("%d", &c[i]);
        printf("Row of friend %d: ", i + 1);
        scanf("%d", &r[i]);
    }
    ssort(c, frds);
    ssort(r, frds);

    /* Executing solution and printing the result */
    if (frds % 2 == 1) {
        int mid = (frds - 1) / 2;
        printf("\nThe optimal location for the coffee shop is: (%d,%d)", c[mid], r[mid]);
    }
    else {
        int mid = frds / 2;
        printf("\nThe optimal locations for the coffee shop are: (%d-%d,%d-%d)", c[mid - 1], c[mid], r[mid - 1], r[mid]);
    }
    return 0;
}
