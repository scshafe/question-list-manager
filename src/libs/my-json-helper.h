#ifndef MY_JSON_HELPER_H
#define MY_JSON_HELPER_H


#include <json/json.h>
#include <string>



namespace MyJsonHelper
{
  bool build_json_root(Json::Value &root, std::string rawJson);

};

#endif