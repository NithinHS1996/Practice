CC=gcc
all:lib.so main

lib.so: lib.o
	gcc -shared -o lib.so lib.o
lib.o: lib.c
	gcc -fPIC -c lib.c -o lib.o

main:main.o
	gcc -o main main.o lib.so
main.o: main.c
	gcc -c main.c

clean:
	rm -f *.o *.so main
