#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H


#include <QDialog>
#include <QGridLayout>

#include <QListWidget>
#include <QIcon>


class PreferencesDialog : public QDialog
{
public:
    PreferencesDialog(QWidget* parent = nullptr);


    QGridLayout*     mainLayout;

    QListWidget*     optionsList;
    QListWidgetItem* generalItem;
    QListWidgetItem* mailItem;
    QListWidgetItem* notesItem;
    QListWidgetItem* trackerItem;
    QListWidgetItem* plannerItem;

    QListWidget*     optionsList1;
    QListWidgetItem* optionItem1;
};

#endif // PREFERENCESDIALOG_H
