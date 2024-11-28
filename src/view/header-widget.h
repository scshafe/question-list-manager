#ifndef HEADER_H
#define HEADER_H

#include <gtkmm/box.h>
#include <gtkmm/label.h>

#include "time-widget.h"
#include "temp-widget.h"

class Header : public Gtk::Box
{
public:
  Header();
  virtual ~Header();

  TimeWidget tm;
  TempWidget tempwidget;

  // Gtk::Label temp_high;
  // Gtk::Label temp_low;

  // float t_high;
  // float t_low;

};

#endif