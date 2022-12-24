#include <stdio.h>
#include <stdlib.h>
#define INFINITY -1

//FIXME: ORDER OF ARGS
int mincost;
int* stops_best;

int cost(int* stops, int nst, int* dests, int nrid) {
    int sum = 0;
    for (int i = 0 ; i < nrid ; i++) {
        int dest = dests[i];
        int somth = dest;
        for (int j = 0 ; j < nst ; j++) {
            int tempcost = dest <= stops[j] ? stops[j] - dest : dest - stops[j];
            if(tempcost < somth)
                somth = tempcost;
        }
        sum += somth;
    }
    return sum;
}

void permutation(int index, int* stops, int nst, int start, int nfl, int* dests, int nrid) {
    for (int j = start; j <= (nfl + index - nst + 1); ++j) {
        stops[index] = j;
        if (index + 1 < nst) {
            permutation(index + 1, stops, nst, j + 1, nfl, dests, nrid);
        }
        else {
            int temp = cost(stops, nst, dests, nrid);
            if (temp < mincost) {
                mincost = temp;
                for (int h = 0 ; h < nst ; h++) {
                    stops_best[h] = stops[h];
                }
            }
        }
    }
}

int solve(int nrid, int nst, int* dests) {

    /* Arrays that will hold possible elevator sequences */
    int* stops = malloc(nst * sizeof(int)); /* This holds floor stops */
    stops_best = malloc(nst * sizeof(int)); /* This holds floor stops of best solution */
    for (int i = 0 ; i < nst ; i++) { /* Initialize both stops and stops_best to zero */
        stops[i] = 0;
        stops_best[i] = 0;
    }
    
    /* Looping through all destinations to find the highest floor */
    int nfl = 0;
    for (int i = 0 ; i < nrid ; i++) { 
        if (dests[i] > nfl) {
            nfl = dests[i];
        }
    }

    /* Initialize mincost with cost of the elevator going nowhere */
    mincost = cost(stops, nst, dests, nrid);

    /* Begin calculating the permutations */
    for (int i = nst - 1; i >= 0 ; i--) {
        permutation(i, stops, nst, 1, nfl, dests, nrid);
    }
    
    /* Messages required by solution */
    if (stops_best[nst - 1] == 0) { /* If last floor on stops_best is 0 it means the elevator went nowhere */
        printf("No lift stops\n");
    }
    else {
        printf("Lift stops are:");
        for (int i = 0 ; i < nst - 1 ; i++) {
            if(stops_best[i]) /* Its possible that we don't move all nst floors */
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