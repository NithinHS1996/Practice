CC=gcc

lib.a: lib.o
	ar rcs lib_lib.a lib.o
lib.o: lib.c
	gcc -c lib.c -o lib.o

clean:
	rm -f *.o lib lib_lib.a
