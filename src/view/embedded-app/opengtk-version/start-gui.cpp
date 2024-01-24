#include <gtkmm/application.h>
#include "main-window.h"

// int start_gui()
// {
//     auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

// //   HelloWorld helloworld;
//   MainWindow main_window;

//   //Shows the window and returns when it is closed.
//   return app->run(main_window);
// }


// scp -r /home/cole/git-projects/question-list-manager/src/view/embedded-app/opengtk-version debian@192.168.10.2:/home/debian/gtkmm-example/practice
// g++ start-gui.cpp main-window.cpp question-card.cpp -o simple `pkg-config gtkmm-3.0 --cflags --libs`


// FOR TESTING PURPOSES

int main(int argc, char **argv)
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  MainWindow main_window;

  //Shows the window and returns when it is closed.
  return app->run(main_window);
}