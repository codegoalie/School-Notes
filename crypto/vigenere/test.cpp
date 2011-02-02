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
  string plain_text, key;

  cout << "Please enter a text to encrypt:" << endl;
  cin >> plain_text;
  cout << "Please enter a key:" << endl;
  cin >> key;
  string cypher = vigenere::encrypt(plain_text, key);
  string decrypt= vigenere::decrypt(cypher, key);

  cout << "Your cyphertext: " << cypher << "\nYour plaintext:  " << decrypt << endl;

  return 1;
}
