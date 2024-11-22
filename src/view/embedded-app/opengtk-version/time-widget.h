#ifndef TIME_WIDGET_H
#define TIME_WIDGET_H

#include <string>

#include <gtkmm/label.h>

class TimeWidget : public Gtk::Label
{
public:
  TimeWidget();
  virtual ~TimeWidget();

  std::string time_text;
   

private:
  void update_time();

};

#endif