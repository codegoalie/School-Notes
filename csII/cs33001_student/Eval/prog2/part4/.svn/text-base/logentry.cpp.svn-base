//
//
//File:        logentry.cpp  
//       
//Version:     1.0
//Date:        3.9.2010
//Author:      Chris Marshall
//
//Description: Class implementation for a log entry.
//
//
//

#include "logentry.hpp"
#include "string.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <stdlib.h>

/************************************/
// Date class Implementations

Date::Date()
{
  _month = "Jan";
  _day   = 1;
  _year  = 2000;
}

Date::Date(String month, int day, int year)
{
  _month = month;
  _day = day;
  _year = year;
}

std::ostream& operator<<(std::ostream& out, Date d)
{
  out << d.month() << " " << d.day() << ", " << d.year();
  return out;
}

/************************************/
// Time class Implementations

Time::Time()
{
  _hour = _minute = _second = 0;
}

Time::Time(int phour, int pmin, int psec)
{
  _hour    = phour;
  _minute  = pmin;
  _second  = psec;
}

std::ostream& operator<<(std::ostream& out, Time t)
{
  out << t.hour() << ":";
  if(t.minute() < 10)
    out << "0";
  out << t.minute() << ":";
  if(t.second() < 10)
    out << "0";
  out << t.second();
  return out;
}

/************************************************/
// logEntry Class Implementation
//
logEntry::logEntry()
{
  _host = _request = _status = "";
  // date and time default constructros are sufficient
  _number_of_bytes = 0;
}


logEntry::logEntry(String r)
{
  std::vector<String> split = r.split(' ');
  if(split.size() == 10)
  {
    _host = split[0];
    _status = split[8];
    _request = split[6];
    _number_of_bytes = atoi(split[9].get_array()); 
    std::vector<String> dateTime = split[3].split(':');
    _time = Time(
        atoi(dateTime[1].get_array()), 
        atoi(dateTime[2].get_array()),
        atoi(dateTime[3].get_array())
        );

    std::vector<String> date = dateTime[0].split('/');
    _date = Date(
        date[1],
        atoi(date[0].substr(1,2).get_array()),
        atoi(date[2].get_array())
        );
  }
  else
  {
    logEntry();
  }
}

std::ostream& operator<<(std::ostream& out, const logEntry log_entry)
{
  out << log_entry.host();
  for(int i=log_entry.host().length(); i < log_entry.MAX_HOST_LENGTH; ++i)
    out << " ";
  out << " requested " << log_entry.request();
  for(int i=log_entry.request().length(); i < log_entry.MAX_REQ_LENGTH; ++i)
    out << " ";
  out << "(" << log_entry.bytes() << " b, " << log_entry.status() << ")  on " 
      << log_entry.date() << " at " << log_entry.time();
  return out;
}

////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//
std::vector<logEntry> parse(std::istream& in)
{
  std::vector<logEntry> result;
  int i=0;
  while(! in.eof())
  {
    char temp;
    String raw("");
    in >> temp;
    while(temp != '\n' && !in.eof())
    {
      raw += String(temp);
      in.get(temp);
    }
    if(raw != String())
    {
      std::cout << "Parsing Record: " << i << "\r";
      ++i;
      result.push_back(logEntry(raw));
    }
  }
  
  return result;
}

////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//

void output_all(std::ostream& out, const std::vector<logEntry> &logs) 
{
   for(int i=0; i < (int)logs.size(); ++i)
     out << logs[i] << std::endl;
}

////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//
void by_host(std::ostream& out, const std::vector<logEntry> &logs) 
{
  for(int i=0; i < (int)logs.size(); ++i)
    out << logs[i].host() << std::endl;

}

////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//
int	byte_count(const std::vector<logEntry> &logs)
{
  int total_bytes =0;
  for(int i=0; i < (int)logs.size(); ++i)
   total_bytes += logs[i].bytes();

  return total_bytes;
}
