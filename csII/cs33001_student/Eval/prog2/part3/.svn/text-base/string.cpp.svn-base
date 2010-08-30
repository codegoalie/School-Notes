//File:        string.cpp  
//       
//Version:     1.0
//Date:        3.3.2010
//Author:      Chris Marshall
//
//Description: Class definition for a String.
//
//

#include "string.hpp"
#include <iostream>
#include <vector>
#include <fstream>

//////////////////////////////////////////////////////////
// Constructor
// PRE:   Nothing
// POST:  String of size 1 created with NULL element
//
String::String()
{   
  _capacity = 64;
  str = new char[_capacity];    // allocate some memory from the heap for our string
  str[0] = 0;           // NULL terminate the string
} 


//////////////////////////////////////////////////////////
// Constructor
// PRE:  Nothing
// POST: str contains the passed char array
//
String::String(const char *s)
{ 
  _capacity = 64;
  str = new char[_capacity];
  int i = 0;
  while(s[i] != 0)
  {
    str[i] = s[i];    // copy chars from s to str
    ++i;
  }
str[i] = 0;         // null terminate string
} 

//////////////////////////////////////////////////////////
// Copy Constructor
// PRE:
// POST: this is copy of actual 
//
String::String(const String& actual)
{
  _capacity = actual.capacity();
  str = new char[_capacity];            // allocate memory

  int i=0;
  while(actual[i] != 0)
  {
    str[i] = actual[i];         // copy values
    ++i;
  }
  
  str[i] = 0;                   // null terminalte String
}

//////////////////////////////////////////////////////////
// Assignment Copy
// 
// PRE: s = String
// POST: this == s
//
String& String::operator=(const String& s)
{ 
  delete[] str;                   // deallocate the string
  int len = s.length();           
  str = new char[len];            // allocate new memory
  for(int i=0; i < len; ++i)
    str[i] = s[i];                // copy values from s to string
  str[len] = 0;                     // null terminate string

  return *this;                   // return dereference of this for chaining
}

//////////////////////////////////////////////////////////
// Mutator for bracket operator 
// PRE: 0 < i < length()
// POST: RetVal == element i of str
//
char& String::operator[] (int i)
{
  return str[i];
}

//////////////////////////////////////////////////////////
// Accessor for bracket operator 
// PRE: 0 < i < length()
// POST: RetVal == element i of str
//
char String::operator[] (int i) const
{
  return str[i];
}
//////////////////////////////////////////////////////////
//
// Accessor for _capacity
// PRE: 
// POST: RetVal == _capacity of string
//
int String::capacity() const
{
  return _capacity;
}

//////////////////////////////////////////////////////////
// Accessor for Length
// PRE: 
// POST: RetVal == length of string
//
int String::length() const
{
  int i=0;
  while(str[i] != 0) ++i;
  return i;
}

//////////////////////////////////////////////////////////
// Changes the capacity of the sring, copying the contents
// PRE: 
// POST: _capacity == cap, contents kept in tack
//
void String::resize(int cap) 
{
  char *temp;
  temp = new char[cap];
  int len = length();
  if(cap < len)
    len = cap;

  for(int i=0; i < len; ++i)
    temp[i] = str[i];

  delete[] str;
  str = temp;
  _capacity = cap;
}

//////////////////////////////////////////////////////////
// Concatination with other String
// PRE: 
// POST: RetVal == this concat with rhs
//
String String::operator+(String rhs) const
{
  String result;                // init new String
  int i=0;
  while(str[i] != 0)
  {
    result[i] = str[i];         // copy all from this
    ++i;
  }

  int ii=0;
  while(rhs[ii] != 0)
  {
    result[i] = rhs[ii];        // copy all form rhs starting where this left off
    ++i;
    ++ii;
  }

  result[i+ii-1] = 0;           // null terminate 

  return result;
}

//////////////////////////////////////////////////////////
// Concatination with Char[]
// PRE: 
// POST: RetVal == this concat with ch
//
String String::operator+(const char *ch) const
{
  String result(*this);
  int i=length();
  int ii=0;
  while(ch[ii] != 0 && i < _capacity)
  {
    result[i] = ch[ii];
    ++i;
    ++ii;
  }
  
  result[i] = 0;

  return result;
}

//////////////////////////////////////////////////////////
// Concatination modifying this with String
// PRE: 
// POST: RetVal == this == this concat with rhs
//
String& String::operator+=(String rhs)
{
  *this = *this + rhs;
  return *this;
}


//////////////////////////////////////////////////////////
// Concatination modifying this with char[]
// PRE: 
// POST: RetVal == length of string
//
String& String::operator+=(const char *ch)
{
  *this = *this + ch;
  return *this;
}

