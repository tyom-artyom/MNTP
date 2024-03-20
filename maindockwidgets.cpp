#include "maindockwidgets.h"


MainDockWidgets::MainDockWidgets(QWidget* parent)
{
    trackerCalendarDockWidget = new CalendarDockWidget(parent);
    plannerCalendarDockWidget = new CalendarDockWidget(parent);


    trackerCalendarDockWidget->hide();
    plannerCalendarDockWidget->hide();
}
