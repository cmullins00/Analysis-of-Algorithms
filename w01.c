/*********************************************
 * Id: mull7488
 *
 * This program finds the smallest distance between two integers in an array.
 *********************************************/

#include <stdio.h>

int MinDistance(int size, int values[]);
int atoi(const char *nptr);
int abs(int x);

int main(int argc, char *argv[]) {
   if (argc < 2) {
      printf("Error: Too few arguments, try the example below.");
      printf("%s 4 9 3 7\n", argv[0]);
      return 0;
   } // If there are not enough arguments, then exit 

   int values[argc-1];
   int i;

   for (i = 0; i < argc-1; i++) {
      values[i] = atoi(argv[i+1]);
   }

   int dmin = MinDistance(argc, values);   

   printf("%d\n", dmin);

   return 0;
}

//Function that finds the smallest difference between the given values
int MinDistance(int size, int values[]) {
   int dmin = abs(values[1] - values[2]);

   int i, j;

   for (i = 0; i < size-1; i++) {
      for (j = 0; j < size-1; j++) {
         if (i != j && abs(values[i] - values[j]) < dmin) {        
            dmin = abs(values[i] - values[j]);
         }
      }
   }  

   return dmin;
}

