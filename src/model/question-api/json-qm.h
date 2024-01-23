#ifndef JSON_QM_H
#define JSON_QM_H

#include "question-manager.h"


class JsonQM : public QuestionManager {

public:
    JsonQM();

    void create_new_question();
    void get_random_question();
    void get_all_questions();
    void delete_question();
};

#endif