Name: Javaughn Burke
StudentID#: 1025920
Assignment 3
Date: February 27, 2019


To compile the files  type in "make"
to run the program type in "./rumMe"

a menu should pop up prompting required actions to run each programs
Options 1 and 2 to run P11 and P12 respectively will display the anagrams that were found
,the total count of anagrams and the program execution time of the anagram entered in the Research
Options 3, 4 and 5 runs P21 - BruteForce string search, P22 - horspool string search and P23 - Boyer Moore string
search respectively. programs should display shift count, execution time and number of times the string is found.


program Analysis:

bruteForce shift patterns - (2102412 + 2682458 + ...) / 10 = 2736916
bruteForce performance time - (30 + 35 + 40 + 44 + 36 + 33 + 32 + 34 + 35 + 41) / 10 =  36ms

horspool's algorithm shift pattern -(1931351 + 1260805 + ...) / 10 = 584537
horspool's algorithm performance time - (431 + 423 + 464 + 431 + 419 + 477 + 461 + 419 + 424 + 420) / 10 = 436.9ms


The horspool's algorithm was much slower than the brute force algorithm for some reason in my case.
The brute for ce should be slower but for some reason the program pauses for a split second before it ran
and i couldnt find the issue. The average times for the algorithms are 36ms for bruteForce and 436.9ms for horspool

The time efficiency for brute force  was O(n^2) and the horspool and Boyer-Moore should be O(n/m)

The brute force for the anagram search is slower than the presorting method consitering the fact that the presorting step was done
before checking for the anagram.    
