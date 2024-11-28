
#include <gtkmm/box.h>
#include <gtkmm/label.h>

#include "header-widget.h"

Header::Header() :
Gtk::Box(),
tm(),
tempwidget()
{
    pack_start(tm);

    pack_start(tempwidget);

    // temp_high.set_text("high: 80 degrees");
    // temp_low.set_text("low: 40 degrees");

    // pack_start(temp_high);
    // pack_start(temp_low);

    show_all_children();
    // add(temp_high);
    // temp_high.show();
}

Header::~Header()
{
}

