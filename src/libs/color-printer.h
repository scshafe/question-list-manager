#ifndef COLOR_PRINTER_H
#define COLOR_PRINTER_H


#include <iostream>
#include <string>
#include "color.hpp"
#include <sstream>
namespace ColorPrinter
{
    
    template <typename ... Args >
    void print_error(Args ... args)
    {
        std::stringstream ss;
        (ss << "Error: " << ... << args);
        std::cout << termcolor::red << ss.str() << termcolor::reset << std::endl;
    }

    template <typename ... Args >
    void print_warning(Args ... args)
    {
        std::stringstream ss;
        (ss << "Warning: " << ... << args);
        std::cout << termcolor::bright_magenta << ss.str() << termcolor::reset << std::endl;
    }

    template <typename ... Args >
    void print_info(Args ... args)
    {
        std::stringstream ss;
        (ss << ... << args);
        std::cout << ss.str() << std::endl;
    }

};

namespace CP = ColorPrinter;

#endif
