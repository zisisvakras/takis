#include <stdio.h>
#include <stdlib.h>
#include "lift.h"

/* Function described by the assignment */
int fw(int start, int finish, int nrid, int* dests) {
    int sum = 0;
    if (finish == INFINITY) { 
        /* 
        *  If the second arg is infinity we don't need to calculate 
        *  infinity - dest because it will always be the larger one 
        */
        for (int i = 0 ; i < nrid ; i++) {
            if (dests[i] > start) { /* Is the destination within the range */
                sum += dests[i] - start; /* Adding the cost */
            }
        }
    }
    else {
        for (int i = 0 ; i < nrid ; i++) {
            if (dests[i] > start && dests[i] <= finish) { /* Is the destination within the range */
                if (dests[i] - start < finish - dests[i]) { /* Check which has lower cost */
                    sum += dests[i] - start; /* Adding the cost */
                }
                else {
                    sum += finish - dests[i]; /* Adding the cost */
                }
            }
        }
    }
    return sum;
}

/* Function described by the assignment */
int M(int i, int j, int nrid, int* dests, int** mvalues) {
     /* In case i is 0 we need to execute the first formula described in the solution*/
    if (i == 0) {
        if (mvalues[0][0] == INFINITY) { /* Catch the initial value */
            mvalues[0][0] = fw(0, INFINITY, nrid, dests);
        }
        return mvalues[0][0]; /* All M(0, j) is the same for all j */
    }
    int min = INFINITY;
    for (int k = 0 ; k <= j ; k++) { /* Using the sum described in solution */
        int sum = 0;
        if (mvalues[i - 1][k] == INFINITY) { /* Catch the initial value */
            mvalues[i - 1][k] = M(i - 1, k, nrid, dests, mvalues);
        }
        sum += mvalues[i - 1][k];
        sum -= fw(k, INFINITY, nrid, dests);
        sum += fw(k, j, nrid, dests);
        sum += fw(j, INFINITY, nrid, dests);
        if (sum < min || min == INFINITY) { /* At the start we want to catch the infinity value */
            min = sum;
        }
    }
    return min;
}


int solve(int nrid, int nst, int* dests) {
    int min = INFINITY; /* This holds the result of MinCost */
    int nfl = 0, last_floor = 0;

    /* Looping through all destinations to find the highest floor */
    for (int i = 0 ; i < nrid ; i++) { 
        if (dests[i] > nfl) {
            nfl = dests[i];
        }
    }

    /* Initializing the 2d array that will store the values of M function,
    *  M will have as inputs the values 0 to nst for i, and 0 to nfl for j
    *  therefore we need an array with (nfl + 1)*(nst + 1) size like the following:
    */
    int** mvalues = malloc((nst + 1) * sizeof(int*));
    if (mvalues == NULL) {
        fprintf(stderr, "Couldn\'t allocate memory\n");
        return -1;
    }
    for (int h = 0 ; h <= nst ; h++) {
        mvalues[h] = malloc((nfl + 1) * sizeof(int));
        if (mvalues[h] == NULL) {
            fprintf(stderr, "Couldn\'t allocate memory\n");
            return -1;
        }
        for (int k = 0 ; k <= nfl ; k++) {
            mvalues[h][k] = INFINITY;
        }
    }

    /* Executing the MinCost as described by the solution */
    for (int j = 0 ; j <= nfl ; j++) {
        int temp = M(nst, j, nrid, dests, mvalues);
        if (temp < min || min == INFINITY) { /* At the start we want to catch the infinity value */
            min = temp;
            last_floor = j;
        }
    }

    /* Messages required by solution */
    if (last_floor == 0) {
        printf("No lift stops\n");
    }
    else {
        printf("Last stop at floor %d\n", last_floor);
    }

    /* Freeing the 2d array */
    for (int h = 0 ; h <= nst ; h++) {
        free(mvalues[h]);
    }
    free(mvalues);

    return min;
}