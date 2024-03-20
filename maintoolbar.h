#ifndef MAINTOOLBAR_H
#define MAINTOOLBAR_H


#include <QToolBar>

#include <QActionGroup>
#include <QAction>


class MainToolBar : public QToolBar
{
    Q_OBJECT

public:
    MainToolBar(QWidget* parent = nullptr);

private:
    QActionGroup* actionsGroup;

    QAction*      managerAction;
    QAction*      notesAction;
    QAction*      trackerAction;
    QAction*      plannerAction;

signals:
    void managerActionTriggered();
    void notesActionTriggered();
    void trackerActionTriggered();
    void plannerActionTriggered();
};


#endif // MAINTOOLBAR_H
