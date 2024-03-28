#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H


#include <QDialog>

#include <QHBoxLayout>

#include <QListWidget>

#include <QIcon>


class PreferencesDialog : public QDialog
{
public:
    PreferencesDialog(QWidget* parent = nullptr);

private:
    QHBoxLayout*     layout;

    QListWidget*     optionsList;
    QListWidget*     optionsList1;

    QListWidgetItem* generalItem;
    QListWidgetItem* managerItem;
    QListWidgetItem* notesItem;
    QListWidgetItem* trackerItem;
    QListWidgetItem* plannerItem;

    QListWidgetItem* optionItem1;
};


#endif // PREFERENCESDIALOG_H
