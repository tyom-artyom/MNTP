#include "plannereventwidget.h"


PlannerEventWidget::PlannerEventWidget(QWidget* parent) : QWidget(parent)
{
    setStyleSheet("background-color: #488286; border-radius: 5px;");
}

PlannerEventWidget::~PlannerEventWidget()
{

}

void PlannerEventWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    QStyleOption styleOption;

    styleOption.initFrom(this);

    style()->drawPrimitive(QStyle::PE_Widget, &styleOption, &painter, this);
}

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


