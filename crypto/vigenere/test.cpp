/*
 * Vigenere Cypher Test Program
 *
 * Chris Marshall
 * 2/1/2011
 */

#include "vigenere.h"
#include <string>
#include <iostream>

using namespace std;

int main(void)
{
  string plain_text = "ITSASECRET";
  string key = "LEMON";

  string cypher = vigenere::encrypt(plain_text, key);
  string decrypt= vigenere::decrypt(cypher, key);

  cout << plain_text << " >> " << cypher << " >> " << decrypt << endl;

  return 1;
}
