/*
 * Extended Euclidean Algorithm
 *
 * Chris Marshall
 * 2/23/2011
 */

#include <iostream>
#include <vector>

using namespace std;

int gcd(int, int);

vector<int> ExtEucAlg(int a, int b)
{
  vector<int> tmpVal, tmpVal2, ret;
  ret.push_back(gcd(a, b));
  if(a % b == 0)
  {
    ret.push_back(0);
    ret.push_back(1);
  }
  else
  {
    tmpVal = ExtEucAlg(b, a % b);
    ret.push_back(tmpVal[2]);
    ret.push_back(tmpVal[1]-tmpVal[2] * (a/b));
    
  }
  return ret;
}

int gcd(int a, int b)
{
  while(b != 0)
  {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main()
{
  vector<int> a;
  a = ExtEucAlg(1001,54);
  cout << "d = " << a[0] << ", a = " << a[1] << ", b = " << a[2] << endl;

  return 0;
}
