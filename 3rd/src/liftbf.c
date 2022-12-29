#include <stdio.h>
#include <stdlib.h>
#define INFINITY -1

//FIXME: ORDER OF ARGS, CHANGE VARIABLE NAMES,  COMMENTS

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

int generate_next(int* stops, int nst, int nfl) {
    if(stops[nst - 1] != nfl) {
        stops[nst - 1]++;
        return 1;
    }
    for (int i = nst - 2; i >= 0 ; i--) {
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
    int* stops = malloc(nst * sizeof(int)); /* This holds floor stops */
    int* stops_best = malloc(nst * sizeof(int)); /* This holds floor stops of best solution */
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
    int mincost = cost(stops, nst, dests, nrid);

    /* Begin calculating the permutations */
    while(generate_next(stops, nst, nfl)) {
        int temp = cost(stops, nst, dests, nrid);
        if (temp < mincost) {
            mincost = temp;
            for (int h = 0 ; h < nst ; h++) {
                stops_best[h] = stops[h];
            }
        }
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