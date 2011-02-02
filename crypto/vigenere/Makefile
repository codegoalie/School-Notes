# Chris Marshall
#
# 2/1/2011
#
# Vigenere Cypher Makefile


CC=g++
CFLAGS=-c -Wall

all: vigenere_test

vigenere_test: vigenere.o test.o
	$(CC) vigenere.o test.o -o vigenere_test

test.o: test.cpp vigenere.h
	$(CC) $(CFLAGS) test.cpp vigenere.h

vigenere.o: vigenere.h vigenere.cpp
	$(CC) $(CFLAGS) vigenere.h vigenere.cpp

clean:
	rm -rf *o vigenere_test *gch
