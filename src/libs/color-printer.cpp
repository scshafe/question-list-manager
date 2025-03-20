


#include "color-printer.h"


void ColorPrinter::print_error(std::string error_message)
{
    std::cout << termcolor::red << "Error:" << termcolor::blue << error_message << std::endl;
  }
