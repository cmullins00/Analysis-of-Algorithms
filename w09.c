/*********************************************
 * Id: mull7488
 *
 * This program sorts an array of numbers using the selection sort algorithm
 *********************************************/

#include<stdio.h>
#include<string.h>

int atoi(const char *str);
void selectionSort(int n, int A[n]);
void printArray(int n, int A[n]);

int main(int argc, char *argv[])
{
   if(argc < 2)
   {
      printf("./a.out 41 27 3 16 4\n");
      return 0;
   } // Check the number of arguments

   int i = 1;
   int list[argc];

   while (i < argc)
   {
      list[i-1] = atoi(argv[i]);
      i++;
   }

   selectionSort(argc-1, list);

   return 0;
}

// Inputs a string of numbers, sorts the numbers using the selection sort algorithm
void selectionSort(int n, int A[n]) 
{
   int min, temp, j;
   int i = 0;

   //Prints initial array of numbers
   printArray(n, A);

   for (i = 0; i < n-1; i++)
   {
      //Min is set to the first value
      min = i;

      // Checks through the list of unsorted numbers
      for (j = i+1; j < n; j++)
      {
         if (A[j] < A[min])
         {
            min = j;
         } //Finds the smallest number in the unsorted half
      } // Checks through the list of unsorted numbers

      //Put the next smallest number at the end of the sorted portion
      temp = A[min];
      A[min] = A[i];
      A[i] = temp;

      //Print progress
      printArray(n, A);
   } // Separates the sorted portion of the array from the unsorted
}

//Prints an array of integers
void printArray(int n, int *A)
{
   int i = 0;

   while (i < n)
   {
      printf("%d ", A[i]);
      i++;
   }

   printf("\n");
}
