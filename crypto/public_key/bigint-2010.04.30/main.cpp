
#include <iostream>
#include <cmath>
#include "BigIntegerLibrary.hh"


BigUnsigned RSADigitalSigAuthenticate(BigUnsigned, BigUnsigned, BigUnsigned);

int main()
{
//BigUnsigned a = 8866446688, b = 196819691970, 
//    p = 2425967623052370772757633156976982469681, g = 3;
//
//BigUnsigned A(modexp(g,a,p)), B(modexp(g,b,p));
//std::cout << std::endl << 
//  "g^a(mod p) = A = " << A << std::endl <<
//  "g^b(mod p) = B = " << B << std::endl <<
//  "Alice's K  = B^a(mod p) = " << modexp(B, a, p) << std::endl <<
//  "Bob's K    = A^b(mod p) = " << modexp(A, b, p) << std::endl <<
//  std::endl;

  std::cout << "Example 9.4:\n\n";
  BigUnsigned s(1790), e(883), n(1817), m(1776);
  std::cout << "Alice sent (s,n,e) of (" << s << ", " << e << ", " << n << ") " <<
    "for the message " << m << ".\nBob authenticates to " <<
    RSADigitalSigAuthenticate(s,e,n) << std::endl;
  std::cout << "The signature is ";
  if(m != RSADigitalSigAuthenticate(s,e,n)) std::cout << "not ";
  std::cout << "valid.\n";

  std::cout << "\n\n\n";
  e = 727641838100;
  n = 153817*1542689;
  m = 888999000;
  s = modexp(m, 25936022131, n);
  std::cout << "Alice sent (s,n,e) of (" << s << ", " << e << ", " << n << ") " <<
    "for the message " << m << ".\nBob authenticates to " <<
    RSADigitalSigAuthenticate(s,e,n) << std::endl;
  std::cout << "The signature is ";
  if(m != RSADigitalSigAuthenticate(s,e,n)) std::cout << "not ";
  std::cout << "valid.\n";
  return 0;
}

BigUnsigned RSADigitalSigAuthenticate(BigUnsigned s, BigUnsigned e, BigUnsigned n)
{
  return modexp(s, e, n);
}
