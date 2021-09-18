CC=g++

main:main.o
	g++ main.o ../lib/liblib.a -o main
main.o: main.cpp
	$(CC) -c main.cpp

clean:
	rm -rf *.o main
