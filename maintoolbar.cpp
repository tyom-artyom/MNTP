#include "maintoolbar.h"


MainToolBar::MainToolBar(QWidget* parent) : QToolBar(parent)
{
    actionGroup  = new QActionGroup(this);

    setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    managerAction = new QAction(QIcon(":/icons/manager.png"), tr("&Manager"), this);
    notesAction   = new QAction(QIcon(":/icons/notes.png"),   tr("&Notes"),   this);
    trackerAction = new QAction(QIcon(":/icons/tracker.png"), tr("&Tracker"), this);
    plannerAction = new QAction(QIcon(":/icons/planner.png"), tr("&Planner"), this);

    actionGroup  ->setExclusive(true);

    managerAction->setCheckable(true);
    notesAction  ->setCheckable(true);
    trackerAction->setCheckable(true);
    plannerAction->setCheckable(true);

    plannerAction->setChecked(true);

    addAction(managerAction);
    addAction(notesAction);
    addAction(trackerAction);
    addAction(plannerAction);

    actionGroup->addAction(managerAction);
    actionGroup->addAction(notesAction);
    actionGroup->addAction(trackerAction);
    actionGroup->addAction(plannerAction);

    QObject::connect(managerAction, &QAction::triggered, this, &MainToolBar::managerActionTriggered);
    QObject::connect(notesAction,   &QAction::triggered, this, &MainToolBar::notesActionTriggered);
    QObject::connect(trackerAction, &QAction::triggered, this, &MainToolBar::trackerActionTriggered);
    QObject::connect(plannerAction, &QAction::triggered, this, &MainToolBar::plannerActionTriggered);
}
