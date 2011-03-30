// Chris Marshall
// 3/29/2011

#include <iostream>
#include "baseb.h"

int main()
{

  int initter[] =  {1,0,1,1,0,0,1,1,1,0,0,0};
  std::vector<int> vals (initter, initter+ sizeof(initter) / sizeof(int));
  BaseB one_a(vals, 2);

  int initter2[] = {1,0,0,1,1,1,0,1,1,0,0};
  std::vector<int> vals2 (initter2, initter2 + sizeof(initter2) / sizeof(int));
  BaseB one_b(vals2, 2);

  BaseB one_r = one_a + one_b;
  std::cout << std::endl;
  one_a.print();
  std::cout << " +\n";
  one_b.print();
  std::cout << " =\n";
  one_r.print();
  std::cout << std::endl;

  return 0;
}
