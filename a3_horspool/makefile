CSTANDARD = -ansi
CFLAGS = -Wall -pedantic

compile: main P11 P12 P21 P22 P23
	gcc $(CFLAGS) -g main.o P11.o P12.o P21.o P22.o P23.o -o runMe

main: main.c
	gcc $(CFLAGS) $(CSTANDARD) -g -c main.c -o main.o

P11: P11.c
	gcc $(CFLAGS) $(CSTANDARD) -g -c P11.c -o P11.o

P12: P12.c
	gcc $(CFLAGS) $(CSTANDARD) -g -c P12.c -o P12.o

P21: P21.c
	gcc $(CFlAGS) $(CSTANDARD) -g -c P21.c -o P21.o

P22: P22.c
	gcc $(CFLAGS) $(CSTANDARD) -g -c P22.c -o P22.o

P23: P23.c
	gcc $(CFLAGS) $(CSTANDARD) -g -c P23.c -o P23.o

run: compile
	./runMe
