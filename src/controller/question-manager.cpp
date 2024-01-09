#include "question-manager.h"
// #include <stdlib.h>
#include <iostream>
#include "json.h"

void begin_application()
{
    Json::Value root;

    std::fstream data_file;
    data_file.open("json_data.json", std::stream::in);

    data_file >> root;

    std::string file_name = root.get("title", "default-name").asString();
    std::cout << file_name << std::endl;

    data_file.close();

}