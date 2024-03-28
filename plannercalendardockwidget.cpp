#include "plannercalendardockwidget.h"


PlannerCalendarDockWidget::PlannerCalendarDockWidget(QWidget* parent) : QDockWidget(parent)
{
    setWindowTitle(tr("Calendar"));

    calendarWidget = new QCalendarWidget(this);

    calendarWidget->setStyleSheet(R"(
    QCalendarWidget QToolButton
    {
        icon-size: 24px;
    }

    QCalendarWidget #qt_calendar_prevmonth
    {
        qproperty-icon: url(:icons/caret_back.png);
    }

    QCalendarWidget #qt_calendar_nextmonth
    {
        qproperty-icon: url(:icons/caret_forward.png);
    }
    )");

    setWidget(calendarWidget);
}
