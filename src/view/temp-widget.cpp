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
#include "../libs/color-printer.h"

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
      CP::print_error("curl_easy_perform() failed: ", curl_easy_strerror(res));
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

  char *markup = get_temp_markup_string(temp_current);
  t_curr.set_markup(markup);
  release_temp_markup_string(markup);
}

void TempWidget::update_daily_high_and_low()
{
  char *markup_high = get_temp_markup_string(temp_high);  
  t_high.set_markup(markup_high);
  release_temp_markup_string(markup_high);
  
  char *markup_low = get_temp_markup_string(temp_low);
  t_low.set_markup(markup_low);
  release_temp_markup_string(markup_low);
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
  ss << "https://" << getenv("BBB_WEATHER_USERNAME") << ":" << getenv("BBB_WEATHER_PASSWORD") << "@api.meteomatics.com/" << utc_time_for_weather_api() << "/t_2m:F/41.8755616,-87.6244212/json?model=mix";
  CP::print_important("Meteomatics URL: ", ss.str());
  return ss.str();
}


std::string TempWidget::print_temp(const float& temp)
{
  std::cout << "printing temp of: " << temp << std::endl;
  return std::to_string(temp) + "°F";
}


char *TempWidget::get_temp_color_code(float temp)
{
	if (temp < 20.0) return "blue";
	if (temp < 40.0) return "green";
	if (temp < 60.0) return "yellow";
	if (temp < 80.0) return "orange";
	return "red";
}

char *TempWidget::get_temp_markup_string(float temp)
{
  char *temp_color = get_temp_color_code(temp);
  char *markup = g_markup_printf_escaped("<span color=\"%s\">%d°F</span>", temp_color, temp);
  return markup;
}

void TempWidget::release_temp_markup_string(char* markup)
{
  g_free(markup);
}
