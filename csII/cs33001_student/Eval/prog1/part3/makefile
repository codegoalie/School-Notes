#  Chris Marshall
#  33001
#  01.31.2010
#  program 1

 
CC=g++
CFLAGS=-c -Wall

all: rational

rational: part3.o rational.o
	$(CC) part3.o rational.o  -o rational

part3.o: part3.cpp rational.hpp
	$(CC) $(CFLAGS) part3.cpp rational.hpp

rational.o: rational.hpp rational.cpp
	$(CC) $(CFLAGS) rational.hpp rational.cpp

clean:
	rm -rf *o rational *gch output.txt
