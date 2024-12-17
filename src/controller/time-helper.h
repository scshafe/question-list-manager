#ifndef TIME_HELPER_H
#define TIME_HELPER_H

#include <string>

std::string utc_time_for_display();
std::string utc_time_for_weather_api();


bool is_day();
int time_until_sun_change();

#endif
