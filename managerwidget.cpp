#include "managerwidget.h"


ManagerWidget::ManagerWidget(QWidget* parent) : QTabWidget(parent)
{
    progressWidget   = new ProgressWidget(this);
    marksWidget      = new MarksWidget(this);

    insertTab(0, progressWidget, "Progress");
    insertTab(1, marksWidget,    "Marks");
}
