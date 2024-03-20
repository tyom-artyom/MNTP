#include "plannertablewidget.h"


void PlannerTableWidget::updateDb()
{
    for (short int row{0} ; row < rowCount() ; ++row)
    {
        query.prepare("UPDATE planner SET monday = :mondayValue, tuesday = :tuesdayValue, wednesday = :wednesdayValue, thursday = :thursdayValue, friday = :fridayValue WHERE lesson_interval = :lesson_interval");

        query.bindValue(":mondayValue",     item(row, 0)->text());
        query.bindValue(":tuesdayValue",    item(row, 1)->text());
        query.bindValue(":wednesdayValue",  item(row, 2)->text());
        query.bindValue(":thursdayValue",   item(row, 3)->text());
        query.bindValue(":fridayValue",     item(row, 4)->text());
        query.bindValue(":lesson_interval", rowLabels.at(row));

        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }
    }
}

void PlannerTableWidget::updateTable()
{
    if (query.exec("SELECT * FROM planner"))
    {
        for (short int row{0} ; query.next() ; ++row)
        {
            for (short int column{0} ; column < columnCount() ; ++column)
            {
                setItem(row, column, new QTableWidgetItem(query.value(column + 1).toString()));

                qDebug() << query.value(column).toString();
            }
        }
    }
    else
    {
        qDebug() << query.lastError().text() << query.lastQuery();
    }
}

PlannerTableWidget::PlannerTableWidget(QWidget* parent) : QTableWidget(parent)
{
    setColumnCount(5);
    setRowCount(7);

    verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    rowLabels    << "08:30-9:15" << "09:30-10:15" << "10:30-11:15" << "11:30-12:15" << "12:30-13:15" << "13:30-14:15" << "14:30-15:15";
    columnLabels << "monday" << "tuesday" << "wednesday" << "thursday" << "friday";

    setVerticalHeaderLabels(rowLabels);
    setHorizontalHeaderLabels(columnLabels);

    updateTable();
}

PlannerTableWidget::~PlannerTableWidget()
{
    updateDb();
}
