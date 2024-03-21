#include "plannereventcell.h"


PlannerEventCell::PlannerEventCell(QWidget* parent) : QWidget(parent)
{
    eventWidget = new PlannerEventWidget(this);
}
