/*********************************************
 * Id: mull7488
 *
 * This algorithm traverses a 2D matrix to find the optimal route that gives the most coins
 * The first two values represent the shape of the matrix, and the X's act as walls
 *********************************************/

#include <stdio.h>
#include <string.h>

int atoi(const char *str);
char *strcpy(char *dest, const char *src);
int strcmp (const char* str1, const char* str2);
int max(int x, int y);
int coinCollection(int n, int m, int A[n][m]);

// Main driver code
int main(int argc, char *argv[])
{
   if (argc < 4)
   {
      printf(" ./a.out 5 6 0 X 0 1 0 0 1 0 0 X 1 0 0 1 0 X 1 0 0 0 0 1 0 1 X X X 0 1 0\n");
      return -1;
   }

   int r = atoi(argv[1]);
   int c = atoi(argv[2]);

   int A[r][c];
   int i, j, total;
   int count = 3;

   // Go through the entire board and change all X's to -1
   for (i = 0; i < r; i++)
   {
      for (j = 0; j < c; j++)
      {
         //A[i][j] = argv[count];
         if (strcmp(argv[count], "X") == 0)
         {
            A[i][j] = -1;
            //printf("X       ");
         }
         else
         {
            A[i][j] = atoi(argv[count]);
         }
         count += 1;
      }
   }

   printf("Board Inputed:\n");
   for (i = 0; i < r; i++)
   {
      for (j = 0; j < c; j++)
      {
         if (A[i][j] >= 0)
         {
            printf("%d\t", A[i][j]);
         }
         else
         {
            printf("X\t");
         }
      }
      printf("\n");
   }

   printf("\n");

   total = coinCollection(r, c, A);  

   printf("The optimal path with this board is: %d\n", total);

   return 0;
}

// Returns the max of two given values
int max(int x, int y)
{
   return (x > y)? x : y;
}

/*
// Traverses a matrix and finds all possible routes and max coins that can be collected per route
int coinCollection(int n, int m, int A[n][m])
{
   //F[1, 1]←C[1, 1];
   int temp[n][m];
   int i, j;

   memset(temp, 0, sizeof(temp));

   temp[0][0] = A[0][0];
   //printf("S: temp[0][0] = %d\n", temp[0][0]);

   //for j ←2 to m do
   //   F[1, j]←F[1, j − 1]+ C[1, j]
   for (j = 1; j < m; j++)
   {
      if (A[0][j] >= 0)
      {
         temp[0][j] = (temp[0][j-1] + A[0][j]);
         printf("1: %d + %d = %d\n", temp[0][j-1], A[0][j], temp[0][j-1] + A[0][j]);
         printf("1: temp[0][%d] = %d\n", j, temp[0][j]);
      }
      else
      {
         temp[0][j] = -1;
         printf("1: temp[0][%d] = %d\n", j, temp[0][j]);
      }

      //for i ←2 to n do
      //   F[i, 1]←F[i − 1, 1]+ C[i, 1]
      for (i = 1; i < n; i++)
      {
         if (A[i][0] >= 0)
         {
            temp[i][0] = (temp[i-1][0] + A[i][0]);
            //printf("2: temp[%d][0] = %d\n", i, temp[i][0]);
         }
         else
         {
            temp[i][0] = -1;
            //printf("2: temp[%d][0] = %d\n", i, temp[i][0]);
         }

         //for j ←2 to m do
         //   F[i, j ]←max(F [i − 1, j], F[i, j − 1]) + C[i, j ]
         for (j = 1; j < m; j++)
         {
            //printf("Max between %d and %d. A = %d\n", temp[i-1][j], temp[i][j-1], A[i-1][j-1]);
            if (A[i][j] >= 0)
            {
               temp[i][j] = max(temp[i-1][j], temp[i][j-1]) + A[i][j];
               //printf("3: temp[%d][%d] = %d\n", i, j, temp[i][j]);
            }
            else
            {
               temp[i][j] = -1;
               //printf("3: temp[%d][%d] = %d\n", i, j, temp[i][j]);
            }
         }
      }
   }

   printf("Coin Collecting Table:\n");
   for (i = 0; i < n; i++)
   {
      for (j = 0; j < m; j++)
      {
         if (temp[i][j] >= 0)
         {
            printf("%d\t", temp[i][j]);
         }
         else
         {
            printf("0\t");
         }
      }
      printf("\n");
   }

   printf("\n");

   return temp[n-1][m-1];
}
*/

