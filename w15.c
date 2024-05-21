/*********************************************
 * Id: mull7488
 *
 * Creates a bad and good shift table for string pattern matching
 *********************************************/

# include <limits.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

#define NO_OF_CHARS 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE 32

int strcmp (const char* String1, const char* String2);
void printShiftTable(int table[]);
int* badShiftTable(char* needle, int size);
void createGoodShiftTable(char *pattern, int **goodShiftTable);
void search( char *txt, char *pat);
int max (int a, int b);

// Driver program to test above function
int main(int argc, char * argv[])
{
   if (argc != 3)
   {
      printf("./a.out baobab bess_knew_about_baobabs\n");
      return -1;
   } // Check the number of arguments

   char *pat = argv[1];
   char *txt = argv[2];

   search(txt, pat);

   return 0;
}

// Used to print the bad shift table
void printShiftTable(int table[])
{
   int i, start;
   for(start = MIN_WRITEABLE; start < NO_OF_CHARS; start += TABLE_ROW_LENGTH)
   {
      for(i = start; i < start + TABLE_ROW_LENGTH; i++)
      {
         printf("%c\t", i);
      }
      printf("\n");

      for(i = start; i < start + TABLE_ROW_LENGTH; i++)
      {
         printf("%d\t", table[i]);
      }
      printf("\n\n");

   }
}

// The preproccessor for the bad shift table
int* badShiftTable(char* needle, int size)
{
   static int table[NO_OF_CHARS];
   int i;

   for (i = 0; i < NO_OF_CHARS; i++) {
      table[i] = size;
   }

   for (i = 0; i < size - 1; i++) {
      table[(int)needle[i]] = size - 1 - i;
   }

   printf("Shift Table:\n");
   printShiftTable(table);

   return table;
}

// Creates a good shift table using the pattern
void createGoodShiftTable(char *pattern, int **goodShiftTable)
{
   // i is the stopping point for pattern checking
   int i, j, n = strlen(pattern)-1;
 
   *goodShiftTable = malloc(n * sizeof(int));

   char preceeding;
   int subPat;
   //int x;
   int test, check;

   // Start at end of pattern. Add a letter with each iteration. This is each iteration of the good shift table. Last iteration not needed.
   for (i = n; i > 0; i--)
   {
      // Character preceeding our sub-pattern
      preceeding = pattern[i-1];
      check = 0;

      /*
      printf("Looking at ");
      for (x = n; x >= i; x--)
      {
         printf("%c", pattern[x]);
      }
      printf("\n");
      */

      // This is checking for matches during each iteration. This needs to be able to go to the end of the string. Starts at n-1 since it shouldn't match the same character to itself
      for (j = n - 1; j >= 0; j--)
      {
         //printf("pattern iteration: %d\n", j);
         subPat = n-1;
         test = j-1;

         // If the last letter in the pattern matches somewhere...
         if (pattern[j] == pattern[n])
         {
            //printf("Found a matching letter\n");
            // Case where only one character is being matched
            if (i == n && preceeding != pattern[j-1])
            {
               //printf("Yay! First character successfully matched\n");
               (*goodShiftTable)[i] = n-j;
               break;
            }

            //printf("1. checking %c and %c... test = %d\n", pattern[subPat], pattern[test], test);

            // If we are not looking at just one character, then we need to check the other characters too
            while (pattern[subPat] == pattern[test] && subPat >= i)
            {
               //printf("2. checking %c and %c. Things still match...\n", pattern[subPat], pattern[test]);
               if (test == 0)
               {
                  //printf("Found a partial match at the end of the pattern!\n");
                  (*goodShiftTable)[i] = j+1;
                  check = 1;
                  break;
               }

               test -= 1;
               subPat -= 1;

            }
            if (check == 1)
            {
               break;
            }

            if (pattern[subPat] == pattern[test] && test-1 >= 0 && preceeding != pattern[test-1])
            {
               //printf("Successfully found a match at %d! %c and %c\n", test, pattern[subPat], pattern[test]);
               (*goodShiftTable)[i] = n-j;
               break;
            }
         }

         // If at the end of the string and no match is found
         if (j <= 0 && pattern[j] == pattern[n])
         {
            //printf("No luck! Shifting by %d (len(pat)-1 because of match at end)\n", n);
            (*goodShiftTable)[i] = n;
            break;
         }
         else if (j <= 0 && pattern[j] != pattern[n])
         {
            //printf("No luck! Shifting by %d (len(pat) because no match at end)\n", n+1);
            (*goodShiftTable)[i] = n+1;
            break;
         }
      }
   }
}

