#include <iostream>
#include <sstream>
#include <ctime>

#include "time-widget.h"
#include "time-helper.h"

TimeWidget::TimeWidget()
: Gtk::Label()
{
    update_time();
    
}

TimeWidget::~TimeWidget()
{

}

void TimeWidget::update_time()
{
  time_text = utc_time_for_display();
  set_text(time_text);
}