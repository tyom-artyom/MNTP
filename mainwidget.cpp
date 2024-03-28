#include "mainwidget.h"


void MainWidget::setManagerWidget()
{
    setCurrentWidget(managerWidget);
}

void MainWidget::setNotesWidget()
{
    setCurrentWidget(notesWidget);
}

void MainWidget::setTrackerWidget()
{
    setCurrentWidget(trackerWidget);
}

void MainWidget::setPlannerWidget()
{
    setCurrentWidget(plannerWidget);
}

MainWidget::MainWidget(QWidget* parent) : QStackedWidget(parent)
{
    managerWidget = new ManagerWidget(this);
    notesWidget   = new NotesWidget(this);
    trackerWidget = new TrackerWidget(this);
    plannerWidget = new PlannerWidget(this);

    addWidget(managerWidget);
    addWidget(notesWidget);
    addWidget(trackerWidget);
    addWidget(plannerWidget);

    setCurrentWidget(plannerWidget);
}
