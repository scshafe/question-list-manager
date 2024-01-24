#include <string>
#include <iostream>
#include <gtkmm/button.h>
#include "question-card.h"


QuestionCard::QuestionCard() :
Gtk::Button("default button")
{
    
    // add(m_button);

    // m_button.show();

}

QuestionCard::QuestionCard(std::string button_test) :
Gtk::Button(button_test)
{
    set_border_width(60);
    // add(m_button);

    // m_button.show();

}


void QuestionCard::on_question_clicked()
{
  std::cout << "Question clicked" << std::endl;
}