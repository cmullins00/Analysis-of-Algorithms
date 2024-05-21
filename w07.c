/*********************************************
 * Id: mull7488
 *
 * This iterative algorithm solves the cyclic Tower of Hanoi problem
 *********************************************/

#include<stdio.h>

int atoi(const char *str);
void recursion(int n, char A, char B, char C);

int main(int argc, char *argv[])
{
   if(argc != 2)
   {
      printf("./a.out 3\n");
      return 0;
   }

   int n = atoi(argv[1]);
   char tower1 = 'A';
   char tower2 = 'B';
   char tower3 = 'C';

   recursion(n, tower1, tower2, tower3);

   return 0;
}

// Rearranges the towers to solve the cyclic Tower of Hanoi problem
void recursion(int n, char x, char y, char z)
{
   if(n > 0)
   {
      recursion(n - 1, x, y, z);
      printf("MOVE %c TO %c \n", x, y);

      recursion(n - 1, z, x, y);

      recursion(n - 1, y, z, x);
      printf("MOVE %c TO %c \n", y, z);

      recursion(n - 1, x, y, z);
   }

   return;
}
