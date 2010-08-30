#ifndef _STRING_H_
#define _STRING_H_

//File:        string.h   
//       
//Version:     1.0
//Date:        3.3.2010
//Author:      Chris Marshall
//
//Description: Class definition for a String.
//
//

#include <iostream>
#include <vector>
#include <fstream>


////////////////////////////////////////////////////
// CLASS INV: assigned(capacity)      &&
//            length <= capacity-1    && 
//            str[length] == 0
//            
class String {
  public: 
                     String       ();                     
                     String       (const char*);       
                    ~String       () { delete[] str; }    // Destructor
                     String       (const String&);        // Copy Constructor
            String&  operator=    (const String&);        // Assignment copy
    
            char&    operator[]   (int);                  //Accessor/Modifier.
            char     operator[]   (int) const;            //Accessor.

            int      capacity     ()                      const;
            int      length       ()                      const; 
            void     resize       (int);                  // changes the capacity of the String

            String   operator+    (String)                const; 
            String   operator+    (const char*)           const;
            String&  operator+=   (String);
            String&  operator+=   (const char*);

            int      find_char    (char, int)             const;
            int      find_substr  (String, int)           const;
            String   substr       (int, int)              const;
            std::vector<String>   split  (char)           const;
     
            bool     operator==   (String)                const; 
            bool     operator==   (const char*)           const;
            bool     operator<=   (String)                const;
            bool     operator<    (String)                const;
            bool     operator>=   (String)                const;
            bool     operator>    (String)                const;

  private:  
            char   *str;                 //Pointer to character array.
            int     _capacity;            //Number of characters allocated

};

std::istream& getline      (std::istream&, String&);
std::istream& operator>>   (std::istream&, String&);
std::ostream& operator<<   (std::ostream&, const String&);



#endif

