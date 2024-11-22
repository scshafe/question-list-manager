#ifndef TEMP_WIDGET_H
#define TEMP_WIDGET_H

#include <string>

#include <gtkmm/box.h>
#include <gtkmm/label.h>


class TempWidget : public Gtk::Box
{
public:
  TempWidget();
  virtual ~TempWidget();

private:
  float temp_current;
  float temp_high;
  float temp_low;

  Gtk::Label t_curr;
  Gtk::Label t_high;
  Gtk::Label t_low;

  void update_weather();
  std::string create_weather_url();
  std::string print_temp(const float& temp);

};


#endif
