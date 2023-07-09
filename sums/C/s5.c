#include <stdio.h>

int main() { 

  /* Declaring variables */
  double pi, sum;
  long i = 2;

  /* 
  * Summing terms two at a time 
  * while alternating sign
  */
  do {
    
    sum += 1 / ((double)i * (double)(i + 1) * (double)(i + 2));
    i += 2;
    sum -= 1 / ((double)i * (double)(i + 1) * (double)(i + 2));
    i += 2;

  } while (i < 1e+6);

  /* 
  * Calculating pi based on the
  * proven result of the sum
  */
  pi = 4 * sum + 3; 

  /* Printing result */
  printf("Summed %ld terms, pi is %1.16f\n", (i - 2) / 2, pi);
}
