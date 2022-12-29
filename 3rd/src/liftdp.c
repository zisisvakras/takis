#include <stdio.h>
#include <stdlib.h>
#define INFINITY -1 /* Any negative number would have worked for INFINITY */

//TODO REVIEW COMMENTS

/* Function described by the assignment */
int fw(int start, int finish, int nrid, int* dests) {
    int sum = 0; /* Initialize sum */
    if (finish == INFINITY) { 
        /* 
        *  If finish is infinity we don't need to calculate 
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

int solve(int nrid, int nst, int* dests) {
    int nfl = 0; /* This holds the highest destination */
    /* Looping through all destinations to find the highest floor */
    for (int i = 0 ; i < nrid ; i++) { 
        if (dests[i] > nfl) {
            nfl = dests[i];
        }
    }

    /* 
    *  Initializing a 2d array that will store the values of M function,
    *  M will have as inputs the values 0 to nst for i, and 0 to nfl for j
    *  therefore we need an array with size (nfl + 1)*(nst + 1)
    * 
    *  Also initializing a 2d array that will store the k of M(i - 1, k) that has the lowest cost when
    *  calculating M(i, j), for more info review the solution to the problem provided by the assignment
    */
    int** mvalues = malloc((nst + 1) * sizeof(int*));
    int** kvalues = malloc((nst + 1) * sizeof(int*));
    int* stops = malloc((nst + 1) * sizeof(int)); //TODO ADD EXPLANATION
    if (mvalues == NULL || kvalues == NULL || stops == NULL) { /* Error case */
        fprintf(stderr, "Couldn't allocate memory");
        return -1;
    }
    for (int i = 0 ; i <= nst ; i++) {
        mvalues[i] = malloc((nfl + 1) * sizeof(int));
        kvalues[i] = malloc((nfl + 1) * sizeof(int));
        if (mvalues[i] == NULL || kvalues[i] == NULL) { /* Error case */
            fprintf(stderr, "Couldn't allocate memory");
            return -1;
        }
    }

    /* M(0, j) for all j will be fw(0, INF) */
    int value_at_zero = fw(0, INFINITY, nrid, dests);
    for (int j = 0 ; j <= nfl ; j++) {
        mvalues[0][j] = value_at_zero;
        kvalues[0][j] = 0; /* The elevator didn't move */
        printf("%3d ", mvalues[0][j]); /* Using 3d so results will be properly displayed */
    }
    printf("\n"); /* New line for proper display */

    /* Finding M(1, 0) through M(nst, nfl) */
    int mincost = mvalues[0][0]; /* Initialize MinCost with the value of M(0, 0) */
    for (int i = 1 ; i <= nst ; i++) { /* Start at i = 1 since we did 0 just before */
        for (int j = 0 ; j <= nfl ; j++) {
            int min = INFINITY; /* Initializing the current min value of M(i - 1, k) */
            for (int k = 0 ; k <= j ; k++) { /* Using the sum described in solution */
                int sum = 0;
                sum += mvalues[i - 1][k]; /* M(i - 1, k) will have been calculated since we are following a bottom-up approach */
                sum -= fw(k, INFINITY, nrid, dests);
                sum += fw(k, j, nrid, dests);
                sum += fw(j, INFINITY, nrid, dests);
                if (sum < min || min == INFINITY) { /* At the start we want to catch the infinity value */
                    min = sum;
                    kvalues[i][j] = k; /* Save floor path to print at the end */
                }
            }
            mvalues[i][j] = min; /* Assign M(i, j) to the min value of the previous sums */
            if (mvalues[i][j] < mincost) { /* If new M(i, j) is smaller than the current mincost change it */
                mincost = mvalues[i][j];
                stops[nst] = j; /* We need to save last floor for later */
            }
            printf("%3d ", mvalues[i][j]); /* Using 3d so results will be properly displayed */
        }
        printf("\n"); /* New line for proper display */
    }

    /* Finding the stop sequence using the k-array and the last floor */
    for (int i = nst ; i > 0 ; i--) {
        stops[i - 1] = kvalues[i][stops[i]];
    }

    /* Messages required by solution */
    if (stops[nst] == 0) { /* If last floor was 0 then the elevator didn't move */
        printf("No lift stops\n");
    }
    else {
        printf("Lift stops are:");
        for (int i = 0 ; i <= nst ; i++) {
            if(stops[i]) { /* If floor is 0 (no movement) no need to print */
                printf(" %d", stops[i]);
            }
        }
        printf("\n");
    }
    
    /* Freeing the 2d arrays */
    for (int i = 0 ; i <= nst ; i++) {
        free(mvalues[i]);
        free(kvalues[i]);
    }
    free(mvalues);
    free(kvalues);
    free(stops);

    return mincost;
}