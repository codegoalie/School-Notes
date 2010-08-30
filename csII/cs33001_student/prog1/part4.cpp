/*  Chris Marshall
 *  33001
 *  2.20.2010
 *  program 1, part 4
 */

#include "rational.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main (void)
{
  
  ifstream input_file;
  ofstream output_file;

  input_file.open("data1-2.txt");
  output_file.open("output.txt");

  rational num1, num2;
  int int1;

  input_file >> num1 >> int1;

  output_file << num1 << " * " << int1 << " = " << num1 * int1 << endl;
  output_file << num1 << " / " << int1 << " = " << num1 / int1 << endl;
  output_file << endl;

  while(! input_file.eof()) 
  {
    input_file >> num1;
    if(! input_file.eof())
      input_file >> num2;
    else
      break;
  
    output_file << num1 << " * " << num2 << " = " << num1 * num2 << endl;
    output_file << num1 << " / " << num2 << " = " << num1 / num2 << endl;
    output_file << endl;
  }

  input_file.close();
  output_file.close();

  return 0;
}
