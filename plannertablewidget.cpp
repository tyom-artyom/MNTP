#include "plannertablewidget.h"


PlannerTableWidget::PlannerTableWidget(QWidget* parent) : QTableWidget(parent)
{
    setColumnCount(3);
    setRowCount(1);

    verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    columnLabels << "Monday" << "Tuesday" << "Wednesday" << "Thursday" << "Friday" << "Saturday" << "Sunday";

    verticalHeader()->setVisible(false);
    setHorizontalHeaderLabels(columnLabels);

    for (short int row{0} ; row < rowCount() ; ++row)
    {
        for (short int column{0} ; column < columnCount() ; ++column)
        {
            eventCell = new PlannerEventCell(this);
            setCellWidget(row, column, eventCell);
        }
    }
}

