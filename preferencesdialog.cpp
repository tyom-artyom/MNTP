#include "preferencesdialog.h"


PreferencesDialog::PreferencesDialog(QWidget* parent) : QDialog(parent)
{
    setWindowTitle(tr("Preferences"));
    setMinimumSize(300, 300);

    layout       = new QHBoxLayout(this);

    optionsList  = new QListWidget(this);
    optionsList1 = new QListWidget(this);

    generalItem  = new QListWidgetItem(QIcon(":/icons/gear.png"),    tr("General"), optionsList);
    managerItem  = new QListWidgetItem(QIcon(":/icons/manager.png"), tr("Manager"), optionsList);
    notesItem    = new QListWidgetItem(QIcon(":/icons/notes.png"),   tr("Notes"),   optionsList);
    trackerItem  = new QListWidgetItem(QIcon(":/icons/tracker.png"), tr("Tracker"), optionsList);
    plannerItem  = new QListWidgetItem(QIcon(":/icons/planner.png"), tr("Planner"), optionsList);

    optionItem1  = new QListWidgetItem(tr("Item1"), optionsList1);

    generalItem->setSizeHint(QSize(0, 50));
    managerItem->setSizeHint(QSize(0, 50));
    notesItem  ->setSizeHint(QSize(0, 50));
    trackerItem->setSizeHint(QSize(0, 50));
    plannerItem->setSizeHint(QSize(0, 50));

    setLayout(layout);

    layout->addWidget(optionsList, 0);
    layout->addWidget(optionsList1, 0);

    optionsList->addItem(generalItem);
    optionsList->addItem(managerItem);
    optionsList->addItem(notesItem);
    optionsList->addItem(trackerItem);
    optionsList->addItem(plannerItem);

    optionsList1->addItem(optionItem1);
}
