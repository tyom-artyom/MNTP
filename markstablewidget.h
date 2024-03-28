#ifndef MARKSTABLEWIDGET_H
#define MARKSTABLEWIDGET_H


#include <QTableWidget>
#include <QHeaderView>


class MarksTableWidget : public QTableWidget
{
public:
    MarksTableWidget(QWidget* parent = nullptr);

private:
    QStringList columnLabels;
};


#endif // MARKSTABLEWIDGET_H
