/***************************************
 * Id: mull7488
 *
 * Algorithm that can be used to solve the Tower of Hanoi puzzle
 ***************************************/

#include <stdio.h>

void towerSolver(int num, char x, char y, char z);
int atoi(const char *str);

int main(int argc, char *argv[])
{
   if (argc != 2)
   {
      printf("./a.out 3\n");
      return 0;
   } // Check the number of arguments

   int numOfDisc = atoi(argv[1]);
   char tower1 = 'A', tower2 = 'B', tower3 = 'C';
   towerSolver(numOfDisc, tower1, tower2, tower3);

   return 0;
}

// Recursive algorithm that changes the order of the towers
void towerSolver(int num, char x, char y, char z)
{
   if(num > 0)
   {
      towerSolver(num - 1, x, z, y);
      printf("MOVE %c TO %c \n", x, z);
      towerSolver(num - 1, y, x, z);
   }
}
