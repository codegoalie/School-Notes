/*
 * Vigenere Cypher Class
 *
 * has methods for encrypting and decrypting
 *
 * Chris Marshall
 * 2/1/2011
 */

#ifndef VIGENERE_H_
#define VIGENERE_H_

#include <string>

using namespace std;

class vigenere
{
  public:
    static string encrypt(string, string);
    static string decrypt(string, string);

  private:
    static string alphabet;
    static int char_to_int(char);
};

#endif /* VIGENERE_H_ */
