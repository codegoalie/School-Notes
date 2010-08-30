// Test for string class
// Chris Marshall
// 2.28.2010

#include "my_string.hpp"
#include <iostream>

using namespace std;

int main()
{
  my_string a;
  my_string b("Joe");
  my_string c('c');

  cout << "Length Method: ";
  if(b.length() == 3) cout << "Passed";
  else cout << "Failed";
  cout << endl;

  cout << "my_string + my_string overload: ";
  a = b + c;
  if(a == "Joec") cout << "Passed";
  else cout << "Failed";
  cout << endl;

  cout << "my_string + char overload: ";
  if((b + 'c') == "Joec") cout << "Passed";
  else cout << "Failed";
  cout << endl;

  cout << "char + my_string overload: ";
  if(('c' + b) == "cJoe") cout << "Passed";
  else cout << "Failed";
  cout << endl;

  char d[2];
  d[0] = 'a';
  d[1] = 'b';

  cout << "my_string + char[] overload: ";
  if(b + d == "Joeab") cout << "Passed";
  else cout << "Failed";
  cout << endl;

  cout << "char[] + my_string overload: ";
  if(d + b == "abJoe") cout << "Passed";
  else cout << "Failed";
  cout << endl;


  a = "abcdefghijk";
  cout << "substr method: ";
  if(a.substr(2,4) == "cde") cout << "Passed";
  else cout << "Failed";
  cout << endl;

  cout << "find_char method: ";
  if(a.find_char('f', 0) == 5) cout << "Passed";
  else cout << "Failed";
  cout << endl;

  cout << "[] accessor: ";
  if(a[4] == 'e') cout << "Passed";
  else cout << "Failed";
  cout << endl;

  cout << "[] mutator: ";
  a[4] = 'z';
  if(a[4] == 'z') cout << "Passed";
  else cout << "Failed";
  cout << endl;

  return 0;
}
