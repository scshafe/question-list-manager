#include <string>
#include <iostream>
#include <gtkmm/button.h>

#include "question-card.h"

QuestionCard::QuestionCard() :
Gtk::Bin(),
button()
{
  word = "word";
  definition = "definition";

  select_text = 0;
  button.set_label(get_text_item());


  add(button);
  button.signal_clicked().connect(sigc::mem_fun(*this, &QuestionCard::on_question_clicked));
  show_all_children();

}


void QuestionCard::on_question_clicked()
{
  increment_text_counter();
  button.set_label(get_text_item());
}

void QuestionCard::increment_text_counter()
{
  // change 2 to 3 when adding example sentences
  select_text = ++select_text % 2;
}

std::string QuestionCard::get_text_item()
{
  if (select_text == 0)
  {
    return word;
  }
  if (select_text == 1)
  {
    return definition;
  }
  // if (select_text == 2)
  // {
  //   return example_sentence;
  // }
  return "Error in get_text_item()";
}