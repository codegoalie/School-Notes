#ifndef _LOGENTRY_HPP_
#define _LOGENTRY_HPP_

//
//
//File:        logentry.hpp  
//       
//Version:     1.0
//Date:        
//Author:      
//
//Description: Class definition for a log entry.
//
//
//

#include <vector>
#include "string.h" 

class Date { 
  public:
            Date() {};

  private:
    String  day, month;
    int     year;
};

class Time {
  public:
            Time() {};

  private:
    int	    hour, minute, second;
};


class logEntry {
  public:
            logEntry() {};
            logEntry(String);

    friend  ostream& operator<<   (ostream&, const Log_Entry);

  private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int	    number_of_bytes;
};


//
// Free functions
//

std::vector<logEntry>   parse       (istream&);
int                     byte_count  (const std::vector<logEntry>&);
void                    output_all  (ostream&, const std::vector<logEntry> &);
void                    by_host     (ostream&, const std::vector<logEntry> &);



#endif
