// #include "question-manager.h"
// #include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "json/json.h"


void begin_application();

void begin_application()
{
    Json::Value root;

    std::ifstream data_file;
    data_file.open("json_data.json");

    data_file >> root;

    std::string file_name = root.get("title", "default-name").asString();
    std::cout << file_name << std::endl;

    data_file.close();

}

int main()
{
    // init


    begin_application();
}