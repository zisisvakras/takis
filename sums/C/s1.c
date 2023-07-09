#include <stdio.h>
#include <math.h>

int main() { 

  /* Declaring variables */
  double pi, sum;
  long i = 1;

  /* 
  * Summing terms two at a time 
  * while alternating sign
  */
  do {
    
    sum += 1 / ((double)i * (double)i);
    i++;
    sum -= 1 / ((double)i * (double)i);  
    i++;

  } while (i < 1e+7); 

  /* 
  * Calculating pi based on the
  * proven result of the sum
  */
  pi = sqrt(12 * sum);     

  /* Printing result */
  printf("Summed %ld terms, pi is %1.16f\n", i - 1, pi);
}
