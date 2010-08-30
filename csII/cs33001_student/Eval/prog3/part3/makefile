CC=g++
CFLAGS=-c -Wall

all: main

main: main.o string.o
	$(CC) main.o string.o -o main

main.o: main.cpp stack.hpp node.hpp string.hpp
	$(CC) $(CFLAGS) main.cpp stack.hpp node.hpp string.hpp

string.o: string.hpp string.cpp
	$(CC) $(CFLAGS) string.hpp string.cpp

clean:
	rm -rf *o main *gch

