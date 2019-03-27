#include "header.h"

/*
function to find the anagram using brute force
*/
int find_anagramBruteForce(char string1[], char string2[]) {
  int i = 0;
  int j = 0;
  int found = 0;
  char firstString[12] = {0};
  char secondString[12] = {0};

/* uses temporary strings  for string 1 and string 2*/
  strcpy(firstString, string1);
  strcpy(secondString, string2);

  if(strlen(firstString) != strlen(secondString)) {
    return 0;
  }
  /*
  searches the second string for matching characters of the first string
  */
  for(i = 0; i < strlen(firstString); i++) {
    for(j = 0; j < strlen(secondString); j++) {
      if(firstString[i] == secondString[j]) {
        secondString[j] = '.'; /* if a character is found it changes that character to a '.' to prevent reading one character twice    */
        found = 1;
        break;
      }
    }
    if(found == 0) {
      return 0;
    }
    found = 0;
  }

  return 1;
}








/*
This function is called bu the main function to carry out the processes of the Brute force anagram
search
*/

void bruteForce() {
  FILE *fp = NULL;
  char buffer[12];
  char string[30000][12];
  int i = 0;
  char input[20];
  int anagramCount = 0;
  int result;
  struct timeb t_start, t_current;
  float t_diff;


  fp = fopen("data_4.txt", "r");
  if(fp == NULL) {
    printf("data_4.txt could not be opened\n");
    return;
  }
  /*
  reads the file into a 2D character array
  */
  while(1) {
    fscanf(fp, "%s ", buffer);
    strcpy(string[i], buffer);
    if(feof(fp)) {
      break;
    }
    i++;
  }
  fclose(fp);

  printf("Please enter a string you want to find the anagrams of using brute force method:\n");
  scanf("%s", input);

  printf("The anagrams for %s are:\n", input);

  ftime(&t_start);

/*
searches fro anagrams in each string array  and returns 1 if a string is found
*/
  for(i = 0; i < 30000; i++) {
    result = find_anagramBruteForce(input, string[i]);
    if(result == 1) {
      if(strcmp(input, string[i]) != 0) {
        /* counts the number of anagrams and prints the anagram if one is found   */
        anagramCount++;
        printf("%s\n", string[i]);
      }
    }
  }

  ftime(&t_current);
  t_diff = (1000 * (t_current.time - t_start.time) + (t_current.millitm - t_start.millitm));

  if(anagramCount == 0) {
    printf("No anagrams found for this input\n");
    printf("The total time taken to complete the search is %fms\n", t_diff);
  }

  printf("The total number of anagrams found is %d\n", anagramCount);
  printf("The total time taken to complete the search is %fms\n", t_diff);







}
