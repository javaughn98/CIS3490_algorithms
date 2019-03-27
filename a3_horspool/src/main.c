#include "header.h"




int main(int argc, char *argv[]) {
  int input;


  do {
    printf("Please select on of the following options below (between 1 and 6):\n");
    printf("1 - program for exersize P11\n");
    printf("2 - program for exersize P12\n");
    printf("3 - program for exersize P21\n");
    printf("4 - program for exersize P22\n");
    printf("5 - program for exersize P23\n");
    printf("6 - exit\n");

    scanf("%d", &input);

    switch(input) {
      case 1:
        bruteForce();
        break;

      case 2:
        anagramSorting();
        break;

      case 3:
        bruteForceStringSearch();
        break;

      case 4:
        horspool();
        break;

      case 5:
        boyer_moore();
        break;

      case 6:
        printf("exiting.....Goodbye\n");
        break;

    }

    if(input > 6 || input < 0) {
      printf("please enter a number between 1 and 6.\n\n");
    }

  }while(input != 6);

  return 0;
}
