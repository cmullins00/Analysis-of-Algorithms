/*********************************************
 * Id: mull7488
 *
 * This program completes russian peasant multiplication on two given ints
 *********************************************/

#include <stdio.h>

double atof(const char *str);
double floor(double x);

int main(int argc, char *argv[])
{
   if (argc != 3)
   {
      printf("./a.out 50 65\n");
      return 0;
   } // Check the number of arguments

   int total = 0;

   double x = atof(argv[1]);
   double y = atof(argv[2]);

   if (((int)x % 2) == 1)
   {
      printf("%6d %6d %6d\n", (int)x, (int)y, (int)y);
      total += y;
   }
   else
   {
      printf("%6d %6d\n", (int)x, (int)y);
   }

   while ((int) floor(x) != 1)
   {
      x = (int)floor(x/2);
      y = y * 2;

      if (((int)x % 2) == 1)
      {
         printf("%6d %6d %6d\n", (int)x, (int)y, (int)y);
         total += y;
      }
      else
      {
         printf("%6d %6d\n", (int)x, (int)y);
      }
   }

   printf("%20s\n", "------");
   printf("%20d\n", total);
   
   return 0;
}

//Rounds down a given float
double floor(double x)
{
   int y = (int)x;
   y = x-y;  

   x = x-y;

   return x;
}
