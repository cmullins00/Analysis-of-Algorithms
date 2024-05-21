/*************************************
 * Id: mull7488
 *
 * Algorithm for solving a system of linear equations
 *************************************/

#include <stdio.h>
#include <stdlib.h>

void printMatrix(int n, float values[n][n+1]);

int main(int argc, char *argv[])
{
   if (argc < 2) 
   {
      printf("%s 3 1 2 3 4 5 6 7 8 9 10 11 12\n", argv[0]);
      return 0;
   } // Makes sure there are enough arguments

   int numEquations = atoi(argv[1]);   // First value is used for number of rows and columns

   float values[numEquations][numEquations+1]; // Stores the values passed in as input
   int i = 0;
   int j = 0;
   int k = 0;
   float tempji = 0;

   for (i = 0; i < numEquations; i++) 
   {
      for (j = 0; j < numEquations+1; j++)
      {
         values[i][j] = atof(argv[k+2]);
         k++;
      }
   } // Converts ints to floats and stores it in matrix shape specified by numEquations

   printMatrix(numEquations, values);

   for (i = 0; i <= numEquations-2; i++) 
   {
      for (j = i+1; j <= numEquations-1; j++) 
      {
         tempji = values[j][i];

         for (k = i; k <= numEquations; k++)
         {
            values[j][k] = values[j][k] - (values[i][k] * tempji / values[i][i]);
         }
      }

      printMatrix(numEquations, values);
   }

   return 0;
}

//Prints a 2D array in a matrix format that is n values tall and n+1 values wide
void printMatrix(int n, float values[n][n+1])
{
   int i = 0;
   int j = 0;

   for (i = 0; i < n; i++) // Prints all values in a 2D matrix
   {
      for (j = 0; j < n+1; j++)
      {
         printf("%.2f ", values[i][j]);
      }

      printf("\n");
   }

   printf("\n");
}

