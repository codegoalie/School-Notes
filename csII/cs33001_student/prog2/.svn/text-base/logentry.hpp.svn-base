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
#include <iostream>
#include <fstream>
#include "string.hpp" 

class Date { 
  public:
            Date();
            Date(String month, int day, int year);
      String   month()   { return _month; };
      int      day()     { return _day; };
      int      year()    { return _year; };

  private:
    int     _year, _day;
    String  _month;

};


class Time {
  public:
            Time();
            Time(int hour, int min, int sec);
      int   hour()    { return _hour; };
      int   minute()  { return _minute; };
      int   second()  { return _second; };

  private:
    int	    _hour, _minute, _second;
};


class logEntry {
  public:
    static const int MAX_HOST_LENGTH  = 14;
    static const int MAX_REQ_LENGTH   = 40;

            logEntry();
            logEntry(String);
    String  host()    const { return _host; };
    String  status()  const { return _status; };
    int     bytes()   const { return _number_of_bytes; };
    String  request() const { return _request; };
    Date    date()    const { return _date; };
    Time    time()    const { return _time; };

    friend  std::ostream& operator<<   (std::ostream&, const logEntry);

  private:
    String  _host;
    Date    _date;
    Time    _time;
    String  _request;
    String  _status;
    int	    _number_of_bytes;
};


//
// Free functions
//

std::ostream& operator<<(std::ostream&, Date);
std::ostream& operator<<(std::ostream&, Time);
std::vector<logEntry>   parse       (std::istream&);
int                     byte_count  (const std::vector<logEntry>&);
void                    output_all  (std::ostream&, const std::vector<logEntry> &);
void                    by_host     (std::ostream&, const std::vector<logEntry> &);

#endif

