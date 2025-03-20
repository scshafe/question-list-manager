


#include "color-printer.h"
#include <sstream>
#include <iostream>



void ColorPrinter::print_info(std::string& message)
{
    std::cout << termcolor::reset << message << std::endl;
}


void ColorPrinter::print_warning(std::string& message)
{
    std::cout << termcolor::green << message << termcolor::reset << std::endl;
}


