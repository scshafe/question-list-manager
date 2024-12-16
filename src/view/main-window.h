#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/stack.h>

#include <gdkmm/color.h>

#include "header-widget.h"
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
  Gtk::Stack view_stacker;

  Gtk::Box day_container;

  Gdk::RGBA day_color;
  Gdk::RGBA night_color;

  //Member widgets:
  Header header;
  QuestionCard question_card;
  TimeWidget night_time_widget;

  void switch_to_day();
  void switch_to_night();
};

#endif