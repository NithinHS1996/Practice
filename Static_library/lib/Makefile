CC=g++

liblib.a:lib.o
	ar cr liblib.a lib.o
lib.o: lib.cpp
	$(CC) -c lib.cpp

clean:
	rm -rf *.a *.o
