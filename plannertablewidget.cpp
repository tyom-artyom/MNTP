#include "plannertablewidget.h"


void PlannerTableWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setPen(pen);
    painter.drawLine(0, 0, width(), 0);
    painter.end();
}

PlannerTableWidget::PlannerTableWidget(QWidget* parent) : QWidget(parent)
{
    pen.setWidth(2);
    pen.setBrush(Qt::white);
}
