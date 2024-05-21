/*********************************************
 * Id: mull7488
 *
 * String matching algorithm that uses Hoorspool Matching
 *********************************************/
// C++ program to implement Quick Hull algorithm
// to find convex hull.
#include<stdio.h>
#include <stdlib.h>

int atoi(const char *str);
int abs(int x);
void free(void *ptr);
//int x = 0;

// Returns the side of point p with respect to line
// joining points p1 and p2.
int findSide(int p1[2], int p2[2], int p[2])
{
   int val = ((p[1] - p1[1]) * (p2[0] - p1[0])) -  ((p2[1] - p1[1]) * (p[0] - p1[0]));

   if (val > 0)
   {
      return 1;
   }

   if (val < 0)
   {
      return -1;
   }

   return 0;
}

// returns a value proportional to the distance
// between the point p and the line joining the
// points p1 and p2
int lineDist(int p1[2], int p2[2], int p[2])
{
   int val = ((p[1] - p1[1]) * (p2[0] - p1[0])) - ((p2[1] - p1[1]) * (p[0] - p1[0]));

   return abs(val);
}

// End points of line L are p1 and p2. side can have value
// 1 or -1 specifying each of the parts made by the line L
void quickHull(int *a[2], int n, int p1[2], int p2[2], int side, int *hull[2], int x)
{
   int ind = -1;
   int max_dist = 0;
   int i;

   // finding the point with maximum distance
   // from L and also on the specified side of L.
   for (i = 0; i < n; i++)
   {
      int temp = lineDist(p1, p2, a[i]);
      if (findSide(p1, p2, a[i]) == side && temp > max_dist)
      {
         ind = i;
         max_dist = temp;
      }
   }

   // If no point is found, add the end points
   // of L to the convex hull.
   if (ind == -1)
   {

      if (x >= n)
      {
         return;
      }
      //hull.insert(p1);
      //hull.insert(p2);
      hull[x][0] = p1[0];
      hull[x][1] = p1[1];
      x += 1;

      hull[x][0] = p2[0];
      hull[x][1] = p2[1];
      x += 1;

      return;
   }

   // Recur for the two parts divided by a[ind]
   quickHull(a, n, a[ind], p1, -findSide(a[ind], p1, p2), hull, x);
   quickHull(a, n, a[ind], p2, -findSide(a[ind], p2, p1), hull, x);
}

void printHull(int *a[2], int n, int *hull[2], int x)
{
   // a[i].second -> y-coordinate of the ith point
   if (n < 3)
   {
      printf("Convex hull not possible\n");
      return;
   }

   // Finding the point with minimum and
   // maximum x-coordinate
   int min_x = 0;
   int max_x = 0;
   int count = 0;
   int i;
   for (i = 1; i < n; i++)
   {
      if (a[i][0] < a[min_x][0])
      {
         min_x = i;
      }

      if (a[i][0] > a[max_x][0])
      {
         max_x = i;
      }

      count += 1;
   }
   // Recursively find convex hull points on
   // one side of line joining a[min_x] and
   // a[max_x]
   quickHull(a, n, a[min_x], a[max_x], 1, hull, x);

   // Recursively find convex hull points on
   // other side of line joining a[min_x] and
   // a[max_x]
   quickHull(a, n, a[min_x], a[max_x], -1, hull, x);

   printf("The points in Convex Hull are:\n");
   for (i = 0; i < count-1; i++)
   {
      printf("(%d, %d) ", hull[i][0], hull[i][1]);
   }

   printf("(%d, %d)\n", hull[count-1][0], hull[count-1][1]);
}

// Driver code
int main(int argc, char *argv[])
{
   //Check if the input is correct
   if (argc < 3 || (argc % 2 != 1))
   {
      printf("./a.out 0 3 1 1 2 2 4 4 0 0 1 2 3 1 3 3\n");
      return -1;
   }

   int n = (argc-1)/2;

   int *a[n];
   int *hull[n];

   int i;
   int x = 0;

   for (i = 0; i < n; i++)
   {
      a[i] = (int*)malloc(2 * sizeof(int));
      hull[i] = (int*)malloc(2 * sizeof(int));
   }
   int k = 1;
   int count = 0;

   //Assign values to the array of pairs
   for (i = 0; i < n; i++)
   {
      a[i][0] = atoi(argv[k]);
      k += 1;

      a[i][1] = atoi(argv[k]);
      k += 1;
      count += 1;
   }

   printf("The points that exist are:\n");
   for (i = 0; i < n-1; i++)
   {
      printf("(%d, %d) ", a[i][0], a[i][1]);
   }

   printf("(%d, %d)\n", a[count-1][0], a[count-1][1]);

   //int n = sizeof(a)/sizeof(a[0]);
   printHull(a, n, hull, x);

   /*
   for (i = 0; i < argc-1/2; i++)
   {
      free(a[i]);
      free(hull[i]);
   }
   */

   free(*a);
   free(*hull);
   
   return 0;
}

