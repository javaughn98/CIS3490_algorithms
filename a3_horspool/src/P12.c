#include "header.h"

/*
function that sorts the strings to signature strings
*/
char *sorting(char string[]) {
  char tmp;
  int i = 0;
  int j = 0;
  static char tempString[12];

  strcpy(tempString, string);

  for(i = 0; i < strlen(string) - 1; i++) {
    for(j = i + 1; j < strlen(string); j++) {
      if(tempString[i] > tempString[j]) {
        tmp = tempString[i];
        tempString[i] = tempString[j];
        tempString[j] = tmp;
      }
    }
  }
  return tempString;
}

/*
function to search for anagram after string has been sorted
*/
int find_anagram(char string1[], char string2[]) {
  int i = 0;
  if(strlen(string1) != strlen(string2)) {
    return 0;
  }
  for(i = 0; i < strlen(string1); i++) {
    if(string1[i] != string2[i]) {
      return 0;
    }
  }

  return 1;
}

void anagramSorting() {
  FILE *fp = NULL;
  char buffer[12];
  char string[30000][12];
  char string2[30000][12];
  int i = 0;
  char input[12];
  char input2[12];
  int anagramCount = 0;
  int result;
  struct timeb t_start, t_current;
  int t_diff;
  int t_diff1;



  fp = fopen("data_4.txt", "r");
  if(fp == NULL) {
    printf("data_4.txt could not be opened\n");
    return;
  }

  while(1) {
    fscanf(fp, "%s ", buffer);
    strcpy(string[i], buffer);
    if(feof(fp)) {
      break;
    }
    i++;
  }
  fclose(fp);

  printf("Please enter a string you want to find the anagrams of using sorting method:\n");
  scanf("%s", input);

  printf("The anagrams for %s are:\n", input);

  /*
  double presorting method finds and stores the signature of a string
  */
  ftime(&t_start);
  for(i = 0; i < 30000; i++) {
    strcpy(string2[i], sorting(string[i]));
  }
  strcpy(input2, sorting(input));
  ftime(&t_current);
  t_diff = (int) (1000 * (t_current.time - t_start.time) + (t_current.millitm - t_start.millitm));

  ftime(&t_start);


  for(i = 0; i < 30000; i++) {
    result = find_anagram(input2, string2[i]);
    if(result == 1) {
      if(strcmp(input, string[i]) != 0) {
        anagramCount++;
        printf("%s\n", string[i]);
      }
    }
  }

  ftime(&t_current);
  t_diff1 = (int) (1000 * (t_current.time - t_start.time) + (t_current.millitm - t_start.millitm));

  if(anagramCount == 0) {
    printf("No anagrams found for this input\n");
    printf("The total time taken to complete the search is %dms\n", t_diff1);
    printf("The total time taken to sort the array is %dms\n", t_diff);
  }

  printf("The total number of anagrams found is %d\n", anagramCount);
  printf("The total time taken to complete the search is %dms\n", t_diff1);
  printf("The total time taken to sort the array is %dms\n", t_diff);

}
