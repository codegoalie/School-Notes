// Chris Marshall
// 3/29/2011

#include <iostream>
#include "baseb.h"

int main()
{

  int initter[] =  {1,2,2};
  std::vector<int> vals (initter, initter+ sizeof(initter) / sizeof(int));
  BaseB one_a(vals, 3);

  int initter2[] = {1,2,0};
  std::vector<int> vals2 (initter2, initter2 + sizeof(initter2) / sizeof(int));
  BaseB one_b(vals2, 3);

  BaseB one_r = one_a - one_b;
  std::cout << std::endl;
  one_a.print();
  std::cout << " -\n";
  one_b.print();
  std::cout << " =\n";
  one_r.print();
  std::cout << std::endl;

  return 0;
}
