CC=g++
all:liblib.so main

liblib.so:lib.o
	$(CC) -shared -fPIC -o liblib.so lib.o
lib.o: lib.cpp
	$(CC) -fPIC -c -o lib.o lib.cpp

main:main.o
	g++ -o main main.o liblib.so
main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *.so *.o main 
