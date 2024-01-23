#ifndef QUESTION_MANAGER_H
#define QUESTION_MANAGER_H

#include <string>
#include "question.h"

class QuestionManager {
    std::string db_path;
    std::string file_path;

public:
    QuestionManager();

    // db is json/sqlite3 file, path_to_files is where md files are stored
    // return true/false on success
    bool init_database(std::string db, std::string path_to_files);

    virtual void create_new_question() = 0;
    virtual void get_random_question() = 0;
    virtual void get_all_questions() = 0;
    virtual void delete_question() = 0;

};

#endif