#include <stdio.h>
#include <stdlib.h>
#include "lift.h"

int main(void) {
    /* Declaring input variables */
    int nrid, nst;
    int* dests;

    /* Getting program input */
    if(scanf("%d", &nrid) != 1) { /* Error case */
        fprintf(stderr, "Couldn't read input");
        return -1;
    }
    if(scanf("%d", &nst) != 1) { /* Error case */
        fprintf(stderr, "Couldn't read input");
        return -1;
    }

    /* Scanning for destinations */
    dests = malloc(nrid * sizeof(int));

    if (dests == NULL) { /* Error case */
        fprintf(stderr, "Couldn't allocate memory");
        return -1;
    }

    for (int i = 0 ; i < nrid ; i++) {
        if(scanf("%d", dests + i) != 1) { /* Error case */
            fprintf(stderr, "Couldn't read input");
            return -1;
        }
    }

    /* Solving the problem */
    int cost = solve(nrid, nst, dests);

    if (cost == -1) { /* Error case */
        return -1;
    }

    /* Printing the cost */
    printf("Cost is: %d\n", cost);

    /* Free memory allocated for destinations */
    free(dests);
}