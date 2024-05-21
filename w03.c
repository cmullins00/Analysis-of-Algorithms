/*****************************************
 * Id: mull7488
 *
 * Recursive algorithm for computing 2^n in the least efficient way I can think of
 *****************************************/

#include <stdio.h>
#include <stdlib.h>

int recursion(int n);

int main(int argc, char *argv[])
{
   int value;
   int total;

   if (argc != 2)
   {
      printf("%s 9\n", argv[0]);
      return 0;
   }

   value = atof(argv[1]);

   if (value < 1)
   {
      printf("Input: %d\n", value);
      printf("Input must be a number greater than 0!\n");
      return 0;
   }

   total = recursion(value);
   printf("%d\n", total);  

   return 0;
}

//Recursively calculates 2^(n-1) + 2^(n-1)
int recursion(int n)
{
   if (n < 1)
   {
      return 1;
   }

   return recursion(n-1) + recursion(n-1);
}

//2^n = 2^(n-1) + 2^(n-1)
