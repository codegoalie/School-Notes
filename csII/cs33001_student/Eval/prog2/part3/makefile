CC=g++
CFLAGS=-c -Wall

all: part3

part3: string.o part3.o
	$(CC) part3.o string.o -o part3

part3.o: part3.cpp string.hpp
	$(CC) $(CFLAGS) part3.cpp string.hpp

string.o: string.hpp string.cpp
	$(CC) $(CFLAGS) string.hpp string.cpp

clean:
	rm -rf *o part3 *gch
