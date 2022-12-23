#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAXEXP 9
#define THREAD_COUNT 4
#define PARTITIONS_MOBIUS 12000
#define PARTITIONS_PERFECT 1200

pthread_mutex_t mutex;
int abundant_counter, deficient_counter, time_start, mobius_bounds, perfect_bounds, thread_feeder;
char mobius_array[1000000010];
int primes[6000];

void* mobius(void* args) {
    int count = *(int*)args;
    while (thread_feeder < mobius_bounds) {
        pthread_mutex_lock(&mutex);
        int lower, upper;
        if (thread_feeder == mobius_bounds) {
            break;
        }
        if (mobius_bounds - thread_feeder >= mobius_bounds / PARTITIONS_MOBIUS) {
            lower = thread_feeder;
            upper = thread_feeder + mobius_bounds / PARTITIONS_MOBIUS;
            thread_feeder += mobius_bounds / PARTITIONS_MOBIUS + 1;
        }
        else {
            lower = thread_feeder;
            upper = mobius_bounds;
            thread_feeder = mobius_bounds;
        }
        pthread_mutex_unlock(&mutex);
        for (int i = lower; i <= upper; i++) {

            int mobius_temp = i;
            int mobius_factor_count = 0;
            int mobius_bool = 1;

            for (int j = 0; primes[j] * primes[j] <= mobius_temp; j++) {
                if (mobius_temp % primes[j] == 0) {
                    mobius_temp /= primes[j];
                    if (mobius_temp % primes[j] == 0) {
                        mobius_bool = 0;
                        break;
                    }
                    mobius_factor_count++;
                }
            }
            if (mobius_temp != 1) {
                mobius_factor_count++;
            }

            if (mobius_bool) {
                if (mobius_factor_count % 2 == 0) {
                    mobius_array[i] = 1;
                } else {
                    mobius_array[i] = -1;
                }
            }
        }
    }
    printf("\nThread %d completed mobius at %ld\n\n", count, time(NULL) - time_start);
    return NULL;
}

void* perfect(void* args) {
    int count = *(int*)args;
    int abundantthread = 0;
    int deficientthread = 0;
    while (thread_feeder < perfect_bounds) {
        pthread_mutex_lock(&mutex);
        int lower, upper;
        if (thread_feeder == perfect_bounds) {
            break;
        }
        if (perfect_bounds - thread_feeder >= perfect_bounds / PARTITIONS_PERFECT) {
            lower = thread_feeder;
            upper = thread_feeder + perfect_bounds / PARTITIONS_PERFECT;
            thread_feeder += perfect_bounds / PARTITIONS_PERFECT + 1;
        }
        else {
            lower = thread_feeder;
            upper = perfect_bounds;
            thread_feeder = perfect_bounds;
        }
        pthread_mutex_unlock(&mutex);
        for (int i = lower; i <= upper; i++) {

            int divisor_sum = 1;
            int before;
            int temp = i;

            for (int j = 0; primes[j] * primes[j] <= temp; j++) {
                before = divisor_sum;
                while (temp % primes[j] == 0) {
                    divisor_sum = divisor_sum * primes[j] + before;
                    temp /= primes[j];
                }
            }
            if (temp != 1) {
                divisor_sum *= temp + 1;
            }
            divisor_sum -= i;

            if(divisor_sum == i) {
                printf("Found perfect number: %d\n", i);
            } else if (divisor_sum < i) {
                deficientthread++;
            } else {
                abundantthread++;
            }
        }
    }
    pthread_mutex_lock(&mutex);
    abundant_counter += abundantthread;
    deficient_counter += deficientthread;
    pthread_mutex_unlock(&mutex);
    printf("\nThread %d completed perfect at %ld\n\n", count, time(NULL) - time_start);
    return NULL;
}

void launch_threads(void* function) {
    pthread_t th[THREAD_COUNT];
    int count[THREAD_COUNT];
    time_start = time(NULL);
    for (int i = 0; i < THREAD_COUNT; i++) {
        count[i] = i;
        pthread_create(th + i, NULL, function, count + i);
    }
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(th[i], NULL);
    }
}

int main(void) {
    pthread_mutex_init(&mutex, NULL);
    // Calculating mobius bounds
    mobius_bounds = 1;
    for (int i = 1; i <= MAXEXP; i++) {
        mobius_bounds *= 10;
    }
    mobius_bounds += 9;

    // Sieve
    int prime_counter = 1;
    int primes_bound = (int)sqrt(mobius_bounds*2);
    primes[0] = 2;
    for (int i = 3; i <= primes_bound; i += 2) {
        int is_prime = 1;
        for (int j = 0; primes[j] * primes[j] <= i; j++) {
            if(i % primes[j] == 0) {
                is_prime = 0;
                break;
            }
        }
        if(is_prime) {
            primes[prime_counter++] = i;
        }
    }

    // Mobius threads
    thread_feeder = 1;
    launch_threads(&mobius);

    int mertens_bound = 19;
    int mertens_zp = 0;
    int mertens_value = 0;
    int j = 1;

    for (int i = 1; i <= MAXEXP; i++) {
        for ( ; j <= mertens_bound ; j++) {
            mertens_value += mobius_array[j]; 
            if (mertens_value == 0) {
                mertens_zp++;
            }
            if (mertens_bound - 18 <= j) {
                printf("M(%d) = %d\n", j, mertens_value);
            }
        }
        if(i != MAXEXP) {
            printf("..........\n");
        }
        mertens_bound = mertens_bound * 10 - 81;
    }
    printf("\nFound %d zero points of the Mertens function\n\n", mertens_zp);

    perfect_bounds = mertens_zp * 1000;

    printf("Checking numbers in the range [2,%d]\n\n", perfect_bounds);

    // Perfect threads
    thread_feeder = 2;
    launch_threads(&perfect);

    printf("\nFound %d deficient numbers\n", deficient_counter);
    printf("Found %d abundant numbers\n", abundant_counter);
    pthread_mutex_destroy(&mutex);
}
