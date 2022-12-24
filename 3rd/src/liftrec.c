#include <stdio.h>
#define INFINITY -1

/* Function described by the assignment */
int fw(int start, int finish, int nrid, int* dests) {
    int sum = 0; /* Initialize sum */
    if (finish == INFINITY) { 
        /* If the right value is infinite we don't need to calculate 
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
     /* In case i is 0 we need to execute the first formula described in the solution*/
    if (i == 0) {
        return fw(0, INFINITY, nrid, dests);
    }
    int min = INFINITY; /* Initializing the current min value */
    for (int k = 0 ; k <= j ; k++) { /* Using the sum described in solution */
        int sum = 0;
        sum += M(i - 1, k, nrid, dests);
        sum -= fw(k, INFINITY, nrid, dests);
        sum += fw(k, j, nrid, dests);
        sum += fw(j, INFINITY, nrid, dests);
        if (sum < min || min == INFINITY) { /* At the start we want to catch the infinite value */
            min = sum;
        }
    }
    return min;
}


int solve(int nrid, int nst, int* dests) {
    int nfl = 0; /* Declaring nfl variable*/
    int min = INFINITY; /* This holds the result of MinCost */
    int floor = 0; /* This holds the last stop */

    /* Looping through all destinations to find the highest floor */
    for (int i = 0 ; i < nrid ; i++) { 
        if (dests[i] > nfl) {
            nfl = dests[i];
        }
    }

    /* Executing the MinCost as described by the solution */
    for (int j = 0 ; j <= nfl ; j++) {
        int temp = M(nst, j, nrid, dests);
        if (temp < min || min == INFINITY) { /* At the start we want to catch the infinite value */
            min = temp;
            floor = j;
        }
    }

    /* Messages required by solution */
    if (floor == 0) {
        printf("No lift stops\n");
    }
    else {
        printf("Last stop at floor %d\n", floor);
    }
    return min;
}