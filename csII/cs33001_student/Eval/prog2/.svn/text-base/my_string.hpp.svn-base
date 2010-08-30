// Spec for String class awesomeo
// 2.28.2010

#ifndef _STRING_HPP_
#define _STRING_HPP_

#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 256; //or whatever

class my_string
{
  public:
    my_string();
    my_string(const char[]);
    my_string(const char);

    my_string  operator+(const my_string);
    my_string  operator+(const char[]);
    friend  my_string operator+(const char[], const my_string);
    friend  my_string operator+(const char, const my_string);
    my_string& operator+=(const my_string);
    my_string& operator+=(const char[]);

    my_string substr(int start, int end);
    int find_char(char needle, int start);
    char& operator[](int); // return refernece to write: a[1] = 'e';

    friend ostream& operator<<(ostream&, my_string);
    friend istream& operator>>(istream&, my_string&);

    bool operator==(my_string);
    bool operator<=(my_string);
        
    int length();

  private:
    char s[SIZE];
};

#endif

