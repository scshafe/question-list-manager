// #include <gtkmm.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/application.h>
#include <gtkmm/stack.h>
#include <gtkmm.h>

#include <gdkmm/color.h>

#include <iostream>

#include "main-window.h"


MainWindow::MainWindow()
: view_stacker(),
  day_container(Gtk::ORIENTATION_VERTICAL),
  header(),
  question_card(),
  night_time_widget()
{

  // (widgth, height)  480x272 are the LCD cape screen dimensions from 4dsystems
  set_default_size(480, 272);

  // Gtk::Stack allows switching back and forth between child Gtk objects
  add(view_stacker);

  // Add and initialize the day time container
  view_stacker.add(day_container);
  day_container.pack_start(header, Gtk::PACK_SHRINK);
  header.set_vexpand(false);
  header.set_valign(Gtk::ALIGN_BASELINE);  

  day_container.pack_start(question_card);
  question_card.set_vexpand(true);
  question_card.set_valign(Gtk::ALIGN_FILL);
  

  // Add the night time widget
  view_stacker.add(night_time_widget);

  day_color.set_red(1.0);
  day_color.set_green(1.0);
  day_color.set_blue(1.0);
  day_color.set_alpha(1.0);  

  night_color.set_red(1.0);
  night_color.set_green(0.0);
  night_color.set_blue(0.0);
  night_color.set_alpha(0.7);

  switch_to_day();
  is_day = true;

  show_all();

  timeout_value = 4000;
  m_timer_number = 0;
  
  // sigc::connection Glib::SignalTimeout::connect(const sigc::slot<bool>& slot,
  //                                     unsigned int interval, int priority = Glib::PRIORITY_DEFAULT);

  // Creation of a new object prevents long lines and shows us a little
  // how slots work.  We have 0 parameters and bool as a return value
  // after calling sigc::bind.
  // sigc::slot<void> my_slot = sigc::bind(sigc::mem_fun(*this,
  //             &MainWindow::toggle_day_night));
  //             // &TimerExample::on_timeout), m_timer_number);

  // // This is where we connect the slot to the Glib::signal_timeout()
  // sigc::connection conn = Glib::signal_timeout().connect(my_slot,
  //         timeout_value);

  Glib::signal_timeout().connect(sigc::mem_fun(*this, &MainWindow::toggle_day_night), timeout_value);
}



MainWindow::~MainWindow()
{
}

void MainWindow::on_button_clicked()
{
  std::cout << "MainWindow button clicked" << std::endl;
}

void MainWindow::switch_to_day()
{
  view_stacker.set_visible_child(day_container);
  override_background_color(day_color);
}

void MainWindow::switch_to_night()
{
  view_stacker.set_visible_child(night_time_widget);
  override_background_color(night_color);
}

// void MainWindow::toggle_day_night(int timer_number)
bool MainWindow::toggle_day_night()
{
  if ((void *)(view_stacker.get_visible_child()) == (void *)&night_time_widget)
  // if (!is_day)
  {
    is_day = true;
    switch_to_day();
  }
  else
  {
    is_day = false;
    switch_to_night();
  }
  return true;
}
