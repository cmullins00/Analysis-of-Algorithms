/*********************************************
 * Id: mull7488
 *
 * This program sorts an array of integers using quicksort and Hoare partitioning for greater efficiency
 *********************************************/

#include <stdio.h>

int atoi(const char *str);
int HoarePartition(int l, int r, int *A);
void quickSort(int l, int r, int n, int *A);
void printArray(int l, int r, int n, int *A);
void printSubArray(int l, int r, int *A);
void swap(int *x, int *y);

int main(int argc, char *argv[])
{
   if (argc < 2)
   {
      printf("./a.out 46 24 26 12 5");
      return 0;
   } // Check the number of arguments

   int i = 0;
   int list[argc-1];

   
   while (i < argc-1)
   {
      list[i] = atoi(argv[i+1]);
      i++;
   } // Set up the list

   quickSort(0, argc-2, argc-1, list);

   printArray(0, argc-2, argc-1, list);  
   return 0;
}

//This function recursively sorts an array of integers using the quicksort algorithm
void quickSort(int left, int right, int n, int A[r-l])
{
   int s;

   if (left < right)
   {
      s = HoarePartition(left, right, A);

      quickSort(left, s-1, n, A);
      quickSort(s+1, right, n, A);

      printArray(left, right, n, A);
   }
}

//This function finds the midpoint of a substring
int HoarePartition(int left, int right, int *A)
{
   int p = A[left];
   int i = left;
   int j = r+1;

   do
   {
      do
      {
         i++;
      } while (A[i] < p);

      do
      {
         j--;
      } while (A[j] > p);
      
      // Swap A[i] and A[j]
      swap(&A[i], &A[j]);
   } while (i < j);

   //Undo the last swap
   swap(&A[i], &A[j]);

   //Swap A[left] and A[j]
   swap(&A[left], &A[j]);

   return j;  
}

//This function prints the entire array with a subsection in brackets
void printArray(int left, int right, int n, int *A)
{
   int i;
   for (i = 0; i < n; i++)
   {
      if (i == left)
      {
         printSubArray(left, right, A);
         i = right;
      }
      else
      {
         printf("%d ", A[i]);
      }
   }
   printf("\n");
}

//This function prints a subsection of an int array in brackets
void printSubArray(int left, int right, int *A)
{

   printf("[");

   while (left < right)
   {
      printf("%d ", A[left]);
      left++;
   }

   printf("%d]  ", A[right]);
}

//This function swaps two values
void swap(int *x, int *y)
{
   int temp = *x;
   *x = *y;
   *y = temp;
}
