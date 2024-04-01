#include "mainwindow.h"


void MainWindow::removeAllDockWidgets()
{
    QList<QDockWidget*> dockWidgets = findChildren<QDockWidget*>();

    for (QDockWidget* dockWidget : dockWidgets)
    {
        removeDockWidget(dockWidget);
    }
}

void MainWindow::addPlannerCalendarDockWidget()
{
    addDockWidget(Qt::LeftDockWidgetArea, plannerCalendarDockWidget);

    plannerCalendarDockWidget->show();
}

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    setWindowTitle("MNTP");

    QApplication::setStyle(QStyleFactory::create(settings.value("appStyle", "DefaultStyle").toString()));

    //  mainWidget{{{
        mainWidget = new MainWidget(this);

        setCentralWidget(mainWidget);
    //}}}

    //  mainMenuBar{{{
        mainMenuBar = new MainMenuBar(this);

        setMenuBar(mainMenuBar);
    //}}}

    //  mainToolBar{{{
        mainToolBar = new MainToolBar(this);

        addToolBar(Qt::LeftToolBarArea, mainToolBar);

        QObject::connect(mainToolBar, &MainToolBar::managerActionTriggered, mainWidget, &MainWidget::setManagerWidget);
        QObject::connect(mainToolBar, &MainToolBar::notesActionTriggered,   mainWidget, &MainWidget::setNotesWidget);
        QObject::connect(mainToolBar, &MainToolBar::trackerActionTriggered, mainWidget, &MainWidget::setTrackerWidget);
        QObject::connect(mainToolBar, &MainToolBar::plannerActionTriggered, mainWidget, &MainWidget::setPlannerWidget);
    //}}}

    //  mainDockWidgets{{{
        plannerCalendarDockWidget = new PlannerCalendarDockWidget(this);

        addPlannerCalendarDockWidget();

        QObject::connect(mainToolBar, &MainToolBar::managerActionTriggered, this, &MainWindow::removeAllDockWidgets);
        QObject::connect(mainToolBar, &MainToolBar::notesActionTriggered,   this, &MainWindow::removeAllDockWidgets);
        QObject::connect(mainToolBar, &MainToolBar::trackerActionTriggered, this, &MainWindow::removeAllDockWidgets);
        QObject::connect(mainToolBar, &MainToolBar::plannerActionTriggered, this, &MainWindow::removeAllDockWidgets);
        QObject::connect(mainToolBar, &MainToolBar::plannerActionTriggered, this, &MainWindow::addPlannerCalendarDockWidget);
    //}}}
}
