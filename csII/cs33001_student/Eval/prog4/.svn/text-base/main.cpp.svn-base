///////////////////////////////////////////////////
//
// File:        main.cpp of Lisp
//              Program 4 CS II
// Programmer:  J. Maletic 
// Date:        4/20/2010
//
// Description: A simple LISP interpreter.
//              Uses sexpr.h, lispnode.h, and string.h
//
#include "sexpr.h"

int main() {
    sexpr  Lisp;
    sexpr  bye("bye");
    bool   done = false;

    std::cout << "Welcome to KSULisp" << std::endl << std::endl;

    while (!done) {
        std::cout << "> ";
        std::cin >> Lisp;

        //std::cout << "ECHO: " << Lisp << std::endl;  //FOR DEBUGGING -- REMOVE THIS LINE
                                                     // IN FINAL VERSION.

        std::cout << eval(Lisp) << std::endl;
        
        if (bye == eval(Lisp)) done = true; //Won't work without eval.

        Lisp.garbageCollection();
    }
    std::cout << std::endl << "Exiting KSULisp..." << std::endl;
    return 0;
}

