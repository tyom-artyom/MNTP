#ifndef MAINWIDGET_H
#define MAINWIDGET_H


#include <QStackedWidget>

#include "managerwidget.h"
#include "noteswidget.h"
#include "trackerwidget.h"
#include "plannerwidget.h"


class MainWidget : public QStackedWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget* parent = nullptr);

private:
    ManagerWidget* managerWidget;
    NotesWidget*   notesWidget;
    TrackerWidget* trackerWidget;
    PlannerWidget* plannerWidget;

public slots:
    void setManagerWidget();
    void setNotesWidget();
    void setTrackerWidget();
    void setPlannerWidget();
};


#endif // MAINWIDGET_H
