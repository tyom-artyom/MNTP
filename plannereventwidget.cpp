#include "plannereventwidget.h"


void PlannerEventWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        dragStartPos = event->pos();
        dragging = true;
    }
}

void PlannerEventWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() & Qt::LeftButton))
    {
        return;
    }
    if (!dragging)
    {
        return;
    }

    QPoint newPos = this->pos() + (event->pos() - dragStartPos);

    this->move(newPos);
}

void PlannerEventWidget::mouseReleaseEvent(QMouseEvent *event)
{
    dragging = false;
}

PlannerEventWidget::PlannerEventWidget(QWidget* parent) : QWidget(parent)
{
    layout      = new QGridLayout(this);

    label       = new QLabel(this);
    interval    = new QLabel(this);
    description = new QLabel(this);

    label      ->setText("Label");
    interval   ->setText("Interval");
    description->setText("Description");

    setStyleSheet("background-color: #488286; border-radius: 5px;");

    layout->addWidget(label, 0, 0);
    layout->addWidget(interval, 0, 1);
    layout->addWidget(description, 1, 0);
}
