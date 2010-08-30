#  Chris Marshall
#  33001
#  01.31.2010
#  program 1, part 1

 
CC=g++
CFLAGS=-c -Wall

all: rational

rational: part2.o rational.o
	$(CC) part2.o rational.o  -o rational

part2.o: part2.cpp rational.h
	$(CC) $(CFLAGS) part2.cpp rational.h

rational.o: rational.h rational.cpp
	$(CC) $(CFLAGS) rational.h rational.cpp

clean:
	rm -rf *o rational *gch output.txt
