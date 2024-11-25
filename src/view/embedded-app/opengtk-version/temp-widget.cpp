#include <sstream>
#include <iostream>
#include <string>
#include <glib.h>
// #include <libgweather/gweather.h>
#include <curl/curl.h>
#include <json/json.h>


#include "temp-widget.h"
#include "time-helper.h"

TempWidget::TempWidget()
{
  temp_high = 100;
  temp_low = 0;
  update_weather();


  t_curr.set_text(print_temp(temp_current));
  t_high.set_text(print_temp(temp_high));
  t_low.set_text(print_temp(temp_low));

  pack_start(t_curr);
  pack_start(t_high);
  pack_start(t_low);

  show_all_children();
}

TempWidget::~TempWidget()
{

}

size_t WriteCallback(char *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}



void TempWidget::update_weather()
{
  CURL *easy_handle;
  CURLcode res;

  std::string rawJson;
 
  easy_handle = curl_easy_init();
  if(easy_handle) {
    std::cout << "sending curl request" << std::endl;

    // curl_easy_setopt sets options for when the request is performed via curl_easy_perform
    curl_easy_setopt(easy_handle, CURLOPT_URL, create_weather_url().c_str());
    // sets the callback function used for writing the response
    curl_easy_setopt(easy_handle, CURLOPT_WRITEFUNCTION, WriteCallback);
    // tells curl to use rawJson as the write buffer in the callback
    curl_easy_setopt(easy_handle, CURLOPT_WRITEDATA, &rawJson);
 
    std::cout << "after sending curl request" << std::endl;
    /* Perform the request, res gets the return code */
    res = curl_easy_perform(easy_handle);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

                /* always cleanup */
    curl_easy_cleanup(easy_handle);
  }

  const auto rawJsonLength = static_cast<int>(rawJson.length());

  std::cout << rawJson << std::endl;
  
  Json::Value root;
  JSONCPP_STRING err;

  // reader.parse(ss.str(), root);

  Json::CharReaderBuilder builder;
  const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
  if (!reader->parse(rawJson.c_str(), rawJson.c_str() + rawJsonLength, &root,
                      &err)) {
    std::cout << "error: " << err << std::endl;
    return;
  }
  temp_current = stof(root["data"][0]["coordinates"][0]["dates"][0]["value"].asString());
  std::cout << "current temp: " << temp_current << std::endl;

  // t_curr.set_text(print_temp(temp_current));


}


std::string TempWidget::create_weather_url(){
  std::stringstream ss;
  ss << "https://" << getenv("BBB_WEATHER_USERNAME") << ":" << getenv("BBB_WEATHER_PASS") << "@api.meteomatics.com/" << utc_time_for_weather_api() << "/t_2m:F/41.8755616,-87.6244212/json?model=mix";
  std::cout << ss.str() << std::endl;
  return ss.str();
}


std::string TempWidget::print_temp(const float& temp)
{
  std::cout << "printing temp of: " << temp << std::endl;
  return std::to_string(temp) + "°F";
}



// void TempWidget::update_weather()
// {
//     // Initialize GWeather library
//     g_type_init();
    
//     // Location string for the weather (you can use any valid location)
//     const char* location = "San Francisco";  // Example location, can be changed
//     const char* icao_code = "KSFO";
//     const gdouble glatitude = 37.619722;
//     const gdouble glongitude = -122.364722;


//     // Create a GWeatherLocation object for the desired location
//     GWeatherLocation* weather_location = gweather_location_new_detached(location, icao_code, glatitude, glongitude);
    
//     if (weather_location == nullptr)
//     {
//         std::cerr << "Unable to get weather location: " << location << std::endl;
//         return;
//     }

//     GWeatherInfo* weather_info = gweather_info_new(weather_location);

//     if (weather_info == nullptr)
//     {
//         std::cerr << "Unable to get weather information: " << std::endl;
//         return;
//     }
    
//     gdouble* g_temp = new gdouble;

//     if (!gweather_info_get_value_temp(weather_info, GWEATHER_TEMP_UNIT_FAHRENHEIT, g_temp))
//     {
//         std::cout << "gweather_info_get_value_temp is INVALID" << std::endl;
//     }


    


//     // Output the temperature
//     std::cout << "Current temperature in " << location << ": " << (int)(*g_temp) << "°F" << std::endl;

//     temp_current = (int)g_temp;

//     // Clean up
//     // g_object_unref(current_weather);
//     // g_object_unref(weather_location);
    
//     return;
// }