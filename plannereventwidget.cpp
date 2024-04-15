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
void PlannerEventWidget::setEventTimeInterval(std::pair<int, int> eventTimeInterval)
{
    this->eventTimeInterval = eventTimeInterval;
}

std::pair<int, int> PlannerEventWidget::getEventTimeInterval()
{
    return eventTimeInterval;
}
//}}}


