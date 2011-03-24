// Chris Marshall
// 3/24/2011
// Base B Arithmetic Class


#ifndef BASEB_H_
#define BASEB_H_

#include <vector>

class BaseB
{
  public:
    BaseB(std::vector<int> digits, int base) :_base(base), _digits(digits) {};
    BaseB operator+(BaseB);

  private:
    std::vector<int> _digits;
    int _base;
};

#endif
