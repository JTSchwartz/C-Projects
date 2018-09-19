/*******************************************************************************
/
/      filename:  countsubsstdin.c
/
/   description:  Counts the number of given substrings in a string
/
/        author:  Schwartz, Jacob
/      login id:  FA_18_CPS356_33
/
/         class:  CPS 356
/    instructor:  Perugini
/    assignment:  Homework #1
/
/      assigned:  August 30, 2014
/           due:  September 6, 2018
/
/******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

#define MAX 4096

int main()
{
   char* string = malloc(sizeof(*string)*MAX);
   char* substring = malloc(sizeof(*substring)*MAX);
   size_t len = MAX;
   char* nooverlap = malloc(sizeof(*nooverlap)*MAX);
   char overlap_flag[12] = "-nooverlap\n";

   getline(&substring, &len, stdin);
   getline(&string, &len, stdin);

   char* eol;

   if((eol = strchr(substring, '\n')) != NULL) *eol = '\0';

   getline(&nooverlap, &len, stdin);

   int overlap = 0;

   if(strcmp(nooverlap, overlap_flag) == 0)
   {
      overlap = 1;
      fgetc(stdin);
   } else if(nooverlap[0] != '\0' && !feof(stdin))
   {
      fgetc(stdin);
      fprintf(stderr, "Usage: string1 string2 [-nooverlap]\n");
      exit(1);
   }

   if(substring[0] == '\0')
   {
       fprintf(stderr, "Search string cannot be empty!\n");
       exit(1);
   }

   int substringLen = strlen(substring);
   int count = 0;

   char* index;

   index = strstr(string, substring);

   while(index && count < 10)
   {
      count++;

      if(overlap == 0)
      {
         strncpy(string, index + 1, MAX);
         index = strstr(string, substring);
      } else
      {
         strncpy(string, index + substringLen, MAX);
         index = strstr(string, substring);
      }

   }

   printf("%d\n", count);

   exit(0);
}
