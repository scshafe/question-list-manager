// #include "question-manager.h"
// #include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "question-manager.h"
#include "question.h"
#include "json-qm.h"


void begin_application();

void begin_application()
{
    // Json::Value root;

    // std::ifstream data_file;
    // data_file.open("json_data.json");

    // data_file >> root;

    // std::string file_name = root.get("title", "default-name").asString();
    // std::cout << file_name << std::endl;

    // data_file.close();
    JsonQM json_qm;
    QuestionManager& qm = json_qm;
    bool err = qm.init_database("/home/cole/question-manager-db/db.json", "home/cole/question-manager-db/question-files");
    if (err)
    {
        std::cout << "problem initializing Question Manager database" << std::endl;
    }
    else
    {
        std::cout << "set up Question Manager database" << std::endl;
    }
}

int main()
{
    // init


    begin_application();
}