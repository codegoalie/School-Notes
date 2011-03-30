// Chris Marshall
// Base B Arithmetic Class
// 3/24/2011

#include <vector>
#include <iostream>

#include "baseb.h"

BaseB BaseB::operator+(BaseB rhs)
{
  if(_base != rhs._base) 
  {
    std::cout << "Base difference error"; 
    return *this;
  }

  std::vector<int> result;

  int carry = 0;

  int length = 0;
  if(_digits.size() > rhs._digits.size())
    length = _digits.size();
  else
    length = rhs._digits.size();

  for(int i = 0; i < length; ++i)
  {
    //std::cout << i << " finding left\n";
    int left_digit = 0;
    if(i < (int)_digits.size())
      left_digit = _digits[i];

    //std::cout << i << " finding right\n";
    int right_digit = 0;
    if(i < (int)rhs._digits.size())
      right_digit = rhs._digits[i];

    //std::cout << i << " found both\n";
    int k = (left_digit + right_digit) + carry;
    if(k >= _base)
    {
      k -= _base;
      carry = 1;
    }
    else
      carry = 0;

    //std::cout << "adding to result...\n";
    result.push_back(k);
    //std::cout << "done\n";
  }
  if(carry == 1)
  {
    std::cout << "Overflow";
    return *this;
  }
  else
  {
    BaseB* returner = new BaseB(result, _base);
    //std::cout << "returning result\n";
    return *returner;
  }
}

void BaseB::print()
{
  std::cout << "{";
  for(int i=0; i < (int)_digits.size(); ++i)
  {
    if(i != 0) std::cout << ", ";
    std::cout << _digits[i];
  }
  std::cout << "} " << _base;
}
