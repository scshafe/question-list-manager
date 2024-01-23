#include <ctime>
#include "question.h"

Question::Question()
{
    id = 0;
    creation_timestamp = time(NULL);
    question_title = "hello-title";
    path_to_file = "/hello/path";
    tags;
}

std::string Question::get_human_readable_timestamp()
{
    return "hello world";
}