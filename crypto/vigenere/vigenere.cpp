/*
 * Vigenere Cypher Class Implementation
 *
 * Chris Marshall
 * 2/1/2011
 */

#include "vigenere.h"
#include <string>
#include <iostream>

using namespace std;

string vigenere::alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXZ";

string vigenere::encrypt(string plain_text, string key) 
{
  string cypher = "";
  for(int i =0; i < (int)plain_text.size(); ++i)
  {
    cout << i << " " << plain_text[i] << " " << 
      char_to_int(plain_text[i]) << " : " << i % key.size() <<
      " " << char_to_int(key[i % key.size()]) << " : " << 
      char_to_int(plain_text[i]) + char_to_int(key[i % key.size()])
      << " " << (char_to_int(plain_text[i]) + char_to_int(key[i % key.size()]))
      % alphabet.size() << endl;

    cypher += alphabet[(char_to_int(plain_text[i]) + 
          char_to_int(key[i % key.size()]))% alphabet.size()];
  }
  return cypher;
}

string vigenere::decrypt(string cypher, string key)
{
  string plain_text = "";
  for(int i =0; i < (int)cypher.size(); ++i)
  {
    plain_text += alphabet[(char_to_int(cypher[i]) - 
        char_to_int(key[i % key.size()])) % alphabet.size()];
  }
  return plain_text;
}

int vigenere::char_to_int(char c)
{
  switch(c)
  {
    case 'a':
    case 'A':
      return 0;
      break;
    case 'b':
    case 'B':
      return 1;
      break;
    case 'c':
    case 'C':
      return 2;
      break;
    case 'd':
    case 'D':
      return 3;
      break;
    case 'e':
    case 'E':
      return 4;
      break;
    case 'f':
    case 'F':
      return 5;
      break;
    case 'g':
    case 'G':
      return 6;
      break;
    case 'h':
    case 'H':
      return 7;
      break;
    case 'i':
    case 'I':
      return 8;
      break;
    case 'j':
    case 'J':
      return 9;
      break;
    case 'k':
    case 'K':
      return 10;
      break;
    case 'l':
    case 'L':
      return 11;
      break;
    case 'm':
    case 'M':
      return 12;
      break;
    case 'n':
    case 'N':
      return 13;
      break;
    case 'o':
    case 'O':
      return 14;
      break;
    case 'p':
    case 'P':
      return 15;
      break;
    case 'q':
    case 'Q':
      return 16;
      break;
    case 'r':
    case 'R':
      return 17;
      break;
    case 's':
    case 'S':
      return 18;
      break;
    case 't':
    case 'T':
      return 19;
      break;
    case 'u':
    case 'U':
      return 20;
      break;
    case 'v':
    case 'V':
      return 21;
      break;
    case 'w':
    case 'W':
      return 22;
      break;
    case 'x':
    case 'X':
      return 23;
      break;
    case 'y':
    case 'Y':
      return 24;
      break;
    case 'z':
    case 'Z':
    default:
      return 25;
      break;
  }
}
