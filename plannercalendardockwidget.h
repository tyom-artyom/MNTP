#ifndef PLANNERCALENDARDOCKWIDGET_H
#define PLANNERCALENDARDOCKWIDGET_H


#include <QDockWidget>

#include <QCalendarWidget>


class PlannerCalendarDockWidget : public QDockWidget
{
    Q_OBJECT

public:
    PlannerCalendarDockWidget(QWidget* parent = nullptr);

private:
    QCalendarWidget* calendarWidget;
};


#endif // PLANNERCALENDARDOCKWIDGET_H
