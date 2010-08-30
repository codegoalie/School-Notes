/*  Chris Marshall
 *  33001
 *  01.31.2010
 *  program 1
 */

// Specification for rational number ADT implementation

#ifndef RATIONAL_HPP_
#define RATIONAL_HPP_

#include <iostream>
#include <fstream>

using namespace std;

class rational
{

  public:
    rational();						// constructors 
    rational(int, int);

    rational operator+(const rational);
    rational operator+(const int);
    rational operator-(const rational);
    rational operator-(const int);
  
    friend ostream& operator<<(ostream&, rational);
    friend istream& operator>>(istream&, rational&);

  private:
    int numerator;    // class attributes for representation of rational number
    int denominator;

    void reduce();			// divides numerator and denominator by gcf
		int gcf(int, int);	// finds greatest common factor of numerator and denominator
};

#endif /* RATIONAL_H */

