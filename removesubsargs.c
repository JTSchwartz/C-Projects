/*******************************************************************************
/
/      filename:  removesubsargs.c
/
/   description:  Counts the number of given substrings in a string given as arguments
/
/        author:  Schwartz, Jacob
/      login id:  FA_18_CPS356_33
/
/         class:  CPS 356
/    instructor:  Perugini
/    assignment:  Homework #2
/
/      assigned:  September 6, 2014
/           due:  September 13, 2018
/
/******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

#define MAX 4096

int main(int argc, char* argv[])
{

   char* nooverlap = malloc(sizeof(*nooverlap)*MAX);
   char overlap_flag[12] = "-nooverlap";
   int overlap = 0;

   if(argc == 4)
   {
      nooverlap = strdup(argv[3]);
      overlap = 1;
   }

   if (argc < 2 || argc >= 5 || (overlap == 1 && strcmp(nooverlap, overlap_flag) != 0))
   {
      fprintf(stderr, "Usage: string1 string2 [-nooverlap]\n");
      exit(1);
   }

   char* substring = strdup(argv[1]);
   char* string = strdup(argv[2]);
   int substringLen = strlen(substring);
   int count = 0;

   if(substring[0] == '\0')
   {
       fprintf(stderr, "Search string cannot be empty!\n");
       exit(1);
   }

   char* index = strstr(string, substring);
   size_t startLen = index - string;
   char* start = malloc(sizeof(*start)*MAX);
   char* end = index + substringLen;

   start = strndup(string, startLen);

   while(index)
   {
      count++;

      if(overlap == 0)
      {
         strncpy(string, index + 1, MAX);
         end = index + substringLen - 2;
         index = strstr(string, substring);
      } else
      {
         strncpy(string, index + substringLen, MAX);
         index = strstr(string, substring);
      }
   }

   if(overlap == 0) strncpy(string, end, MAX);

   printf("%d\n%s%s\n", count, start, string);

   exit(0);
}
