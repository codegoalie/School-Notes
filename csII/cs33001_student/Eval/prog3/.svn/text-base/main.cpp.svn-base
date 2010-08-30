/* Testing for Stack Implementation
 * Chris Marshall
 * 4.4.2010
 */

#include "stack.hpp"
#include <iostream>

int main()
{
  Stack<int> a;
  a.push(3);
  a.push(2);
  a.push(1); // test the push method
  std::cout << "a: ";
  for(int i=0; i<3; i++)
    std::cout << a.pop() << " "; // expected output: "a: 1 2 3 "
  std::cout << std::endl;
  a.push(3);
  a.push(2);
  a.push(1); // rebuild the stack for assignment

  Stack<int> b(a);
 // b = a; // using constant to assign tests copy constructor and destructor (plus assignment)
  std::cout << "b: ";
  for(int i=0; i<3; i++)
    std::cout << b.pop() << " "; // expected output: "b: 1 2 3 "
  std::cout << std::endl;

  return 0;
}
