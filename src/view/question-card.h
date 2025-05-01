#ifndef QUESTION_CARD_H
#define QUESTION_CARD_H

#include <string>
#include <gtkmm/box.h>
#include <gtkmm/button.h>

#include "vocabulary-manager.h"
#include "../model/vocab-item.h"

class QuestionCard : public Gtk::Box
{
public:
    QuestionCard();
    // QuestionCard(std::string button_test);

    Gtk::Button vocab_button;
    Gtk::Button next_button;

    VocabularyManager* vm;

    void on_question_clicked();
    void on_next_clicked();

    int select_text;

    VocabItem vocab_item;
    // in the future add example sentence

// protected:
    // Gtk::Button m_button;

    void increment_text_counter();
    std::string get_text_item();
    void get_next_vocab_item();
    void get_prev_vocab_item();
    
};


#endif
