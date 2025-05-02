#include <string>
#include <iostream>
#include <gtkmm/button.h>

#include "question-card.h"
#include "../controller/vocabulary-manager.h"
#include "../model/vocab-item.h"
#include "color-printer.h"

QuestionCard::QuestionCard() :
Gtk::Box(),
vocab_button(),
next_button()
{
  select_text = 0;
  vm = VocabularyManager::get_instance();
  
  get_next_vocab_item();
  CP::print_info("just got: ", vocab_item.word);
  CP::print_info("select_text: ", select_text);
  
  std::string tmp = get_text_item();
  CP::print_info("setting vocab button label: ", tmp);
  vocab_button.set_label(tmp);
  vocab_button.set_size_request(400, 200);
  vocab_button.set_overflow(false);
  //vocab_button.set_default_size(400, 200); 

  next_button.set_label("next");

  pack_start(vocab_button/*, Gtk::PACK_EXPAND_WIDGET*/);
  vocab_button.signal_clicked().connect(sigc::mem_fun(*this, &QuestionCard::on_question_clicked));

  pack_start(next_button, Gtk::PACK_SHRINK);
  next_button.signal_clicked().connect(sigc::mem_fun(*this, &QuestionCard::on_next_clicked));
  show_all_children();

}



void QuestionCard::on_question_clicked()
{
  increment_text_counter();
  vocab_button.set_label(get_text_item());
}

void QuestionCard::on_next_clicked()
{
  get_next_vocab_item();
  vocab_button.set_label(get_text_item());
}

void QuestionCard::increment_text_counter()
{
  select_text = ++select_text % 3;
}

std::string QuestionCard::get_text_item()
{
  std::string tmp;
  if (select_text == 0)
  {
    tmp =  vocab_item.word;
  }
  else if (select_text == 1)
  {
    tmp = vocab_item.definition;
  }
  else if (select_text == 2)
  {
    tmp =  vocab_item.example_sentence;
  }
  else
  {
    CP::print_error("get_text_item(), select_text: ", select_text);
    tmp = "Error in get_text_item()";
  }
  CP::print_info("get_text_item() returning: ", tmp);
  return tmp;
}



void QuestionCard::get_next_vocab_item()
{
  select_text = 0;
  vocab_item = vm->get_next_vocab_item();
  CP::print_info("Retrieved word: ", vocab_item.word);
}

//VocabItem QuestionCard::get_prev_vocab_item()
//{
//  select_text = 0;
//  vocab_item = vm->get_prev_vocab_item();
//}



