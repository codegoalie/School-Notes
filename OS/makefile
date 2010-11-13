CC=g++
CFLAGS=-c -Wall

all: fib

fib: fib.o 
	$(CC) fib.o -o fib

fib.o: fib.cpp
	$(CC) $(CFLAGS) fib.cpp

clean:
	rm -rf *o fib *gch

