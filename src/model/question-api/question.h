#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>
#include <ctime>
// #include <chrono>


class Question {
    unsigned int id;
    time_t creation_timestamp;

    std::string question_title;
    std::string path_to_file;
    std::vector<std::string> tags;

public:
    Question();
    std::string get_human_readable_timestamp();

    

};

#endif