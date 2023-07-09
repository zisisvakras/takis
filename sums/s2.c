#include <stdio.h>

int main() { 

  /* Declaring variables */
  double ln2;
  long i = 1;

  /* 
  * Summing terms two at a time 
  * while alternating sign
  */
  do {
    
    ln2 += 1 / (double)i;
    i++;
    ln2 -= 1 / (double)i;  
    i++;

  } while (i < 1e+9); 

  /* Printing result */
  printf("Summed %ld terms, ln2 is %1.16f\n", i - 1, ln2);
}
