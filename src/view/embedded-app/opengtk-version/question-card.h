#ifndef QUESTION_CARD_H
#define QUESTION_CARD_H

#include <string>
#include <gtkmm/button.h>

class QuestionCard : public Gtk::Button
{
public:
    QuestionCard();
    QuestionCard(std::string button_test);

    void on_question_clicked();

// protected:
    // Gtk::Button m_button;

    
};


#endif