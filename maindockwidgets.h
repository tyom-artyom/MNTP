#ifndef MAINDOCKWIDGETS_H
#define MAINDOCKWIDGETS_H


#include "calendardockwidget.h"


class MainDockWidgets
{
public:
    MainDockWidgets(QWidget* parent);

    CalendarDockWidget* trackerCalendarDockWidget;
    CalendarDockWidget* plannerCalendarDockWidget;
};


#endif // MAINDOCKWIDGETS_H
