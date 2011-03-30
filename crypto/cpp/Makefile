# Chris Marshall
#
# 3/24/2011
#
# Base B Arithmetic Class Makefile


CC=g++
CFLAGS=-c -Wall

all: base_b

base_b: baseb.o main.o
	$(CC) baseb.o main.o -o base_b

main.o: main.cpp baseb.h
	$(CC) $(CFLAGS) main.cpp baseb.h

baseb.o: baseb.h baseb.cpp
	$(CC) $(CFLAGS) baseb.h baseb.cpp

clean:
	rm -rf *o base_b *gch
