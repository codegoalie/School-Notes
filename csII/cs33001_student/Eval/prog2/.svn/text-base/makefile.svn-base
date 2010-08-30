CC=g++
CFLAGS=-c -Wall

all: my_string_test

my_string_test: my_string.o main.o
	$(CC) main.o my_string.o -o my_string_test

main.o: main.cpp my_string.hpp
	$(CC) $(CFLAGS) main.cpp my_string.hpp

my_string.o: my_string.hpp my_string.cpp
	$(CC) $(CFLAGS) my_string.hpp my_string.cpp

clean:
	rm -rf *o my_string_test *gch
