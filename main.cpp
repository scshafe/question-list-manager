#include <gtkmm/application.h>
#include "src/view/main-window.h"
#include <iostream>
#include <boost/program_options.hpp>




int main(int argc, char **argv)
{
  namespace po = boost::program_options;
  po::options_description desc("Allowed options");


  desc.add_options()
      ("help", "produce help message")
      // ("compression", po::value<int>(), "set compression level")
  ;

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);    

  if (vm.count("help")) {
      std::cout << desc << "\n";
      return 1;
  }

  // if (vm.count("compression")) {
  //     cout << "Compression level was set to " 
  // << vm["compression"].as<int>() << ".\n";
  // } else {
  //     cout << "Compression level was not set.\n";
  // }

  if (__cplusplus == 202101L) std::cout << "C++23";
    else if (__cplusplus == 202002L) std::cout << "C++20";
    else if (__cplusplus == 201703L) std::cout << "C++17";
    else if (__cplusplus == 201402L) std::cout << "C++14";
    else if (__cplusplus == 201103L) std::cout << "C++11";
    else if (__cplusplus == 199711L) std::cout << "C++98";
    else std::cout << "pre-standard C++." << __cplusplus;
    std::cout << "\n";


    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  MainWindow main_window;

  //Shows the window and returns when it is closed.
  return app->run(main_window);
}