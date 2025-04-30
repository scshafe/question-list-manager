#ifndef COLOR_PRINTER_H
#define COLOR_PRINTER_H


#include <iostream>
#include <fstream>
#include <string>
#include "color.hpp"
#include <sstream>
namespace ColorPrinter
{
    extern std::ostream os;
    

    void initialize_logs(std::string& filename); 
    void print(std::stringstream& ss, std::basic_ostream<char>& colour(std::basic_ostream<char>& stream));


    template <typename ... Args >
    void print_error(Args ... args)
    {
        std::stringstream ss;
        (ss << "Error: " << ... << args);
        print(ss, termcolor::red);
        os << termcolor::red << ss.str() << termcolor::reset << std::endl;
    }

    template <typename ... Args >
    void print_warning(Args ... args)
    {
        std::stringstream ss;
        (ss << "Warning: " << ... << args);
        print(ss, termcolor::bright_magenta);
        os << termcolor::bright_magenta << ss.str() << termcolor::reset << std::endl;
    }

    template <typename ... Args >
    void print_important(Args ... args)
    {
        std::stringstream ss;
        (ss << ... << args);
        print(ss, termcolor::green);
        os << termcolor::green << ss.str() << termcolor::reset << std::endl;
    }

    template <typename ... Args >
    void print_info(Args ... args)
    {
        std::stringstream ss;
        (ss << ... << args);
        os << ss.str() << std::endl;
        print(ss, termcolor::blue);
    }


};

namespace CP = ColorPrinter;

#endif