/*
// Traverses a matrix and finds all possible routes and max coins that can be collected per route
int coinCollection(int n, int m, int A[n][m])
{
   //F[1, 1]←C[1, 1];
   int temp[n][m];
   int i, j;

   // Fill the matrix with 0s
   memset(temp, 0, sizeof(temp));

   // Start in the top left corner
   temp[0][0] = A[0][0];
   //printf("S: temp[0][0] = %d\n", temp[0][0]);

   //for j←2 to m do
   //   F[1, j]←F[1, j − 1]+ C[1, j]
   for (j = 1; j < m; j++)
   {
      if (A[0][j] >= 0)
      {
         temp[0][j] = (temp[0][j-1] + A[0][j]);
         //printf("1: %d + %d = %d\n", temp[0][j-1], A[0][j], temp[0][j-1] + A[0][j]);
         //printf("1: temp[0][%d] = %d\n", j, temp[0][j]);
      }
      else
      {
         temp[0][j] = -1;
         //printf("1: temp[0][%d] = %d\n", j, temp[0][j]);
      }

      //for i←2 to n do
      //   F[i, 1]←F[i − 1, 1]+ C[i, 1]
      for (i = 1; i < n; i++)
      {
         if (A[i][0] >= 0)
         {
            temp[i][0] = (temp[i-1][0] + A[i][0]);
            //printf("2: temp[%d][0] = %d\n", i, temp[i][0]);
         }
         else
         {
            temp[i][0] = -1;
            //printf("2: temp[%d][0] = %d\n", i, temp[i][0]);
         }

         //for j ←2 to m do
         //   F[i, j ]←max(F [i − 1, j], F[i, j − 1]) + C[i, j ]
         for (j = 1; j < m; j++)
         {
            //printf("Max between %d and %d. A = %d\n", temp[i-1][j], temp[i][j-1], A[i-1][j-1]);
            if (A[i][j] >= 0)
            {
               temp[i][j] = max(temp[i-1][j], temp[i][j-1]) + A[i][j];
               //printf("3: temp[%d][%d] = %d\n", i, j, temp[i][j]);
            }
            else
            {
               temp[i][j] = -1;
               //printf("3: temp[%d][%d] = %d\n", i, j, temp[i][j]);
            }
         }
      }
   }

   printf("Coin Collecting Table:\n");
   for (i = 0; i < n; i++)
   {
      for (j = 0; j < m; j++)
      {
         if (temp[i][j] >= 0)
         {
            printf("%d\t", temp[i][j]);
         }
         else
         {
            printf("X\t");
         }
      }
      printf("\n");
   }
   
   printf("\n");

   return temp[n-1][m-1];
}
*/

// Traverses a matrix and finds all possible routes and max coins that can be collected per route
int coinCollection(int n, int m, int A[n][m])
{
   //F[1, 1]←C[1, 1];
   int temp[n][m];
   int i = 0, j = 0, k = 0;

   // Fill the matrix with 0s
   memset(temp, 0, sizeof(temp));

   // Start in the top left corner
   //temp[0][0] = A[0][0];

   // Loop that goes down the matrix
   for (i = 0; i < n; i++)
   {
      // Loop that goes from left to right
      for (j = 0; j < m; j++)
      {
         if (i + j == 0)
         {
            temp[i][j] = A[i][j];
         } // If we are at the start...
         else if (A[i][j] >= 0)
         {
            // If we are at A[i][0] where i > 0, then get we can only look at the value at A[i-1][0]
            if (j == 0)
            {
               temp[i][j] = (temp[i-1][j] + A[i][j]);
            }
            // If we are at A[0][j] where j > 0, then get we can only look at the value at A[0][j-1]
            else if (i == 0)
            {
               temp[i][j] = (temp[i][j-1] + A[i][j]);
            }
            else
            {
               temp[i][j] = max(temp[i-1][j], temp[i][j-1]) + A[i][j];
            }

            // Loop that goes down again
            for (k = i+1; k < m; k++)
            {
               if (A[k][j] >= 0)
               {
                  // Make sure we are not overwriting temp[k][j] with a worse value
                  temp[k][j] = max((max(temp[k-1][j], temp[k][j-1]) + A[k][j]), temp[k][j]);
               }
               else
               {
                  temp[k][j] = -1;
                  break;
               }
            }
         } // If we are not at an X (a wall)...
         else
         {
            temp[i][j] = -1;
            j += m;
         } // If we are at an X (a wall)...
      }
   }

   printf("Coin Collecting Table:\n");
   for (i = 0; i < n; i++)
   {
      for (j = 0; j < m; j++)
      {
         if (temp[i][j] >= 0)
         {
            printf("%d\t", temp[i][j]);
         }
         else
         {
            printf("X\t");
         }
      }
      printf("\n");
   }

   printf("\n");

   return temp[n-1][m-1];
}
