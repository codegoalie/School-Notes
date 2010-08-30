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

#include "logentry.h"
#include <vector>
#include <fstream>
#include <iostream>

/************************************/
// Date class Implementations

Date::Date()
{
  _month = 1;
  _day   = 1;
  _year  = 2000;
}

Date::Date(int month, int day, int year)
{
  _month = month;
  _day = day;
  _year = year;
}

std::ostream& oerator<<(std::ostream& out, Date d)
{
  out << d.month() << "/" << d.day() << "/" << d.year();
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

ostd::stream& operator<<(std::ostream& out, Time t)
{
  out << t.hour() << ":";
  out << (t.minute() < 10) ? "0" : "";
  out << t.minute();
  out << (t.second() < 10) ? "0" : "";
  out << t.second();
  return out;
}

/************************************************/
// logEntry Class Implementation
//
logEntery::logEntry()
{
  _host = _request = _status = "";
  // date and time default constructros are sufficient
  _number_of_bytes = 0;
}

logEntry::logEntry(String raw)
{
  vector<String> split = raw.split(' ');
  if(split.size() == 10)
  {
    _host = split[0];
    _status = split[7];
    _request = split[5] + " " + split[6];
    _number_of_bytes = split[8]; 
  }
  else
  {
    logEntry();
  }
}

ostd::stream& operator<<(std::ostream& out, const logEntry log_entry)
{
  out << _host;
  for(int i=host.length(); i < MAX_HOST_LENGTH; ++i)
    out << " ";
  out << " requested " << _request;
  for(int i=request.length(); i < MAX_REQ_LENGTH; ++i)
    out << " ";
  out << "(" << _bytes << " b, " << _status << ")  at " 
      << _date << " " << _time;
  return out;
}

////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//
vector<Log_Entry> parse(istream& in)
{
  vector<Log_Entry> result;
  while(! in.eof())
  {
    String raw;
    in.getline(raw);
    result.push_back(logEntry(raw));
  }

  return result;
}

////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//
void output_all(std::ostream& out, const vector<Log_Entry> &logs) 
{
   for(int i=0; i < logs.size(); ++i)
     out << logs[0] << std::endl;

   return out;
}

////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//
void by_host(std::ostream& out, vector<Log_Entry> logs) 
{
  for(int i=0; i < logs.size(); ++i)
    out << logs[i].host() << std::endl;
  return out;  
}

////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//
int	byte_count(const vector<Log_Entry> &logs)
{
  int total_bytes =0;
  for(int i=0; i < logs.size(); ++i)
   total_bytes += logs[i].bytes();

  return total_bytes;
}


////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//
Log_Entry::Log_Entry(String s) {
    
    vector<String> vec = s.split(' ');


    //You must add stuff here.
}
