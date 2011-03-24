// Chris Marshall
// Base B Arithmetic Class
// 3/24/2011

#include <vector>
#include <iostream>

#include "baseb.h"

BaseB BaseB::operator+(BaseB rhs)
{
  if(_digits.size() != rhs._digits.size()) 
  {
    std::cout << "Base difference error"; 
    return *this;
  }

  std::vector<int> result;

  int carry = 0;

  for(int i = 0; i < _digits.size(); ++i)
  {
    int k = (_digits[i] + _digits[i]) + carry;
    if(k >= _base)
    {
      k -= _base;
      carry = 1;
    }
    else
      carry = 0;

    result[i] = k;
  }
  if(carry == 1)
  {
    std::cout << "Overflow";
    return *this;
  }
  else
  {
    BaseB* returner = new BaseB(result, _base);
    return *returner;
  }
}
