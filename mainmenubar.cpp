#include "mainmenubar.h"


void MainMenuBar::exitSlot()
{
    QApplication::quit();
}

void MainMenuBar::preferencesSlot()
{
    preferencesDialog->exec();
}

MainMenuBar::MainMenuBar(QWidget* parent) : QMenuBar(parent)
{
    appMenu           = new QMenu  (tr("&App"),          this);
    editMenu          = new QMenu  (tr("E&dit"),         this);
    viewMenu          = new QMenu  (tr("&View"),         this);

    exitAction        = new QAction(tr("&Exit"),         appMenu);

    preferencesAction = new QAction(tr("&Preferences"),  editMenu);
    preferencesDialog = new PreferencesDialog(           editMenu);

    changeStyleAction = new QAction(tr("&Change style"), viewMenu);
    stylesMenu        = new QMenu  (tr("S&tyles"),       viewMenu);
    availableStyles   =     QStyleFactory::keys();

    addMenu(appMenu);
    addMenu(editMenu);
    addMenu(viewMenu);

    appMenu ->addAction(exitAction);

    editMenu->addAction(preferencesAction);

    viewMenu->addAction(changeStyleAction);
    changeStyleAction->setMenu(stylesMenu);
    for (const QString& availableStyle : availableStyles)
    {
        styleAction = new QAction(availableStyle, stylesMenu);

        stylesMenu->addAction(availableStyle, [&]()
        {
            QApplication::setStyle(QStyleFactory::create(availableStyle));

            settings.setValue("appStyle", availableStyle);
        });
    }

    QObject::connect(exitAction,        &QAction::triggered, this, &MainMenuBar::exitSlot);

    QObject::connect(preferencesAction, &QAction::triggered, this, &MainMenuBar::preferencesSlot);
}
