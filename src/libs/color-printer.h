#ifndef COLOR_PRINTER_H
#define COLOR_PRINTER_H


#include <iostream>
#include <string>
#include "color.hpp"
#include <sstream>
namespace ColorPrinter
{
//template <typename ... Args >
//void print_error(Args ... args);
 
template <typename ... Args >
void print_error(Args ... args)
{
    std::stringstream ss;
    (ss << "Error: " << ... << args);
    std::cout << termcolor::red << ss.str() << termcolor::reset << std::endl;
}


// void print_error(std::string error_message);
  void print_info(std::string& message);
  void print_warning(std::string& message);

 
};

namespace CP = ColorPrinter;

#endif
