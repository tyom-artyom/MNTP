#include "plannereventwidget.h"


PlannerEventWidget::PlannerEventWidget(QWidget* parent) : QWidget(parent)
{
    layout      = new QGridLayout(this);

    name        = new QLabel(this);
    interval    = new QLabel(this);
    description = new QLabel(this);

    layout->addWidget(name, 0, 0);
    layout->addWidget(interval, 0, 1);
    layout->addWidget(description, 1, 0);

    name->setText("Default");
    interval->setText("Default");
    description->setText("Default");
}

void PlannerEventWidget::mousePressEvent()
{
    if (event->button() == Qt::LeftButton)
    {
        m_dragStartPos = event->pos();
        m_dragging = true;
    }
}

void PlannerEventWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() & Qt::LeftButton))
    {
        return;
    }
    if (!m_dragging)
    {
        return;
    }
    QPoint newPos = this->pos() + (event->pos() - m_dragStartPos);

    this->move(newPos);
}

void PlannerEventWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_dragging = false;
}