////////////////////////////////////////////////////////// 
// PRE:  0 <= pos < length
// POST: RetVal == i where s[i] == ch && (i >= pos)
//       RetVal == -1 if ch not in string.
//
int String::find_char(char ch, int pos) const
{  
  int len = length();
  if(pos >= len || pos < 0)
  {
    std::cout << "find_char pos out of bounds";
    return(-1);
  }

  for(int i=pos; i < len; ++i)
    if(str[i] == ch)
      return i;

  return -1;
}

////////////////////////////////////////////////////////// 
// PRE:  0 <= pos < length
// POST: RetVal == i where str[i,..,j] == s && (i >= pos)
//       RetVal == -1 if ch not in string.
//
int String::find_substr(String s, int pos) const
{
  int len = length();
  if(pos >= len || pos < 0)
  {
    std::cout << "find_substr pos out of bounds";
    return(-1);
  }

  int sub_len = s.length();
  if(sub_len > (len-pos))
  {
    std::cout << "find_substr: substring length too long";
    return -1;
  }

  for(int i=pos; i < len-sub_len; ++i)
  {
    //std::cout << i << " to " << i+sub_len << " = " << substr(i, i+sub_len) << std::endl;
    if(substr(i, i+sub_len-1) == s)
      return i;
  }

  return -1;
}

//////////////////////////////////////////////////////////
// PRE:  0 <= start <= end < length
// POST: RetVal == String(str[start .. end])
//
String String::substr(int start, int end) const
{ 

    String result;
    int len = length();
    if(start >= len || start < 0 )            // bound check for start
    {
        std::cout << "substr start illegal";
        return(result);
    }
    if(end >= len || end < 0 || end < start)  // bound check for end
    {
      std::cout << "substr end illegal";
      return(result);
    }

    int ii =0;
    for(int i=start; i <= end; ++i)
    {
      result.str[ii] = str[i];             // copy values
      ++ii;
    }
    result[ii] = 0;                // null terminate

    return result;                    
}

////////////////////////////////////////////////////////// 
// PRE:  
// POST: RetVal == vector of Strings split from this by ch 
//
//
std::vector<String> String::split(char ch) const
{
  std::vector<String> result;
  
  int start = 0;
  int end = find_char(ch, 0);         // find the first occurance of ch
  int len = length();
  while(end < len && end != -1)
  {
    result.push_back(substr(start, end-1));   // add the substring between start and end to result
    start = end + 1;                        // move start to one after end
    end = find_char(ch, start);             // find the next occurance of ch
  }

  if(start != len-1)
    result.push_back(substr(start, len-1));
  
  return result;
}


////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//
bool String::operator==(String rhs) const
{
  int len = length();

  if(len != rhs.length()) return false;  // compare lengths of strings, if unequal return false
  
  for(int i=0; i < len; ++i)
    if(str[i] != rhs.str[i])        // if we find a char which isn't equal among strings, return false
      return false;

  return true;
}

////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//
bool String::operator==(const char *ch) const
{
  int i=0;
  while(str[i] == ch[i] && str[i] != 0 && ch[i] != 0)
    ++i;

  return (str[i] == ch[i]);
}

////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//
bool String::operator<=(String rhs) const
{
  int i=0;
  while(str[i] <= rhs[i] && str[i] != 0 && rhs[i] != 0)
    ++i;

  return (str[i] == rhs[i]);

}

////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//
bool String::operator<(String rhs) const
{
  int i=0;
  while(str[i] < rhs[i] && str[i] != 0 && rhs[i] != 0)
    ++i;

  return (str[i] == rhs[i]);

}

////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//
bool String::operator>=(String rhs) const
{
  int i=0;
  while(str[i] >= rhs[i] && str[i] != 0 && rhs[i] != 0)
    ++i;

  return (str[i] == rhs[i]);

}

////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//
bool String::operator>(String rhs) const
{
  int i=0;
  while(str[i] > rhs[i] && str[i] != 0 && rhs[i] != 0)
    ++i;

  return (str[i] == rhs[i]);

}

//////////////////////////////////////////////////////////
//  Reads from in until the end of line character is reached.
// 
//
std::istream& getline(std::istream& in, String& s) 
{   
  

  return in;
}



//////////////////////////////////////////////////////////
//Input
//
std::istream& operator>>(std::istream& in, String& s) { 
  


  return in;
}


//////////////////////////////////////////////////////////
// Output.
//
std::ostream& operator<<(std::ostream& out, const String& s){ 
  int i=0;
  while(s[i] != 0)
  {
    out << s[i];
    ++i;
  }

  return out;
} 
