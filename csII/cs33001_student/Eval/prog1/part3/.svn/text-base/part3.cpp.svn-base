/*  Chris Marshall
 *  33001
 *  2.13.2010
 *  program 1, part 3
 */

#include "rational.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main (void)
{
  
  ifstream input_file;
  ofstream output_file;

  input_file.open("data1-1.txt");
  output_file.open("output.txt");


  while(! input_file.eof()) 
  {
    rational num1, num2;
    input_file >> num1;
    if(! input_file.eof())
      input_file >> num2;
    else
      break;

  
    //rational num1(5,8), num2(12,16);
    output_file << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    output_file << num1 << " - " << num2 << " = " << num1 - num2 << endl;
    output_file << endl;
  }

  rational num3(14, 2);

  int a = 4;
  output_file << num3 << " + " << a << " = " << num3 + a << endl;
  output_file << num3 << " - " << a << " = " << num3 - a << endl;

  input_file.close();
  output_file.close();

  return 0;
}
