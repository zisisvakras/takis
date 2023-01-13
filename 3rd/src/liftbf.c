#include <stdio.h>
#include <stdlib.h>
#include "lift.h"

/*
*  Calculate the cost of a stop sequence by using the following algorithm:
*  1. For every passenger destination (0 to nrid) find the first stop (from the
*  stop sequence provided) thats higher than the passenger's, let's call it j.
*  2. Calculate the cost for the passenger going to jth stop and the (j-1)th stop.
*  3. Add to the cost whichever is lowest.
*  4. If the jth stop is the first stop of the sequence then j-1 will be set to the
*  ground floor (cost is the same as passenger's floor)
*  5. If the passenger's floor is higher than all stops provided then add
*  [passenger's floor - highest stop floor] to the total cost.
*/
int cost(int* stops, int nst, int* dests, int nrid) {
    int sum = 0, index = 0;
    while (index < nst && stops[index] == 0) ++index; /* Skip the zeroes at start */
    for (int i = 0 ; i < nrid ; ++i) {
        int temp = nst > 0 ? dests[i] - stops[nst - 1] : INFINITY;
        int prev = dests[i]; /* Initialize the previous floor with "ground cost" */
        if (temp >= 0) { /* Is the passenger's floor higher than all stops? */
            sum += temp;
            continue;
        }
        for (int j = index ; j < nst ; ++j) {
            /*
            *  Check if current floor is higher than passenger's destination 
            *  and save the cost as well to put into the previous variable
            */
            if ((temp = stops[j] - dests[i]) >= 0) { 
                sum += temp < prev ? temp : prev; /* Add the cost to which ever desision is best */
                break;
            }
            prev = -temp;
        }
    }
    return sum;
}

/*
*  This function provided with the previous stop sequence provides
*  the next one and returns 1, if the sequence is the last one then
*  it returns 0. The algorithm is the following:
*
*  1. Start at the last element (nst) of the stop sequence
*  2. See if element is at its max possible value (nfl + i - nst + 1).
*  3. If it is then go to the previous element and go to step 2
*  4. If its not then add one to the current element and for all the ones after it
*  assign their values to [previous element + 1].
*  5. If the first element is at its max then return 0.
*
*  Example behavior (case of nfl = 9, nst = 5):
*  [0,0,0,0,0] -> [0,0,0,0,1] return 1;
*  [0,0,0,0,1] -> [0,0,0,0,2] return 1;
*
*  [0,0,0,0,9] -> [0,0,0,1,2] return 1;
*  [0,0,0,1,2] -> [0,0,0,1,3] return 1;
*
*  [0,6,7,8,9] -> [1,2,3,4,5] return 1;
*  [5,6,7,8,9] -> return 0;
*/
int generate_next(int* stops, int nst, int nfl) {
    for (int i = nst - 1; i >= 0 ; i--) {
        if(stops[i] != nfl + i - nst + 1) {
            stops[i]++;
            for (int j = i + 1 ; j < nst ; j++) {
                stops[j] = stops[j - 1] + 1;
            }
            return 1;
        }
    }
    return 0;
}

int solve(int nrid, int nst, int* dests) {

    /* Arrays that will hold possible elevator sequences */
    int* stops = calloc(nst, sizeof(int)); /* This holds floor stops */
    int* stops_best = calloc(nst, sizeof(int)); /* This holds floor stops of best solution */
    if (stops == NULL || stops_best == NULL) {
        fprintf(stderr, "Couldn\'t allocate memory\n");
        return -1;
    }
    
    /* Looping through all destinations to find the highest floor */
    int nfl = 0;
    for (int i = 0 ; i < nrid ; i++) { 
        if (dests[i] > nfl) {
            nfl = dests[i];
        }
    }

    /* Initialize mincost with cost of the elevator going nowhere */
    int mincost = cost(stops, nst, dests, nrid);
    
    /* Begin calculating the permutations (starts from [0,0,0.....] because of calloc) */
    while(generate_next(stops, nst, nfl)) {
        int temp = cost(stops, nst, dests, nrid);
        if (temp < mincost) {
            mincost = temp;
            for (int h = 0 ; h < nst ; h++) { /* Keep the current best sequence */
                stops_best[h] = stops[h];
            }
        }
    }
    
    /* Messages required by solution */
    if (nst == 0 || stops_best[nst - 1] == 0) { /* If last floor on stops_best is 0 it means the elevator went nowhere */
        printf("No lift stops\n");
    }
    else {
        printf("Lift stops are:");
        for (int i = 0 ; i < nst - 1 ; i++) {
            if(stops_best[i]) /* Its possible that we don't stop all nst floors */
                printf(" %d", stops_best[i]);
        }
        printf(" %d\n", stops_best[nst - 1]);
    }

    /* Free allocated memory */
    free(stops);
    free(stops_best);

    /* Return mincost */
    return mincost;
}