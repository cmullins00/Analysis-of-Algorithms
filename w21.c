/*********************************************
 * Id: mull7488
 *
 * This recursive algorithm prints out all possible
 * permutations for a given integer n.
 *********************************************/

#include<stdio.h>

int atoi(const char *str);
void swap(int *x, int *y);
void permutations(int *arr, int start, int end);

int main(int argc, char *argv[])
{
   if(argc != 2)
   {
      printf("./a.out 3\n");
      return 0;
   }

   int n = atoi(argv[1]);

   int arr[n];
   int i;

   for(i = 0; i < n; i++)
   {
      arr[i] = i + 1;
   }

   permutations(arr, 0, n-1);

   return 0;
}

// Swaps the value of two given integers
void swap(int *x, int *y) 
{ 
   char temp; 
   temp = *x; 
   *x = *y; 
   *y = temp; 
}

// Recursive function that finds all possible permutations for a given array
void permutations(int *arr, int start, int end)
{
   if (start == end)
   {  
      int i;
      for (i = 0; i <= end; i++)
      {
         printf("%d", arr[i]);
      }
      printf("\n");
   }
   else
   {
      int i;
      for (i = start; i <= end; i++)
      {
         swap(&arr[start], &arr[i]);
         permutations(arr, start + 1, end);
         swap(&arr[start], &arr[i]);
      }
   }
}
