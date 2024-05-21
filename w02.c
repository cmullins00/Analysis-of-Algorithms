/*********************************************
 * Id: mull7488
 *
 * This program finds the smallest distance between two integers in an array 
 * using the quicksort algorithm.
 *********************************************/

#include <stdio.h>

int MinDistance(int size, int values[]);
int atoi(const char *nptr);
void qsort (void* base, size_t num, size_t size, int (*comparator)(const void*,const void*));
int cmpfunc(const void *a, const void *b);
int abs(int x);

int main(int argc, char *argv[]) {
   if (argc < 2) {
      printf("%s 4 9 3 7\n", argv[0]);
      return 0;
   } // If there are not enough arguments, then exit

   int values[argc-1];
   int i;

   for (i = 0; i < argc-1; i++) {
      values[i] = atoi(argv[i+1]);
   }

   // Use the quicksort algorithm to reorder the values
   qsort(values, argc-1, sizeof(int), cmpfunc);

   int dmin = MinDistance(argc, values);   

   printf("%d\n", dmin);

   return 0;
}

//Function that finds the smallest difference between the given values
int MinDistance(int size, int values[]) {
   int dmin = abs(values[0] - values[1]);

   int i, j;
   
   for (i = 1; i < size-1; i++) {
      for (j = i+1; j < size-1; j++) {
         if (abs(values[i] - values[j]) < dmin) {        
            dmin = abs(values[i] - values[j]);
         }
      }
   }

   return dmin;
}

//Compares two values to decide where they are ordered by quicksort
int cmpfunc(const void *a, const void *b) {
   return (*(int*)a - *(int*)b); 
} 

