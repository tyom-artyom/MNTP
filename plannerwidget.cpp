#include "plannerwidget.h"


PlannerWidget::PlannerWidget(QWidget* parent) : QWidget(parent)
{
    layout             = new QGridLayout(this);

    plannerTableWidget = new PlannerTableWidget(this);

    layout->addWidget(plannerTableWidget);
}
