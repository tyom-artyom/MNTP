#ifndef MARKSWIDGET_H
#define MARKSWIDGET_H


#include <QWidget>

#include <QVBoxLayout>

#include "markstablewidget.h"


class MarksWidget : public QWidget
{
public:
    MarksWidget(QWidget* parent = nullptr);

private:
    QVBoxLayout*      layout;

    MarksTableWidget* marksTableWidget;
};


#endif // MARKSWIDGET_H
