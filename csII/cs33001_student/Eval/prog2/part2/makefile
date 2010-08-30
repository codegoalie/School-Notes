CC=g++
CFLAGS=-c -Wall

all: string_test

string_test: string.o part2.o
	$(CC) part2.o string.o -o string_test

part2.o: part2.cpp string.hpp
	$(CC) $(CFLAGS) part2.cpp string.hpp

string.o: string.hpp string.cpp
	$(CC) $(CFLAGS) string.hpp string.cpp

clean:
	rm -rf *o string_test *gch
