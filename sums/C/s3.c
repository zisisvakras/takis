#include <stdio.h>

int main() { 

  /* Declaring variables */
  double pi, sum;
  long i = 1;

  /* 
  * Summing terms two at a time 
  * while alternating sign
  */
  do {
    
    sum += 1 / (double)i;
    i += 2;
    sum -= 1 / (double)i;  
    i += 2;

  } while (i < 1e+9);

  /* 
  * Calculating pi based on the
  * proven result of the sum
  */
  pi = 4 * sum; 

  /* Printing result */
  printf("Summed %ld terms, pi is %1.16f\n", (i - 1) / 2, pi);
}
