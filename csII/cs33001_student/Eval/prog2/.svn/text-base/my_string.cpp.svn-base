// Implementation of string class
// Chris Marshall
// 2.28.2010

#include "my_string.hpp"
#include <iostream>
#include <fstream>

using namespace std;

my_string::my_string() { s[0] = 0; }

my_string::my_string(const char str[])
{
  int i =0;
  while (str[i] != 0)
  {
    s[i] = str[i];
    i++;
  }
  s[i] = 0;
}

my_string::my_string(char ch)
{
  s[0] = ch;
  s[1] = 0;
}

int my_string::length()
{
  int i=0;
  while(s[i] != 0) i++;
  return i; 
}

my_string my_string::operator+(my_string rhs)
{
  my_string result(s);
  int len = length();
  int i   = 0;
  while(rhs.s[i] != 0)
  {
    result.s[i + len] = rhs.s[i];
    i++;
  }
  result.s[i + len] = 0;
  return result;
}

my_string my_string::operator+(const char rhs[])
{
  my_string result(s);
  int len = length();
  int i   = 0;
  while(rhs[i] != 0)
  {
    result.s[i + len] = rhs[i];
    i++;
  }
  result.s[i + len] = 0;
  return result;
}

my_string& my_string::operator+=(my_string rhs)
{
  int len = length(), i = 0;
  while(rhs.s[i] != 0)
  {
    s[len + i] = rhs.s[i];
    i++;
  }
  s[len + i] = 0;
  return *this;
}

my_string operator+(const char lhs[], const my_string rhs)
{
  return my_string(lhs) + rhs;
}

my_string operator+(const char a, const my_string rhs)
{
  return my_string(a) + rhs;
}

bool my_string::operator==(my_string rhs)
{
  int len = length();

  if(len != rhs.length()) return false;

  for(int i = 0; i < len; i++)
    if(s[i] != rhs.s[i])
      return false;
  return true;
}

ostream& operator<<(ostream& lhs, my_string rhs)
{
  lhs << rhs.s;
  return lhs;
}

my_string my_string::substr(int start, int end)
{
  if(start < 0 || start >=length() || end < start || 
      end >=length())
  {
    cout << "Invalid substr start or range. Ending..."; 
    return my_string();
  }
  
  my_string substring;
  for(int i = start; i <= end; i++)
    substring += s[i];

  return substring;
}

int my_string::find_char(char needle, int start)
{
  if(start > length() || needle == 0)
    return -1; // reange error

  int i = start;
  while(s[i] != 0 && s[i] != needle)
    i++;

  if(s[1] == 0)
    return -1;
  else 
    return i;
}

char&  my_string::operator[](int i)
{
  return s[i];
}

bool my_string::operator<=(my_string rhs)
{
  int i=0;
  while(s[i] != 0 && rhs.s[i] != 0 && s[i] <= rhs.s[i])
    i++;

  if(s[i] == 0) return true;
  else return false;
}

