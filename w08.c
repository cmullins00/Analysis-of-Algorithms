/*********************************************
 * Id: mull7488
 *
 * This brute force algorithm matches substrings within a string
 *********************************************/

#include<stdio.h>
#include<string.h>

char *strcpy(char *dest, const char *src);
void BruteForceStringMatch(int n, int m, char T[], char P[]);

int main(int argc, char *argv[])
{
   if(argc != 3)
   {
      printf("./a.out abc abcacacbbabcbacabcbacbabc\n");
      return 0;
   } // Check the number of arguments

   char needle[100];
   char haystack[100]; 

   strcpy(needle, argv[1]);
   strcpy(haystack, argv[2]);

   //printf("T: %c\n", needle[0]);

   int i;
   int n = 0;
   int m = 0;
   for (i = 0; needle[i] != '\0'; i++)
   {
      n += 1;
   }

   for (i = 0; haystack[i] != '\0'; i++)
   {
      m += 1;
   }

   printf("Matches found at locations:");
   BruteForceStringMatch(n, m, needle, haystack);
   printf("\n");

   return 0;
}


// Will look through list P and find substrings that match T
void BruteForceStringMatch(int n, int m, char needle[], char haystack[])
{
   int i, j;
   for (i = 0; i < m-n+1; i++)
   {
      j = 0;
      while (j < m && haystack[i+j] == needle[j])
      {
         j += 1;
         if (j == n)
         {
            printf(" %d", i);
         }
      }
   }
   return;
}
