

#include "color-printer.h"


std::ostream ColorPrinter::os( NULL );
std::filebuf fb;

void ColorPrinter::initialize_logs(std::string& filename)
{
    #ifdef DEBUG
      //os.rdbuf(os.rdbuf());
      return;
    #else
      fb.open(filename.c_str(), std::ios_base::out);
      os.rdbuf(&fb);
    #endif
}

void ColorPrinter::print(std::stringstream& ss, std::basic_ostream<char>& colour(std::basic_ostream<char>& stream))
{
    #ifdef DEBUG
      std::cout << colour << ss.str() << termcolor::reset << std::endl;
    #else
      os << ss.str() << std::endl;
    #endif
}

