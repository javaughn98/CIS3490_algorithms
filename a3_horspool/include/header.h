#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>



int find_anagramBruteForce(char string1[], char string2[]);
char *sorting(char string[]);
void bruteForce();
void anagramSorting();
int find_anagram(char string1[], char string2[]);
void bruteForceStringSearch();
void shiftTable(char string[], int shiftT[]);
int horsepoolMatching(char string1[], char string2[]);
void horspool();
void boyer_moore();
void boyerMooreShiftTable(char pattern[], int mooreShiftTable[]);
int getMaximum(int a, int b);
int bruteForceMatching(char pattern[], char text[]);



#endif
