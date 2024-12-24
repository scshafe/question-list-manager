#include <iostream>
#include <string>

#include "my-json-helper.h"

bool MyJsonHelper::build_json_root(Json::Value &root, std::string rawJson)
{
  const auto rawJsonLength = static_cast<int>(rawJson.length());
  
  JSONCPP_STRING err;

  Json::CharReaderBuilder builder;
  const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
  if (!reader->parse(rawJson.c_str(), rawJson.c_str() + rawJsonLength, &root,
                      &err)) {
    std::cerr << "Error: unable to parse json" << err << std::endl;
    throw std::runtime_error("Error! exception thrown - unable to parse raw json");
    // return false;
  }
  return true;
}