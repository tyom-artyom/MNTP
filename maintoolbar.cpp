#include "maintoolbar.h"


MainToolBar::MainToolBar(QWidget* parent) : QToolBar(parent)
{
    actionsGroup  = new QActionGroup(this);

    managerAction = new QAction(QIcon(":/icons/manager.png"), tr("&Manager"), this);
    notesAction   = new QAction(QIcon(":/icons/notes.png"),   tr("&Notes"),   this);
    trackerAction = new QAction(QIcon(":/icons/tracker.png"), tr("&Tracker"), this);
    plannerAction = new QAction(QIcon(":/icons/planner.png"), tr("&Planner"), this);

    setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QObject::connect(managerAction, &QAction::triggered, this, &MainToolBar::managerActionTriggered);
    QObject::connect(notesAction,   &QAction::triggered, this, &MainToolBar::notesActionTriggered);
    QObject::connect(trackerAction, &QAction::triggered, this, &MainToolBar::trackerActionTriggered);
    QObject::connect(plannerAction, &QAction::triggered, this, &MainToolBar::plannerActionTriggered);

    actionsGroup->addAction(managerAction);
    actionsGroup->addAction(notesAction);
    actionsGroup->addAction(trackerAction);
    actionsGroup->addAction(plannerAction);

    managerAction->setCheckable(true);
    notesAction  ->setCheckable(true);
    trackerAction->setCheckable(true);
    plannerAction->setCheckable(true);

    managerAction->setChecked(true);

    actionsGroup ->setExclusive(true);

    addAction(managerAction);
    addAction(notesAction);
    addAction(trackerAction);
    addAction(plannerAction);
}
