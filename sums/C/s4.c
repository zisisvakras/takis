#include <stdio.h>

int main() { 

  /* Declaring variables */
  double sum;
  long i = 1;

  /* 
  * Summing terms as described
  * by the infinite series s4
  */
  do {
    
    sum += 1 / ((double)i * (double)(i + 2));
    i += 2;

  } while (i < 1e+9);

  /* Printing result */
  printf("Summed %ld terms, 1/2 is %1.16f\n", (i - 1) / 2, sum);
}
