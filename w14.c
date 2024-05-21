/*********************************************
 * Id: mull7488
 *
 * String matching algorithm that uses Hoorspool Matching
 *********************************************/

#include <stdio.h>
#include <string.h>

#define MAX_ALPHABET 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE 32

void printShiftTable(int table[]);
int* shiftTable(char* needle, int size);
int horspoolMatching(char* needle, char* haystack, int* table, int n);

int main(int argc, char * argv[])
{
   if (argc != 3)
   {
      printf("./a.out abc abaabcbabcbabcbabbbabcbaabbcbabcabc\n");
      return -1;
   } // Check the number of arguments

   int i;
   int n = strlen(argv[1]);
   int h = strlen(argv[2]);

   char haystack[h];
   char needle[n];

   for (i = 0; i < h; i++)
   {
      haystack[i] = argv[2][i];
   }

   for (i = 0; i < n; i++)
   {
      needle[i] = argv[1][i];
   }

   printf("Needle: %s\n", needle);
   printf("Haystack: %s\n", haystack);

   int* table = shiftTable(needle, n);

   printf("%s\n", haystack);
   int x = horspoolMatching(needle, haystack, table, h);

   if (x == -1) {
      printf("No match found.\n");
   }

   return 0;
}

//Prints the possible characters and how many characters they will shift the substring when searching
void printShiftTable(int table[])
{
   int i, start;
   for (start = MIN_WRITEABLE; start < MAX_ALPHABET; start += TABLE_ROW_LENGTH)
   {
      for (i = start; i < start + TABLE_ROW_LENGTH; i++)
      {
         printf("%c\t", i);
      }

      printf("\n");

      for (i = start; i < start + TABLE_ROW_LENGTH; i++)
      {
         printf("%d\t", table[i]);
      }
      printf("\n\n");
   }
}

//Creates a table that allows us to shift a certain number of characters when there is a mismatch
int* shiftTable(char* needle, int size)
{
   static int table[MAX_ALPHABET];
   int i, j;

   for (i = 0; i < MAX_ALPHABET; i++) {
      table[i] = size;
   }

   for (j = 0; j < size - 1; j++) {
      table[(int)needle[j]] = size - 1 - j;
   }

   printf("Shift Table:\n");
   printShiftTable(table);

   return table;
}

//Navigates through the haystack looking for the needle using the table that was created
int horspoolMatching(char* needle, char* haystack, int* table, int n)
{
   int m = strlen(needle);
   int i = m - 1;
   int matches[n];
   int matchNum = 0;
   int k;

   while (i < n)
   {
      int k = 0;
      while (k < m && needle[m - 1 - k] == haystack[i - k]) {
         k++;
      }

      if (k == m) {
         printf("%*s%s---found\n", i - m + 1, "", needle);
         matches[matchNum] = i - m + 1;
         matchNum += 1;
         //return i - m + 1;
      }
      else 
      {
         printf("%*s%s\n", i - m + 1, "", needle);
      }

      i += table[(int)haystack[i]];
   }

   //printf("No more matches found.\n");

   if (matchNum > 0)
   {
      printf("Matches found at locations: ");

      for (k = 0; k < matchNum - 1; k++)
      {
         printf("%d ", matches[k]);
      }
   
      printf("%d\n", matches[matchNum-1]);
   }

   return matchNum;
}
