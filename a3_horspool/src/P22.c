#include "header.h"

int patternShift = 0;

/*
  functio uses horspools algorithm to find matching strings 
*/
int horspoolMatching(char string1[], char string2[]) {
  int shiftT[256] = {0};
  int i = 0;
  int k = 0;
  int m = 0;
  int n = 0;

  m = (int) strlen(string1);
  n = (int) strlen(string2);

  shiftTable(string1, shiftT);

  i = m - 1;

  while(i < n) {
    k = 0;
    while((k < m) && (string1[m - 1 - k] == string2[i - k])) {
      k++;
    }
    if(k == (m)) {
      return (i - m + 1);
    }
    else {
      patternShift++;
      i = i + shiftT[(unsigned char)string2[i]];

    }
  }
  return -1;
}


/*
function creates shift table for horspools algorithm
*/
 void shiftTable(char string[], int shiftT[]) {
  int i = 0;
  int j = 0;
  int m = 0;

  m = (int) strlen(string);

  for(i = 0; i < 256; i++) {
    shiftT[i] = m;
  }
  for(j = 0; j < m - 1; j++) {
    shiftT[(int) string[j]] = m - 1 - j;
  }
}

void horspool() {
  FILE *fp = NULL;
  char **stringArray = NULL;
  int l = 0;
  int stringCount = 0;
  int result = 0;
  char input[30] = {0};
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

  while(1) {
    fgets(c, 1000, fp);
     p = strtok(c, " ");
    while(p != NULL) {
      stringArray[l] = (char *) malloc(sizeof(char) * 100);
      if(p[strlen(p) - 1] == '\n') {
        p[strlen(p) - 1] = '\0';
      }
      strcpy(stringArray[l], p);
      p = strtok(NULL, " ");
      l++;
    }
    if(feof(fp)) {
      break;
    }
  }



  printf("Please enter a string pattern that you want to search for using Horspool's algorithm:\n");
  scanf("%s", input);

  ftime(&start);

  for(l = 0; l < 472559; l++) {
    result = horspoolMatching(input, stringArray[l]);
    if(result != -1) {
      stringCount++;
    }
  }

  ftime(&end);
  timeDiff = (end.time - start.time)*1000 + (end.millitm - start.millitm);

  if(stringCount == 0) {
    printf("No strings that contain that input were found\n");
    printf("The execution time for Horspool's algorithm is %fms\n", timeDiff);
    printf("The total number of pattern shifts for this input is %d\n", patternShift);
    return;
  }
  printf("The total number of string that contain that input as a substring is %d\n", stringCount);
  printf("The execution time for Horspool's algorithm is %fms\n", timeDiff);
  printf("The total number of pattern shifts for this input is %d\n", patternShift);

  for(l = 0; l < 472560; l++) {
    free(stringArray[l]);
  }
  free(stringArray);
  free(p);
  fclose(fp);
  return;
}
