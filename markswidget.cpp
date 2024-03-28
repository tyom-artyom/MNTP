#include "markswidget.h"


MarksWidget::MarksWidget(QWidget* parent) : QWidget(parent)
{
    layout           = new QVBoxLayout(this);

    marksTableWidget = new MarksTableWidget(this);

    setLayout(layout);

    layout->addWidget(marksTableWidget);
}
