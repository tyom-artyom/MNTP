#ifndef MANAGERWIDGET_H
#define MANAGERWIDGET_H


#include <QTabWidget>

#include "progresswidget.h"
#include "markswidget.h"


class ManagerWidget : public QTabWidget
{
    Q_OBJECT

public:
    ManagerWidget(QWidget* parent = nullptr);

private:
    ProgressWidget* progressWidget;
    MarksWidget*    marksWidget;
};


#endif // MANAGERWIDGET_H