// A pattern searching function that uses the Bad and Good Character Heuristic of the Boyer Moore Algorithm
void search(char *txt, char *pat)
{
   int patLen = strlen(pat) - 1;
   int txtLen = strlen(txt) - 1;

   // Create the bad shift table
   int *badchar = badShiftTable(pat, patLen + 1);

   // Create the good shift table
   int *goodchar;
   createGoodShiftTable(pat, &goodchar);

   // Shift is shift of the pattern with respect to text, j is as an index for pattern
   int j, shift = 0;

   // Print the good shift table
   int i, temp = patLen;
   for(i = 0; i < patLen; i++)
   {
      printf("%d %*s %d\n", i+1, patLen+1, &pat[patLen-i], goodchar[temp]);
      temp -= 1;
   }

   int matches[txtLen];
   int matchIndex = 0;

   // Prints the entire text
   printf("%s\n", txt);

   // Loop to look for pattern in text 
   while(shift <= (txtLen - patLen))
   {
      j = patLen;
      temp = 0;

      // Keep reducing index j of pattern while characters of pattern and text are matching at this shift s
      while(j >= 0 && pat[j] == txt[shift+j])
      {
         j--;
         temp++;
      }

      // If the pattern is present at current shift, then index j will become -1 after the above loop
      if (j < 0)
      {
         // Shift the pattern by patLen if a match is found && not at the end of txt
         printf("%*s%s---found\n", shift, "", pat);
         matches[matchIndex] = shift;
         matchIndex += 1;
         shift += (shift + patLen < txtLen)? patLen : 1;
      }

      // If the pattern doesn't match at all, then shift by the true pattern length or 1 if at the end of the text
      else if (j == patLen && (shift + patLen < txtLen))
      {
         printf("%*s%s\n", shift, "", pat);
         shift += (shift + patLen+1 < txtLen)? patLen+1 : 1;
      }

      // If part of the pattern matches, then shift as far as the good or bad tables allow
      else
      {
         int d1 = badchar[(int)txt[shift + j]] - temp;
         int d2 = goodchar[j+1];

         if (shift > 0)
         {
            printf("%*s%s d1=%d d2=%d\n", shift, "", pat, d1, d2);
         }

         shift += max(max(d1, d2), 1);
      }
   }

   j = patLen;
   
   // Looking for the pattern again??
   while(j >= 0 && pat[j] == txt[shift + j])
   {
      j--;
   }

   if (j < 0)
   {
      // Shift the pattern by patLen if a match is found & not at the end of txt
      // If (Condition == true) ? then value X : otherwise value Y
      printf("%*s%s---found\n", shift, "", pat);
      matches[matchIndex] = shift;
      matchIndex++;
      //s += (s+m < n)? m : 1;
   }
   else
   {
      // Check at the end of the text here
      printf("%*s%s\n", txtLen-patLen, "", pat);
   }

   //printf("matchIndex: %d\n", matchIndex);

   if (matchIndex > 0)
   {
      printf("Matches found at locations: %d", matches[0]);
      for (i = 1; i < matchIndex; i++)
      {
         printf(" %d", matches[i]);
      }
      printf("\n");
   }
   free(goodchar);
}

// Returns the max of two integers
int max (int a, int b)
{ 
   return (a > b)? a: b; 
}
