#include "preferencesdialog.h"

PreferencesDialog::PreferencesDialog(QWidget* parent) : QDialog(parent)
{
    setWindowTitle(tr("Preferences"));
    setMinimumSize(300, 300);


    mainLayout   = new QGridLayout(this);

    optionsList  = new QListWidget(this);
    generalItem  = new QListWidgetItem(optionsList);
    mailItem     = new QListWidgetItem(optionsList);
    notesItem    = new QListWidgetItem(optionsList);
    trackerItem  = new QListWidgetItem(optionsList);
    plannerItem  = new QListWidgetItem(optionsList);

    optionsList1 = new QListWidget(this);
    optionItem1  = new QListWidgetItem(tr("Item1"), optionsList1);


    generalItem->setText(tr("General"));
    mailItem->setText(tr("Mail"));
    notesItem->setText(tr("Notes"));
    trackerItem->setText(tr("Tracker"));
    plannerItem->setText(tr("Planner"));

    generalItem->setIcon(QIcon(":/icons/gear.png"));
    mailItem->setIcon(QIcon(":/icons/mail.png"));
    notesItem->setIcon(QIcon(":/icons/notes.png"));
    trackerItem->setIcon(QIcon(":/icons/tracker.png"));
    plannerItem->setIcon(QIcon(":/icons/planner.png"));

    generalItem->setSizeHint(QSize(0, 50));
    mailItem->setSizeHint(QSize(0, 50));
    notesItem->setSizeHint(QSize(0, 50));
    trackerItem->setSizeHint(QSize(0, 50));
    plannerItem->setSizeHint(QSize(0, 50));


    optionsList->addItem(generalItem);
    optionsList->addItem(mailItem);
    optionsList->addItem(notesItem);
    optionsList->addItem(trackerItem);
    optionsList->addItem(plannerItem);

    optionsList->addItem(optionItem1);


    mainLayout->addWidget(optionsList, 0, 0);
    mainLayout->setColumnStretch(0, 1);

    mainLayout->addWidget(optionsList1, 0, 1);
    mainLayout->setColumnStretch(1, 5);


    setLayout(mainLayout);
}
