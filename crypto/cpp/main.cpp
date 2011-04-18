// Chris Marshall
// 3/29/2011

#include <iostream>
#include "baseb.h"

int main()
{

  int initter[] =  {22,18,13,8};
  std::vector<int> vals (initter, initter+ sizeof(initter) / sizeof(int));
  BaseB one_a(vals, 30);

  int initter2[] = {2,20,29,13};
  std::vector<int> vals2 (initter2, initter2 + sizeof(initter2) / sizeof(int));
  BaseB one_b(vals2, 30);

  BaseB one_r = one_a - one_b;
  std::cout << std::endl;
  one_a.print();
  std::cout << "(" << one_a.base_ten() << ") -\n";
  one_b.print();
  std::cout << "(" << one_b.base_ten() << ") =\n";
  one_r.print();
  std::cout << "(" << one_r.base_ten() << ")\n";

  return 0;
}
