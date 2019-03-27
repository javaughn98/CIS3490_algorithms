#include "header.h"


 int shift = 0;

/*
  this function takes two strings and search for the pattern in the text
*/

int bruteForceMatching(char pattern[], char text[]) {
  int patternLength, textLength, i, m;

  i = 0;
  patternLength = (int) strlen(pattern);
  textLength = (int) strlen(text);

  for(i = 0; i < textLength; i++) {
    m = 0;
    shift++; /*   counts the number of shifts in the search  */
    while((m < patternLength) && ((unsigned char)text[i + m] == pattern[m])) {
      m = m + 1;
    }
    if(m == patternLength) {
      return i;
    }
  }
  return -1;
}

/*
this function is called by the main function it reads the file compares the shrings and prints the output
*/
void bruteForceStringSearch() {
  FILE *fp = NULL;
  char **stringArray = NULL;
  int i = 0;
  char input[30] = {0};
  int result = 0;
  int stringCount = 0;
  char *p = NULL;
  char c[1000] = {0};
  struct timeb start, end;
  float timeDiff = 0;

  fp = fopen("data_5.txt", "r");
  if(fp == NULL) {
    printf("data_5.txt could not be opened\n");
    return;
  }

  stringArray = (char **) malloc(sizeof(char *) * 472559);
  p =  (char *) malloc(sizeof(char) * 100);

  /*
  reads the file line by line
  split each line read and store int an array of strings
  */
  while(1) {
    fgets(c, 1000, fp);
     p = strtok(c, " ");
    while(p != NULL) {
      stringArray[i] = (char *) malloc(sizeof(char) * 100);
      /*
        removes the new line characters at the end of each line
      */

      if(p[strlen(p) - 1] == '\n') {
        p[strlen(p) - 1] = '\0';
      }
      strcpy(stringArray[i], p);
      p = strtok(NULL, " ");
      i++;
    }
    if(feof(fp)) {
      break;
    }
  }


  printf("Please enter a string pattern that you want to search for using brute force:\n");
  scanf("%s", input);

  ftime(&start);
/*
passes each string fron the array into the function to be checked
*/
  for(i = 0; i < 472559; i++) {
    result = bruteForceMatching(input, stringArray[i]);
    if(result != -1) {
      stringCount++;
    }
  }

  ftime(&end);
  timeDiff = (end.time - start.time)*1000 + (end.millitm - start.millitm);


  if(stringCount == 0) {
    printf("No strings that contain that input were found\n");
    printf("The execution time for BruteForce string search is %fms\n", timeDiff);
    printf("The total number of pattern shifts for this input is %d\n", shift);
    return;
  }

  printf("The total number of string that contain that input as a substring is %d\n", stringCount);
  printf("The execution time for BruteForce string search is %fms\n", timeDiff);
  printf("The total number of pattern shifts for this input is %d\n", shift);

  /*
  free all the memmory for the pointers that were mallocked
  */
  for(i = 0; i < 472560; i++) {
    free(stringArray[i]);
  }
  free(stringArray);
  free(p);
  fclose(fp);

}
