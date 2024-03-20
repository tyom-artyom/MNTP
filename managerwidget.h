#ifndef MANAGERWIDGET_H
#define MANAGERWIDGET_H


#include <QTabWidget>

#include "markswidget.h"
#include "progresswidget.h"


class ManagerWidget : public QTabWidget
{
    Q_OBJECT

public:
    ManagerWidget(QWidget* parent = nullptr);

private:
    MarksTableWidget* marksTableWidget;
    ProgressWidget*   progressWidget;
};


#endif // MANAGERWIDGET_H
