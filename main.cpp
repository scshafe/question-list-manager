#include <gtkmm/application.h>
#include "src/view/main-window.h"
#include <iostream>
#include <fstream>
#include <boost/program_options.hpp>

#include "src/model/vocabulary-retriever.h"
#include "src/libs/color-printer.h"
namespace po = boost::program_options;


int main(int argc, char **argv)
{
  std::string logfile = "question-manager.logs";
  CP::initialize_logs(logfile);
  CP::print_important("Using C++ standard: ", __cplusplus);

// Command-line **only** options
  po::options_description desc("Allowed options");
  desc.add_options()
    ("help", "produce help message")
    ("database-file", po::value<std::string>(), "set vocabulary database file location")
  ;

  // Configuration File options (command-line can override)
  po::options_description config("Configuration");
  config.add_options()
    ("weather-api-username", po::value<std::string>(), "set the username for using meteomatics API")
    ("weather-api-password", po::value<std::string>(), "set the password for using meteomatics API")
    ("groq-api-key", po::value<std::string>(), "set the api key for using groq")
  ;

  // Options available on both command-line and configuration but not shown to the user
  // po::options_description hidden("Hidden options");
  // hidden.add_options()
  //   ("input-file", po::value<string_vector>(), "input file")
  // ;
  

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);  // stores the variables from command-line
  po::notify(vm);


  std::ifstream ifs("/home/debian/motion-sensor-configuration/motion-sensor.cfg");
  po::store(po::parse_config_file(ifs, config), vm);


  if (vm.count("help")) 
  {
    CP::print_info(desc);
    return 0;
  }

  std::string database_file("/home/debian/motion-sensor-configuration/vocabulary-words-test-argument.json");
  std::string weather_api_name, weather_api_pass, groq_api_key;


  if (vm.count("database-file"))
  {
    database_file = vm["database-file"].as<std::string>();
    VocabularyRetriever::set_database_file(database_file);
    CP::print_important("vocabulary database file location was set to ", vm["database-file"].as<std::string>());
  } else 
  {
    CP::print_warning("vocabulary database file location was not set");
  }


  if (vm.count("weather-api-username")) 
  {
    setenv("BBB_WEATHER_USERNAME", vm["weather-api-username"].as<std::string>().c_str(), 1);
    // weather_api_name = vm["weather-api-username"].as<std::string>();
    CP::print_important("weather-api-username set to: ",  vm["weather-api-username"].as<std::string>());
  }
  else
  {
    CP::print_error("Error: weather-api-username not read in");
  }

  if (vm.count("weather-api-password")) 
  {
    setenv("BBB_WEATHER_PASSWORD", vm["weather-api-password"].as<std::string>().c_str(), 1);
    weather_api_pass = vm["weather-api-password"].as<std::string>();
    CP::print_important("weather-api-password set to: ", vm["weather-api-password"].as<std::string>() );
  }

  if (vm.count("groq-api-key")) 
  { setenv("GROQ_API_KEY", vm["groq-api-key"].as<std::string>().c_str(), 1);
    groq_api_key = vm["groq-api-key"].as<std::string>();
    CP::print_important("groq-api-key set to: ",  vm["groq-api-key"].as<std::string>());
  }


  

  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  MainWindow main_window;

  //Shows the window and returns when it is closed.
  return app->run(main_window);
}
