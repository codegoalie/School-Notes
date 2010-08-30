#Make for program 4 Lisp

lisp : main.o sexpr.o
	g++ -Wall -o lisp main.o sexpr.o
  
main.o    : main.cpp sexpr.h
	g++ -Wall -c main.cpp
sexpr.o   : sexpr.cpp sexpr.h
	g++ -Wall -c sexpr.cpp
  
clean : 
	rm -f lisp *.o