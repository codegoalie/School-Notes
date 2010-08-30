#include <assert.h>

/* assert(expression.bool)
    assert evaluates expression and abort()
    if exp == false (0)
*/

void foo(int *ptr)
{
  assert(ptr != 0);
  // ...
}

// global
const bool DEBUG = true;
assert( (ptr != 0) || !DEBUG);

if(DEBUG)
  std::cout << "test" << x << std::endl;


int foo(int *ptr)
{
  if(ptr == 0) return 1;
  else 
    //...
  return 0;
}


  
