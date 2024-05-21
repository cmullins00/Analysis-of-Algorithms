/*********************************************
 * Id: mull7488
 *
 * This program sorts a given array by insertion sort
 *********************************************/

#include <stdio.h>

int atoi(const char *str);
void insertionSort(int n, int *A);
void printArray(int n, int d, int *A);

int main(int argc, char *argv[])
{
   if (argc < 2)
   {
      printf("./a.out 4 1 6 3 5");
   } // Check the number of arguments

   int A[argc-1], i;

   for (i = 0; i < argc-1; i++)
   {
      A[i] = atoi(argv[i+1]);
   }

   insertionSort(argc-2, A);

   return 0;
}

//Takes an array and sorts it using the insertion sort algorithm
void insertionSort(int n, int *A)
{
   int i, v, j;
   int d = 1;

   printArray(n, d, A);

   for (i = 1; i <= n; i++)
   {
      v = A[i];
      j = i-1;

      while (j >= 0 && A[j] > v)
      {
         A[j+1] = A[j];
         j = j-1;
      }
      A[j+1] = v;

      d++;
      printArray(n, d, A);
   }
}

//Prints an array and separates the sorted from the unsorted with a bar
void printArray(int n, int d, int *A)
{
   int i;
   for (i = 0; i < n; i++)
   {
      if (i == d-1)
      {
         printf("%d | ", A[i]);
      }
      else
      {
         printf("%d ", A[i]);
      }
   }

   if (d-1 == n)
   {
      printf("%d | \n", A[i]);
   }
   else
   {
      printf("%d \n", A[i]);
   }
}
