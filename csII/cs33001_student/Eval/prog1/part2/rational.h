/*  Chris Marshall
 *  33001
 *  01.31.2010
 *  program 1, part 1
 */

// Specification for rational number ADT implementation

#ifndef RATIONAL_H
#define RATIONAL_H

#include <fstream>

class rational
{
  public:
    rational();						// constructors 
    rational(int, int);

    void print(std::ofstream&);
  private:
    int numerator;    // class attributes for representation of rational number
    int denominator;

    void reduce();			// divides numerator and denominator by gcf
		int gcf(int, int);	// finds greatest common factor of numerator and denominator
};

#endif /* RATIONAL_H */

