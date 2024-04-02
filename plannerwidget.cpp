#include "plannerwidget.h"


PlannerWidget::PlannerWidget(QWidget* parent) : QWidget(parent)
{
    layout              = new QVBoxLayout(this);

    plannerTableWidget  = new PlannerTableWidget(this);

    plannerEventWidget  = new PlannerEventWidget(plannerTableWidget);
    plannerEventWidget1 = new PlannerEventWidget(plannerTableWidget);
    plannerEventWidget2 = new PlannerEventWidget(plannerTableWidget);

    plannerTableWidget->setColumnCount(3);
    plannerTableWidget->setRowCount(24);

    horizontalHeadings << "Monday" << "Tuesday" << "Wednesday" << "Thursday" << "Friday" << "Saturday" << "Sunday";
    verticalHeadings   << "00:00" << "01:00" << "02:00" << "03:00" << "04:00" << "05:00" << "06:00" << "07:00" << "08:00" << "09:00" << "10:00" << "11:00"
                     << "12:00" << "13:00" << "14:00" << "15:00" << "16:00" << "17:00" << "18:00" << "19:00" << "20:00" << "21:00" << "22:00" << "23:00";

    plannerTableWidget->pen.setWidth(1);
    plannerTableWidget->pen.setColor(QColor("#A6A6A8"));

    plannerTableWidget->textPen.setWidth(1);
    plannerTableWidget->textPen.setColor(QColor("#A6A6A8"));

    plannerTableWidget->setHorizontalHeadings(horizontalHeadings);
    plannerTableWidget->setVerticalHeadings(verticalHeadings);

    plannerTableWidget->addWidget(0, plannerEventWidget);
    plannerTableWidget->addWidget(1, plannerEventWidget1);
    plannerTableWidget->addWidget(2, plannerEventWidget2);

    setLayout(layout);

    layout->addWidget(plannerTableWidget);
}
