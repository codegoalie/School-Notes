// Test for string class
// Chris Marshall
// 2.28.2010

#include "string.hpp"
#include <iostream>

void test(String, bool, int &, int &);

int main()
{
  int total=0, passed=0;

  String a;
  String b("Joe");
  String c("c");

  
  test(String("Default Constructor"), a == "", passed, total);
  test(String("Char Array Constructor"), b == "Joe", passed, total);
  a = b;
  test(String("Assignment"), a == "Joe", passed, total);
  test(String("[] accessor"), b[2] == 'e', passed, total);
  b[0] = 'D';
  test(String("[] mutator"), b[0] == 'D', passed, total);
  test(String("Capacity Accessor"), b.capacity() == 64, passed, total);
  test(String("Length Accessor"), b.length() == 3, passed, total);
  test(String("String + String"), (a + c) == "Joec", passed, total); 
  test(String("String + char[]"), (c+"at") == "cat", passed, total);
  String d("at");
  c+=d;
  test(String("String += String"), c == "cat", passed, total);
  a+="s";
  test(String("String += char[]"), a == "Joes", passed, total);
  String e("abcdefghijkl");
  String f("efg");
  test(String("find_char"), e.find_char('e', 0) == 4, passed, total);
  test(String("substr"), e.substr(2,4) == "cde", passed, total);
  test(String("find_substr"), e.find_substr(f, 0) == 4, passed, total);
  //test(String("split"), false, passed, total);
  a = String("abc");
  b = String("def");
  test(String("<= when equal"), a <= a, passed, total);
  test(String("<= when less"), a <= b, passed, total);
  test(String("<= when greater"), (b <= a) == false, passed, total);
  test(String(">= when equal"), a >= a, passed, total);
  test(String(">= when greater"), b >= a, passed, total);
  test(String(">= when less"), (a >= b) == false, passed, total);
  a.resize(32);
  test(String("resize to larger"), (a.capacity() == 32) && a == "abc", passed, total);
  a.resize(2);
  test(String("resize to smaller"), a.capacity() == 2 && a == "ab", passed, total);

  std::cout << "\n\nPassed:     " << passed << std::endl << "Total:      " << total << std::endl;
  std::cout << "Percentage: " << (int)((double)(passed)/total*100) << "%\n";

  return 0;
}

void test(String name, bool test, int &passed, int &total)
{
  ++total;
  if(test)
    ++passed;
  else
    std::cout << name << " Failed\n";
}
