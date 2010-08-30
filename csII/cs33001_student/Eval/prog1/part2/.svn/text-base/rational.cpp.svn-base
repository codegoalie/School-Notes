/*  Chris Marshall
 *  33001
 *  01.31.2010
 *  program 1, part 1
 */

// Implementation of rational.h

#include "rational.h"
#include <iostream>
#include <fstream>

using namespace std;

rational::rational() 
{
  numerator   = 0;
  denominator = 1;
}

rational::rational(int a, int b)
{
  numerator   = a;
  denominator = b;
	reduce();
}

void rational::print(ofstream &file)
{
  file << numerator << "/" << denominator;
}

int rational::gcf(int a, int b)
{
	if(a < 0) a = -a;	// make sure a and b are positive
	if(b < 0) b = -b; // signing result handled by reduce()

	if(a == 0 || b == 0) // return 1 if either term is 0
		return 1;

	if(a == b) // stopping condition
		return a;

	bool a_isEven = a % 2 == 0;
	bool b_isEven = b % 2 == 0;

  if( a_isEven && b_isEven)
		return 2 * gcf(a/2, b/2);
	
	else	if(a_isEven && !b_isEven)
		return gcf(a/2, b);
	
	else if(!a_isEven && b_isEven)
		return gcf(a, b/2);
	
	else
	{
		int max = a > b 	 ? a : b;
		int min = max == b ? a : b;

		return gcf( (max - min)/2, min);
	}

	// 
}

void rational::reduce()
{
	int sign_factor = 1;
	int neg_count = 0;
	if(numerator < 0)
	{
		numerator *= -1;
		neg_count += 1;
	}

	if(denominator < 0)
	{
		denominator *= -1;
		neg_count += 1;
	}

  if(neg_count % 2 != 0)
		sign_factor = -1;
		
	int g_cf = gcf(numerator, denominator);
	numerator   = sign_factor * numerator / g_cf;
	denominator = denominator / g_cf;
}
