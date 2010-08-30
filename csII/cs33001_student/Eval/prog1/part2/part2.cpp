/*  Chris Marshall
 *  33001
 *  2.6.2010
 *  program 1, part 2
 */

#include "rational.h"
#include <iostream>
#include <fstream>

using namespace std;

int main (void)
{
  rational num;
	rational num2(10, 8), num3(20, 10);
	num = rational(3, 4);

	ofstream file;
	file.open ("output.txt");
	file << "num  = ";
	num.print(file);

	file << "\nnum2 = ";
	num2.print(file);
	file << "\nnum3 = ";
	num3.print(file);
	file << endl;

  return 0;
}
