#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QSettings>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QMainWindow>

#include "mainwidget.h"
#include "mainmenubar.h"
#include "maintoolbar.h"
#include "maindockwidgets.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);

private:
    QSettings        settings;

    MainWidget*      mainWidget;
    MainMenuBar*     mainMenuBar;
    MainToolBar*     mainToolBar;
    MainDockWidgets* mainDockWidgets;

public slots:
    void removeAllDockWidgets();
};


#endif // MAINWINDOW_H
