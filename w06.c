/*********************************************
 * Id: mull7488
 *
 * This iterative algorithm solves the restricted Tower of Hanoi problem
 *********************************************/

#include<stdio.h>

void push(int element, int stack[], int *top, int stackSize);
char pop(int stack[], int *top, int stackSize);
int atoi(const char *str);

int main(int argc, char *argv[]) 
{
   if(argc != 2)
   {
      printf("./a.out 3\n");
      return 0;
   } // Check the number of arguments

   int stackSize = atoi(argv[1]);

   int A[stackSize];
   int B[stackSize];
   int C[stackSize];

   // A negative index shows that the stack is empty
   int topA = -1;
   int topB = -1;
   int topC = -1;
  
   int i;
   for (i = stackSize; i > 0; i--)
   {
      push(i, A, &topA, stackSize);
      //printf("Adding %d to A[%d]\n", i, topA);
      //printf("Element on top of A: %d\n", A[topA]);
   } // Place all rings on the first tower
   
   while(topC != 0)
   {
      //Move 1 from A to C
      push(pop(A, &topA, stackSize), B, &topB, stackSize);
      printf("MOVE A TO B\n");

      push(pop(B, &topB, stackSize), C, &topC, stackSize);
      printf("MOVE B TO C\n");
      
      //Check if puzzle is complete
      if (topC == 0)
      {
         break;
      }

      //printf("A[topA]: %d\n", A[topA]);
      //printf("B[topB]: %d\n", B[topB]);
      //printf("C[topC]: %d\n", C[topC]);

      if (((A[topA] < B[topB]) && (topA != -1)) || topB == -1)  //If the disc on top of A is smaller than B
      {
         push(pop(A, &topA, stackSize), B, &topB, stackSize);
         printf("MOVE A TO B\n");
      } //Move a disc from A to B
      else
      {
         push(pop(B, &topB, stackSize), A, &topA, stackSize);
         printf("MOVE B TO A\n");
      } //Otherwise, move a disc from B to A

      //Move a disc from C to A
      push(pop(C, &topC, stackSize), B, &topB, stackSize);
      printf("MOVE C TO B\n");

      push(pop(B, &topB, stackSize), A, &topA, stackSize);
      printf("MOVE B TO A\n");

      if (((B[topB] < C[topC]) && (topB != -1)) || topC == -1)  //If the value on top of B is smaller than C
      {
         
         push(pop(B, &topB, stackSize), C, &topC, stackSize);
         printf("MOVE B TO C\n");
      } //Move a disc from B to C
      else
      {
         push(pop(C, &topC, stackSize), B, &topB, stackSize);
         printf("MOVE C TO B\n");  
      } //Otherwise, move a disc from C to B
   }

   return 0;
}

//Pushes an integer onto the end of a stack(array)
void push(int element, int *stack, int *top, int stackSize)
{
   if(*top == -1)
   {
      stack[stackSize - 1] = element;
      *top = stackSize - 1;
   } // If the stack is empty...
   else if(*top == 0)
   {
      printf("The stack is already full. \n");
   } // If the stack is full...
   else
   {
      stack[(*top) - 1] = element;
      (*top)--;
   } // Place disc onto stack
}

//Removes the top integer off of stack(array)
char pop(int *stack, int *top, int stackSize)
{
   if(*top == -1)
   {
      printf("The stack is empty. \n");
      return 0;
   } // If the stack is empty...
   else
   {
      char temp = stack[(*top)];

      // If the element popped was the last element in the stack
      // then set top to -1 to show that the stack is empty
      if((*top) == stackSize - 1)
      {
         (*top) = -1;
      }
      else
      {
         (*top)++;
      }

      return temp;
   } 
}
