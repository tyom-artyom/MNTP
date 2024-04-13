#include "plannereventwidget.h"


//  setters/getters{{{
void PlannerEventWidget::setEventInterval(std::pair<int, int> eventInterval)
{
    this->eventInterval = eventInterval;
}

std::pair<int, int> PlannerEventWidget::getEventInterval()
{
    return eventInterval;
}
//}}}

PlannerEventWidget::PlannerEventWidget(QWidget* parent) : QWidget(parent)
{
    setStyleSheet("background-color: #488286; border-radius: 5px;");
}
