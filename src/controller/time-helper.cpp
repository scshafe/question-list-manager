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

  char buf[5];
  sprintf(buf, "%d:%02d", hour, minute);
  std::string text_time(buf);
  return text_time;
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

bool is_day()
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

  return hour >= 8 && hour < 20;
}

int time_until_sun_change()
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

  int ms_since_midnight = 1000 * (second + 60 * (minute + 60 * hour));

  if (hour < 8) // before 8:00am
  {
    int _8_am_in_ms = 8 * 60 * 60 * 1000;
    return _8_am_in_ms - ms_since_midnight;
  }
  if (hour < 20) // between 8:00am and 8:00pm
  {
    int _8_pm_in_ms = 20 * 60 * 60 * 1000;
    return _8_pm_in_ms - ms_since_midnight;
  }
  // after 8:00pm
  int _8_am_in_ms = 8 * 60 * 60 * 1000;
  int ms_in_a_day = 24 * 60 * 60 * 1000;

  return (ms_in_a_day - ms_since_midnight) + _8_am_in_ms;
}