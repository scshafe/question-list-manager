#include <iostream>
#include <sstream>
#include <ctime>

#include "time-widget.h"

TimeWidget::TimeWidget()
: Gtk::Label()
{
    update_time();
    
}

TimeWidget::~TimeWidget()
{

}

void TimeWidget::update_time()
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
    time_text = ss.str();
    set_text(time_text);

    // Print the local time
    std::cout << "Current local time: " 
              << year << "-" << month << "-" << day << " " 
              << hour << ":" << minute << ":" << second << std::endl;
}