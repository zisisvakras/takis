#include <stdio.h>
#define MAXEXP 8

int main() {
    /*
    *   Start of Mertens Section
    */

    /* Variables for mertens loop and value */
    int mertens_bound = 19; /* Bound for loop */
    int mertens_zp = 0; /* Counter for zero points in mertens */
    int mertens_value = 0; /* Holds the value of mertens */
    int j = 1; /* Nested loop iteration counter */

    /* Main loop going through all exponents from 1 to MAXEXP */
    for (int i = 1 ; i <= MAXEXP ; i++) {
        /*
        *  Looping through all values from 1 to 10^MAXEXP + 9
        *  first loop is 1 - 19 then 20 - 109 and so on
        */
        for ( ; j <= mertens_bound ; j++) { /* First param is empty because j = j every time this loop runs */

            /*
            *   Start of Mobius Section
            */
            
            /* Skipping numbers by checking 2^2 and 3^2 now */
            if(j % 4 == 0 || j % 9 == 0) {
                if (mertens_value == 0) { /* If M(j) is 0 then we need to add 1 to counter */
                    mertens_zp++;
                }
                if (mertens_bound - 18 <= j) { /* Printing all values within 10^i - 9 TO 10^i + 9 */
                    printf("M(%d) = %d\n", j, mertens_value);
                }
                continue;
            }

            /* Variables to calculate mobius value */
            int mobius_temp = j; /* Holds number so we can change it to the quotient */
            int mobius_factor = 5; /* This holds the current factor */
            int mobius_factor_count = 0; /* Counter for factors in number */
            int mobius_bool = 1; /* If the number is square free boolean */

            /* Dividing 2 and 3 since we checked for them */
            if(mobius_temp % 2 == 0) {
                mobius_temp /= 2;
                mobius_factor_count++;
            }
            if(mobius_temp % 3 == 0) {
                mobius_temp /= 3;
                mobius_factor_count++;
            }

            /* 
            *   Main loop for checking and counting factors
            *   skipping multiples of 2 and 3 (sieve with Step 6/Mod 6)
            */
            while (mobius_factor * mobius_factor <= mobius_temp) {
                /* Getting rid of current factor loop */
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 2; /* Step 2 */

                /* Getting rid of current factor after step 2 */
                if (mobius_temp % mobius_factor == 0) {
                    mobius_temp /= mobius_factor;
                    if (mobius_temp % mobius_factor == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
                mobius_factor += 4; /* Step 4 */
            }
            /* Checking if last quotient was a factor */
            if (mobius_temp != 1) {
                mobius_factor_count++;
            }

            /* Calculating M(j) using the stored value of M(j-1) */
            if (mobius_bool) { /* If number is not square free then mobius is 0 */
                if (mobius_factor_count % 2 == 0) {
                    mertens_value++;
                } else {
                    mertens_value--;
                }
            }
            /*
            *   End of Mobius Section
            */

            if (mertens_value == 0) { /* If M(j) is 0 then we need to add 1 to counter */
                mertens_zp++;
            }
            if (mertens_bound - 18 <= j) { /* Printing all values within 10^i - 9 TO 10^i + 9 */
                printf("M(%d) = %d\n", j, mertens_value);
            }
        }
        if(i != MAXEXP) { /* On the last exponent we don't want to separate result */
            printf("..........\n");
        }
        /* Calculating next bounds using the formula upper = (upper - 9) * 10 + 9 */
        mertens_bound = mertens_bound * 10 - 81;
    }
    /* Printing the zero points we found */
    printf("\nFound %d zero points of the Mertens function\n\n", mertens_zp);

    /*
    *   End of Mertens Section
    */

    /*
    *   Start of Perfect, Abundant and Deficient numbers Section
    */

    /* Variables for perfect loop and counters */
    int perfect_bound = mertens_zp * 1000; /* Upper bound for loop */
    int abundant_counter = 0; /* Counter for abundant numbers */
    int deficient_counter = 0; /* Counter for deficient numbers */

    /* Printing check */
    printf("Checking numbers in the range [2,%d]\n\n", perfect_bound);

    /* Main loop to check sum of divisors */
    for (int i = 2 ; i <= perfect_bound ; i++) {

        /* Variables for loop */
        int divisor = 5; /* Starting prime */
        int divisor_sum = 1; /* Sum of divisors */
        int temp = i; /* Temp will be assigned to quotient */
        int product_term = 1; /* Variable to calculate product */
        
        /* Getting rid of 2 and 3 so we can sieve using mod 6 */
        while (temp % 2 == 0) {
            product_term = product_term * 2 + 1;
            temp /= 2;
        }
        divisor_sum *= product_term;
        product_term = 1;
        while (temp % 3 == 0) {
            product_term = product_term * 3 + 1;
            temp /= 3;
        }
        divisor_sum *= product_term;

        /* 
        *   Loop to calculate prime factors and
        *   sum using product taught on the lesson,
        *   skipping multiples of 2 and 3 (sieve with Step 6/Mod 6)
        */
        while (divisor * divisor <= temp && divisor_sum < i + i) {
            /* Getting rid of current divisor loop */
            product_term = 1;
            while (temp % divisor == 0) {
                product_term = product_term * divisor + 1;
                temp /= divisor;
            }
            divisor_sum *= product_term;
            divisor += 2; /* Step 2 */

            /* Getting rid of current divisor loop after step 2 */
            product_term = 1;
            while (temp % divisor == 0) {
                product_term = product_term * divisor + 1;
                temp /= divisor;
            }
            divisor_sum *= product_term;
            divisor += 4; /* Step 4 */
        }
        /* Checking if last quotient was a factor */
        if (temp != 1) {
            divisor_sum *= temp + 1;
        }
        /* Removing i from sum since we are looking for proper divisors */
        divisor_sum -= i;

        /* Checking for Perfect, Abundant and Deficient */
        if(divisor_sum == i) {
            printf("Found perfect number: %d\n", i);
        } else if (divisor_sum < i) {
            deficient_counter++;
        } else {
            abundant_counter++;
        }
    }
    
    /* Printing Abundant and Deficient numbers */
    printf("\nFound %d deficient numbers\n", deficient_counter);
    printf("Found %d abundant numbers\n\n", abundant_counter);

    /*
    *   End of Perfect, Abundant and Deficient numbers Section
    */
}
