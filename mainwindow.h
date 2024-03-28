#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QSettings>

#include <QMainWindow>

#include "mainwidget.h"
#include "mainmenubar.h"
#include "maintoolbar.h"
#include "plannercalendardockwidget.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);

private:
    QSettings                  settings;

    MainWidget*                mainWidget;
    MainMenuBar*               mainMenuBar;
    MainToolBar*               mainToolBar;
    PlannerCalendarDockWidget* plannerCalendarDockWidget;

private slots:
    void removeAllDockWidgets();
    void addPlannerCalendarDockWidget();
};


#endif // MAINWINDOW_H
