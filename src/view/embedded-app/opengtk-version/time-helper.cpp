#include <iostream>
#include <sstream>
#include <ctime>
#include <string>


#include "time-helper.h"


std::string utc_time_for_display()
{
  std::time_t now = std::time(0); 

  // Convert to a tm structure (local time)
  std::tm* localTime = std::localtime(&now);

  // Access individual components
  int year = localTime->tm_year + 1900; // Years since 1900
  int month = localTime->tm_mon + 1;    // 0-based index
  int day = localTime->tm_mday;
  int hour = localTime->tm_hour;
  int minute = localTime->tm_min;
  int second = localTime->tm_sec;

  std::stringstream ss;
  ss << hour << ":" << minute;
  return ss.str();
}

std::string utc_time_for_weather_api()
{
  std::time_t now = std::time(0); 

  // Convert to a tm structure (local time)
  std::tm* localTime = std::localtime(&now);

  // Access individual components
  int year = localTime->tm_year + 1900; // Years since 1900
  int month = localTime->tm_mon + 1;    // 0-based index
  int day = localTime->tm_mday;
  int hour = localTime->tm_hour;
  int minute = localTime->tm_min;
  int second = localTime->tm_sec;


  // using sprintf to make the string to pad leading zeros on single digit months, days, hours, minutes, and seconds
  char buf[21];
  sprintf(buf, "%04d-%02d-%02dT%02d:%02d:%02dZ", year, month, day, hour, minute, second);
  std::string text_date(buf);
  return text_date;

}