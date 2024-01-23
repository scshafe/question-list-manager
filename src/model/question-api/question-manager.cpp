
#include <iostream>
#include <fstream>
#include <string>
#include "json/json.h"
#include "question-manager.h"
#include "question.h"

QuestionManager::QuestionManager()
{
    db_path;
    file_path;
}

bool QuestionManager::init_database(std::string db, std::string path_to_files)
{
    db_path = db;
    file_path = path_to_files;
    return true;
}


