#include "markstablewidget.h"


MarksTableWidget::MarksTableWidget(QWidget* parent) : QTableWidget(parent)
{
    setColumnCount(4);
    setRowCount(15);

    verticalHeader()->setVisible(false);
    columnLabels << "Subjects" << "1st part" << "2nd part" << "3rd part";

    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
