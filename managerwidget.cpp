#include "managerwidget.h"


ManagerWidget::ManagerWidget(QWidget* parent) : QTabWidget(parent)
{
    marksTableWidget = new MarksTableWidget(this);
    progressWidget   = new ProgressWidget(this);

    insertTab(0, marksTableWidget, "Marks");
    insertTab(1, progressWidget,   "Progress");
}
