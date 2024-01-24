// #include <gtkmm.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/application.h>

#include <iostream>

#include "main-window.h"

MainWindow::MainWindow()
: question_card("yeet button")
// : m_button("Hello World")   // creates a new button with label "Hello World".
{
  // Sets the border width of the window.
  set_border_width(120);

  // When the button receives the "clicked" signal, it will call the
  // on_button_clicked() method defined below.
  question_card.signal_clicked().connect(sigc::mem_fun(*this,
              &MainWindow::on_button_clicked));

  // This packs the button into the Window (a container).
  add(question_card);

  // The final step is to display this newly created widget...
  question_card.show();
}



MainWindow::~MainWindow()
{
}

void MainWindow::on_button_clicked()
{
  std::cout << "MainWindow button clicked" << std::endl;
}