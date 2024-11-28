#ifndef QUESTION_CARD_H
#define QUESTION_CARD_H

#include <string>
#include <gtkmm/bin.h>
#include <gtkmm/button.h>

class QuestionCard : public Gtk::Bin
{
public:
    QuestionCard();
    // QuestionCard(std::string button_test);

    Gtk::Button button;

    void on_question_clicked();

    int select_text;

    std::string word;
    std::string definition;
    // in the future add example sentence

// protected:
    // Gtk::Button m_button;

    void increment_text_counter();
    std::string get_text_item();
    
};


#endif