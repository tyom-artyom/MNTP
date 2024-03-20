#include "markstablewidget.h"


MarksTableWidget::MarksTableWidget(QWidget* parent) : QTableWidget(parent)
{
    setColumnCount(5);
    setRowCount(7);

    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
