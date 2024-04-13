#include "plannerwidget.h"


void PlannerWidget::passSize()
{
    plannerTableWidget->resize(scrollArea->viewport()->size());
}

void PlannerWidget::passMinimumSize()
{
    scrollArea->setMinimumSize(plannerTableWidget->minimumSize() + (scrollArea->size() - scrollArea->viewport()->size()));
}

void PlannerWidget::resizeEvent(QResizeEvent* event)
{
    passSize();

    passMinimumSize();
}

PlannerWidget::PlannerWidget(QWidget* parent) : QWidget(parent)
{
    layout              = new QVBoxLayout(this);

    scrollArea          = new QScrollArea(this);

    plannerTableWidget  = new PlannerTableWidget(this);

    plannerEventWidget  = new PlannerEventWidget(plannerTableWidget);
    plannerEventWidget1 = new PlannerEventWidget(plannerTableWidget);
    plannerEventWidget2 = new PlannerEventWidget(plannerTableWidget);

    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    horizontalHeaders << "Monday" << "Tuesday" << "Wednesday" << "Thursday" << "Friday" << "Saturday" << "Sunday";
    verticalHeaders   << "00:00" << "01:00" << "02:00" << "03:00" << "04:00" << "05:00" << "06:00" << "07:00" << "08:00" << "09:00" << "10:00" << "11:00"
                      << "12:00" << "13:00" << "14:00" << "15:00" << "16:00" << "17:00" << "18:00" << "19:00" << "20:00" << "21:00" << "22:00" << "23:00";

    plannerTableWidget->setHorizontalHeaders(horizontalHeaders);
    plannerTableWidget->setVerticalHeaders(verticalHeaders);

    plannerTableWidget->pen.setWidth(1);
    plannerTableWidget->pen.setColor("#AAAAAA");

    plannerTableWidget->textPen.setWidth(1);
    plannerTableWidget->textPen.setColor("#AAAAAA");

    setLayout(layout);

    layout->addWidget(scrollArea);

    scrollArea->setWidget(plannerTableWidget);

    plannerTableWidget->addWidget(0, plannerEventWidget);
    plannerTableWidget->addWidget(1, plannerEventWidget1);
    plannerTableWidget->addWidget(2, plannerEventWidget2);
}
