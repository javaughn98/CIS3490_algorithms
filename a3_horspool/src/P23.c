#include "header.h"


int getMaximum(int a, int b) {
  return (a > b)? a : b;
}

/*
function creates a shift table for Boyer-Moore's algorithm
*/
void boyerMooreShiftTable(char pattern[], int mooreShiftTable[]) {
  int m = (int) strlen(pattern);
  int i = 0;

  for(i = 0; i < 256; i++) {
    mooreShiftTable[i] = -1;
  }
  for(i = 0; i < m; i++) {
    mooreShiftTable[(int) pattern[i]] = i;
  }

}

void boyer_moore() {
  FILE *fp;
  char **stringArray = NULL;
  int i = 0;
  char *p = NULL;
  char c[1000] = {0};
  char *input = NULL;
  int patternLength = 0;
  int textLength = 0;
  int k = 0;
  int m = 0;
  int mooreShiftTable[256] = {0};
  int numStringsFound = 0;
  struct timeb start;
  struct timeb end;
  float timeDiff = 0;
  int numOfPatternShift = 0;


  fp = fopen("data_5.txt", "r");
  if(fp == NULL) {
    printf("data_5.txt could not be opened\n");
    return;
  }

  stringArray = (char **) malloc(sizeof(char *) * 472559);
  p =  (char *) malloc(sizeof(char) * 100);
  input = (char *) malloc(sizeof(char) * 50);

  while(1) {
    if(feof(fp)) {
      break;
    }
    fgets(c, 1000, fp);
     p = strtok(c, " ");
    while(p != NULL) {
      stringArray[i] = (char *) malloc(sizeof(char) * 100);
      if(p[strlen(p) - 1] == '\n') {
        p[strlen(p) - 1] = '\0';
      }
      strcpy(stringArray[i], p);
      p = strtok(NULL, " ");
      i++;
    }

  }



  printf("Please enter a string pattern that you want to search for using Boyer-Moore's algorithm:\n");
  scanf("%s", input);

  ftime(&start);
  i = 0;
  patternLength = (int) strlen(input);
  boyerMooreShiftTable(input, mooreShiftTable);

/*
  executes Boyer-Moore's algorithm
*/
  while(i < 472559) {
    textLength = (int) strlen(stringArray[i]);
    k = 0;
    while(k <= (textLength - patternLength)) {
      m = patternLength - 1;
      while((m >= 0) && (input[m] == ((unsigned char) stringArray[i][k + m]))) {
        m--;
      }
      if(m < 0) {
        numStringsFound++;
      k += (k + patternLength < textLength)? patternLength - mooreShiftTable[(unsigned char) stringArray[i][k + patternLength]] : 1;
      numOfPatternShift++;
      }
      else {
        k += + getMaximum(1, m - mooreShiftTable[(unsigned char) stringArray[i][k + m]]);
        numOfPatternShift++;
      }
    }
    i++;
  }

  ftime(&end);
  timeDiff = (end.time - start.time)*1000 + (end.millitm - start.millitm);


  if(numStringsFound == 0) {
    printf("No strings that contain that input were found\n");
    printf("The execution time for the Boyer-Moore algorithm is %fms\n", timeDiff);
    printf("The total number of patterrn shifts for this input is %d\n", numOfPatternShift);
    return;
  }

  printf("The total number of string that contain that input as a substring is %d\n", numStringsFound);
  printf("The execution time for the Boyer-Moore algorithm is %fms\n", timeDiff);
  printf("The total number of patterrn shifts for this input is %d\n", numOfPatternShift);

  for(i = 0; i < 472560; i++) {
    free(stringArray[i]);
  }
  free(stringArray);
  free(input);
  free(p);
  fclose(fp);
return;
}
