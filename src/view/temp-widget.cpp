#include <sstream>
#include <iostream>
#include <string>
#include <glib.h>
// #include <libgweather/gweather.h>
#include <curl/curl.h>
#include <json/json.h>


#include "temp-widget.h"
// #include "src/controller/time-helper.h"
#include "../controller/time-helper.h"
#include "../libs/my-json-helper.h"

TempWidget::TempWidget()
{
  if (!weather_api_credentials_valid())
  {
    t_curr.set_text("Weather credentials not set");
    pack_start(t_curr);
  }
  else
  {
    update_weather();

    pack_start(t_curr);
    pack_start(t_high);
    pack_start(t_low);
  }

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



void TempWidget::update_current_temp()
{
  CURL *easy_handle;
  CURLcode res;

  std::string rawJson;
 
  easy_handle = curl_easy_init();
  if(easy_handle) {

    // curl_easy_setopt sets options for when the request is performed via curl_easy_perform
    // sets the callback function used for writing the response
    // tells curl to use rawJson as the write buffer in the callback
    curl_easy_setopt(easy_handle, CURLOPT_URL, create_weather_url().c_str());
    curl_easy_setopt(easy_handle, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(easy_handle, CURLOPT_WRITEDATA, &rawJson);
 
    res = curl_easy_perform(easy_handle);
    /* Check for errors */
    if(res != CURLE_OK)
    {
      t_curr.set_text("Error");
      std::cerr << "Error: curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
      return;
    }

                /* always cleanup */
    curl_easy_cleanup(easy_handle);
  }
  else
  {
    t_curr.set_text("Error");
    std::cerr << "Error: invalid easy_handle" << std::endl;
    return;
  }
  std::cout << rawJson << std::endl;

  Json::Value root;
  if (!MyJsonHelper::build_json_root(root, rawJson))
  {
    t_curr.set_text("Error");
    return;
  }


  temp_current = stof(root["data"][0]["coordinates"][0]["dates"][0]["value"].asString());
  std::cout << "current temp: " << temp_current << std::endl;

  t_curr.set_text(print_temp(temp_current));
}

void TempWidget::update_daily_high_and_low()
{
  
  t_high.set_text(print_temp(100.0));
  t_low.set_text(print_temp(0.0));
}


void TempWidget::update_weather()
{
  update_current_temp();
  update_daily_high_and_low();
}

bool TempWidget::weather_api_credentials_valid()
{
  if(getenv("BBB_WEATHER_USERNAME") == "" || getenv("BBB_WEATHER_PASSWORD") == "")
  {
    return false;
  }
  return true;
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


