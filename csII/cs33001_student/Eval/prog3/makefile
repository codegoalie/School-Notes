CC=g++
CFLAGS=-c -Wall

all: main

main: main.o
	$(CC) main.o -o main

main.o: main.cpp stack.hpp node.hpp
	$(CC) $(CFLAGS) main.cpp stack.hpp node.hpp

clean:
	rm -rf *o main *gch

