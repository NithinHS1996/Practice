CC=gcc

main: main.o
	gcc -o main main.o -L../lib/ -l_lib

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm -f *.o main
