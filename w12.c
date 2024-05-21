/*********************************************
 * Id: mull7488
 *
 * This program runs 3 sorting algorithms to see which has the best time
 *********************************************/

#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>

int atoi(const char *str);

void selectionSort(int n, int A[n]);

void quickSort(int A[], int low, int high);
int partition(int *A, int low, int high);
void swap(int *x, int *y);

void insertionSort(int *A, int n);
int binarySearch(int *A, int item, int low, int high);

int main()
{
   struct timeval start, stop;
   double select1Time, select2Time, select3Time;
   double insert1Time, insert2Time, insert3Time;
   double quick1Time, quick2Time, quick3Time;
   int i, newvalue;

   srand (time(NULL));

   //Set numbers here
   int s1 = 1000;
   int s2 = 10000;
   int s3 = 100000;

   int list1[s1];
   int list2[s2];
   int list3[s3];

   //***********************************************************************************************************
   //Selection Sort

   for (i = 0; i < s1; i++)
   {
      newvalue = rand() % 10;
      list1[i] = newvalue;
   }

   for (i = 0; i < s2; i++)
   {
      newvalue = rand() % 10;
      list2[i] = newvalue;
   }

   for (i = 0; i < s3; i++)
   {
      newvalue = rand() % 10;
      list3[i] = newvalue;
   }

   gettimeofday(&start, NULL);

   //Run code here
   selectionSort(s1, list1);

   gettimeofday(&stop, NULL);
   select1Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);

   //Run code here
   selectionSort(s2, list2);

   gettimeofday(&stop, NULL);
   select2Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);

   //Run code here
   selectionSort(s3, list3);

   gettimeofday(&stop, NULL);
   select3Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   //***********************************************************************************************************
   //Insert Sort

   for (i = 0; i < s1; i++)
   {
      newvalue = rand() % 10;
      list1[i] = newvalue;
   }

   for (i = 0; i < s2; i++)
   {
      newvalue = rand() % 10;
      list2[i] = newvalue;
   }

   for (i = 0; i < s3; i++)
   {
      newvalue = rand() % 10;
      list3[i] = newvalue;
   }

   gettimeofday(&start, NULL);

   //Run code here
   insertionSort(list1, s1-1);

   gettimeofday(&stop, NULL);
   insert1Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);

   //Run code here
   insertionSort(list2, s2-1);

   gettimeofday(&stop, NULL);
   insert2Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);

   //Run code here
   insertionSort(list3, s3-1);

   gettimeofday(&stop, NULL);
   insert3Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   //***********************************************************************************************************
   //Quick Sort

   for (i = 0; i < s1; i++)
   {
      newvalue = rand() % 10;
      list1[i] = newvalue;
   }

   for (i = 0; i < s2; i++)
   {
      newvalue = rand() % 10;
      list2[i] = newvalue;
   }

   for (i = 0; i < s3; i++)
   {
      newvalue = rand() % 10;
      list3[i] = newvalue;
   }

   gettimeofday(&start, NULL);

   //Run code here
   quickSort(list1, 0, s1-1);

   gettimeofday(&stop, NULL);
   quick1Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);

   //Run code here
   quickSort(list2, 0, s2-1);

   gettimeofday(&stop, NULL);
   quick2Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   gettimeofday(&start, NULL);

   //Run code here
   quickSort(list3, 0, s3-1);

   gettimeofday(&stop, NULL);
   quick3Time = (double)(stop.tv_sec - start.tv_sec) * 1000 + (double)(stop.tv_usec - start.tv_usec) / 1000;

   //***********************************************************************************************************

   //Print the results here
   printf("//+-----------------------+-----------------+----------------+------------+\n");
   printf("//|    Number of Elements |  Selection Sort | Insertion sort |  Quicksort |\n");
   printf("//+-----------------------+-----------------+----------------+------------+\n");
   printf("//|                   1000|                %d|               %d|           %d|\n", (int)select1Time, (int)insert1Time, (int)quick1Time);
   printf("//|                  10000|              %d|              %d|          %d|\n", (int)select2Time, (int)insert2Time, (int)quick2Time);
   printf("//|                 100000|            %d|            %d|        %d|\n", (int)select3Time, (int)insert3Time, (int)quick3Time);
   printf("//+-----------------------+-----------------+----------------+------------+\n");

   return 0;
}

//============================= FUNCTIONS ====================================

// Inputs a string of numbers, sorts the numbers using the selection sort algorithm
void selectionSort(int n, int A[n])
{
   int min, temp, j;
   int i = 0;

   //For loop that separates the sorted portion of the array from the unsorted
   for (i = 0; i < n-1; i++)
   {
      //Min is set to the first value
      min = i;

      //For loop that checks through the list of unsorted numbers
      for (j = i+1; j < n; j++)
      {
         //Finds the smallest number in the unsorted half
         if (A[j] < A[min])
         {
            min = j;
         }
      }

      //Put the next smallest number at the end of the sorted portion
      temp = A[min];
      A[min] = A[i];
      A[i] = temp;
   }
}

// Partition the array using the last element as the pivot
int partition(int *A, int low, int high)
{
   int pivot = A[high];
   int i = (low - 1);
   int j;  

   for (j = low; j <= high - 1; j++)
   {
      if (A[j] < pivot)
      {
         i++;
         swap(&A[i], &A[j]);
      }
   }
   swap(&A[i + 1], &A[high]);

   return (i + 1);
}

// Function to implement Quick Sort
void quickSort(int A[], int low, int high)
{
   if (low < high)
   {
      int pi = partition(A, low, high);
      quickSort(A, low, pi - 1);
      quickSort(A, pi + 1, high);
   }
}

//This function swaps two values
void swap(int *x, int *y)
{
   int temp = *x;
   *x = *y;
   *y = temp;
}

// Function to sort an array a[] of size 'n'
void insertionSort(int *A, int n)
{
   int i, loc, j, selected;
 
   for (i = 1; i < n; ++i)
   {
      j = i - 1;
      selected = A[i];
 
      // find location where selected should be inserted
      loc = binarySearch(A, selected, 0, j);
 
      // Move all elements after location to create space
      while (j >= loc)
      {
         A[j + 1] = A[j];
         j--;
      }
      A[j + 1] = selected;
   }
}

//A binary search based function to find the position for insertion in an array
int binarySearch(int *A, int item, int low, int high)
{
   if (high <= low)
   {
      return (item > A[low]) ? (low + 1) : low;
   }

   int mid = (low + high) / 2;
 
   if (item == A[mid])
   {
      return mid + 1;
   }

   if (item > A[mid])
   {
      return binarySearch(A, item, mid + 1, high);
   }
   
   return binarySearch(A, item, low, mid - 1);
}
