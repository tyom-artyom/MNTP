#ifndef CALENDARDOCKWIDGET_H
#define CALENDARDOCKWIDGET_H


#include <QMainWindow>

#include <QDockWidget>

#include <QCalendarWidget>


class CalendarDockWidget : public QDockWidget
{
    Q_OBJECT

public:
    CalendarDockWidget(QWidget* parent = nullptr);

private:
    QCalendarWidget* calendarWidget;

public slots:
    void addWidget();
};


#endif // CALENDARDOCKWIDGET_H
