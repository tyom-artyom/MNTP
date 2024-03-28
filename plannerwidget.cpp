#include "plannerwidget.h"


PlannerWidget::PlannerWidget(QWidget* parent) : QWidget(parent)
{
    layout             = new QVBoxLayout(this);

    plannerTableWidget = new PlannerTableWidget(this);

    setLayout(layout);

    layout->addWidget(plannerTableWidget);
}
