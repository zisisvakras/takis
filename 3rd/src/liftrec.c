#include <stdio.h>
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
int M(int i, int j, int nrid, int* dests) {
    /* When i = 0 we need to calculate fw(0, INF) */
    if (i == 0) {
        return fw(0, INFINITY, nrid, dests);
    }
    int min = INFINITY;
    for (int k = 0 ; k <= j ; k++) { /* Using the sum described in solution */
        int sum = 0;
        sum += M(i - 1, k, nrid, dests);
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

    /* Executing the MinCost as described by the solution */
    for (int j = 0 ; j <= nfl ; j++) {
        int temp = M(nst, j, nrid, dests);
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
    return min;
}