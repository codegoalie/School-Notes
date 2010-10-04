#  Chris Marshall
#
#  9.16.2010
#  Operating Systems
#  Program 1

 
CC=g++
CFLAGS=-c -Wall

all: memory-lookups

memory-lookups: main.o 
	$(CC) main.o -o memory-lookups

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

#rational.o: rational.hpp rational.cpp
#	$(CC) $(CFLAGS) rational.hpp rational.cpp

clean:
	rm -rf *o memory-lookups *gch
