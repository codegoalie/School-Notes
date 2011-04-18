// Chris Marshall
// 3/24/2011
// Base B Arithmetic Class


#ifndef BASEB_H_
#define BASEB_H_

#include <vector>

class BaseB
{
  public:
    BaseB(std::vector<int> digits, int base) :_digits(digits), _base(base) {};
    BaseB operator+(BaseB);
    BaseB operator-(BaseB);

    void print();
    void convert_to_complement();
    void convert_to_complement(int);

    int base_ten();

  private:

    std::vector<int> _digits;
    int _base;
};

#endif
