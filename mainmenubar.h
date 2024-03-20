#ifndef MAINMENUBAR_H
#define MAINMENUBAR_H


#include <QApplication>

#include <QSettings>
#include <QStyleFactory>

#include <QMainWindow>

#include <QMenuBar>
#include <QMenu>
#include <QAction>

#include "preferencesdialog.h"


class MainMenuBar : public QMenuBar
{
    Q_OBJECT

public:
    MainMenuBar(QWidget* parrent = nullptr);

private:
    QSettings          settings;

    QMenu*             appMenu;
    QMenu*             editMenu;
    QMenu*             viewMenu;

    QAction*           exitAction;

    QAction*           preferencesAction;
    PreferencesDialog* preferencesDialog;

    QAction*           changeStyleAction;
    QMenu*             stylesMenu;
    QStringList        availableStyles;
    QAction*           styleAction;
    QString            availableStyle;

public slots:
    void exitSlot();

    void preferencesSlot();
};


#endif // MAINMENUBAR_H
