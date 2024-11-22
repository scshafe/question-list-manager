#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm/window.h>
#include <gtkmm/box.h>

#include "header.h"
#include "question-card.h"


class MainWindow : public Gtk::Window
{

public:
  MainWindow();
  virtual ~MainWindow();

protected:
  //Signal handlers:
  void on_button_clicked();

  //Container Widgets: (for holding member widgets)
  Gtk::Box app_container;

  //Member widgets:
  Header header;
  QuestionCard question_card;
};

#endif