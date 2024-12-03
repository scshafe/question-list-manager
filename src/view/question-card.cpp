#include <string>
#include <iostream>
#include <gtkmm/button.h>

#include "question-card.h"
#include "../controller/vocabulary-manager.h"
#include "../model/vocab-item.h"

QuestionCard::QuestionCard() :
Gtk::Bin(),
button()
{

  // VocabularyRetriever* vr = VocabularyRetriever::get_instance();

  VocabularyManager* vm = VocabularyManager::get_instance();
  vocab_item = vm->get_next_vocab_item();

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
  select_text = ++select_text % 3;
}

std::string QuestionCard::get_text_item()
{
  if (select_text == 0)
  {
    return vocab_item.word;
  }
  if (select_text == 1)
  {
    return vocab_item.definition;
  }
  if (select_text == 2)
  {
    return vocab_item.example_sentence;
  }
  return "Error in get_text_item()";
}