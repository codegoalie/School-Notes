// Chris Marshall
// Base B Arithmetic Class
// 3/24/2011

#include <vector>
#include <cmath>
#include <iostream>

#include "baseb.h"

BaseB BaseB::operator+(BaseB rhs)
{
  if(_base != rhs._base) 
  {
    std::cout << "Base difference error"; 
    return *this;
  }

  std::vector<int> result, long_adder, short_adder;

  if(_digits.size() > rhs._digits.size())
  {
    long_adder = _digits;
    short_adder = rhs._digits;
  }
  else
  {
    long_adder = rhs._digits;
    short_adder = _digits;
  }

  int short_iterator = short_adder.size() - 1;

  int carry = 0;

  for(int i = long_adder.size()-1; i >= 0; --i)
  {

    int short_digit = 0;
    if(short_iterator >= 0)
      short_digit = short_adder[short_iterator];

    int k = (long_adder[i] + short_digit) + carry;
    if(k >= _base)
    {
      k -= _base;
      carry = 1;
    }
    else
      carry = 0;

    result.insert(result.begin(), k);
    --short_iterator;
  }
  if(carry == 1)
  {
    result.insert(result.begin(), 1);
  }
 
  BaseB returner(result,_base);
  return returner;
}

BaseB BaseB::operator-(BaseB rhs)
{
  int new_size = (_digits.size() > rhs._digits.size()) 
    ? _digits.size()
    : rhs._digits.size();

  rhs.convert_to_complement(new_size);
  BaseB result = *this + rhs;
  result._digits.erase(result._digits.begin());
  return result;
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

void BaseB::convert_to_complement()
{
  convert_to_complement((int)_digits.size());
}

void BaseB::convert_to_complement(int digits)
{
  std::vector<int> new_digits;
  int ii=0;
  for(int i=0; i < digits; ++i)
  {
    if(i < (digits - (int)_digits.size()))
    {
      new_digits.push_back(_base - 1);
    }
    else
    {
      new_digits.push_back(_base - _digits[ii] - 1);
      ++ii;
    }
  }

  _digits = new_digits;
  
  *this = *this + BaseB(std::vector<int>(1,1), _base);
}

int BaseB::base_ten()
{
  int result=0;
  for(int i = 0 ; i < (int)_digits.size(); ++i)
  {
    result += _digits[i] * pow(_base, (int)_digits.size() - i);
  }
  return result;
}
