#include "plannertablewidget.h"


void PlannerTableWidget::setColumnCount(int columnCount)
{
    this->columnCount = columnCount;

    for (int i{} ; i < columnCount ; ++i)
    {
        columnsRects.append(QRect(0, 0, 0, 0));
    }
}

void PlannerTableWidget::setRowCount(int rowCount)
{
    this->rowCount    = rowCount;
}

void PlannerTableWidget::setHorizontalHeadings(QStringList& horizontalHeadings)
{
    this->horizontalHeadings = horizontalHeadings;
}

void PlannerTableWidget::setVerticalHeadings(QStringList& verticalHeadings)
{
    this->verticalHeadings   = verticalHeadings;
}

void PlannerTableWidget::setHorizontalHeadingsVisible(bool horizontalHeadingsVisible)
{
    this->horizontalHeadingsVisible = horizontalHeadingsVisible;
}

void PlannerTableWidget::setVerticalHeadingsVisible(bool verticalHeadingsVisible)
{
    this->verticalHeadingsVisible   = verticalHeadingsVisible;
}

void PlannerTableWidget::addWidget(QWidget* widget)
{

}

void PlannerTableWidget::drawTable()
{
    columnMargin = (width()  - (columnCount - 1))  / columnCount;
    rowMargin    = (height() - (rowCount - 1))     / rowCount;

    rowLine = rowMargin * (0 + 1) + (0 + 1);

    for (int column{} ; column < columnCount - 1 ; ++column)
    {
        columnLine     = columnMargin * (column + 1)     + (column + 1);
        nextColumnLine = columnMargin * (column + 1 + 1) + (column + 1 + 1);

        painter.drawLine(columnLine, 0, columnLine, height() - 1);
        columnsRects[column] = QRect(columnLine + 1, rowLine + 1, (column + 1 == columnCount - 1 ? (width() - 1) - (columnLine + 1) : columnMargin - 1), (height() - 1) - (rowLine + 1));
        columnsRects[column] = QRect(QPoint(columnLine + 1, rowLine + 1), QPoint((column + 1 == columnCount - 1 ? width() - 1 : columnMargin - 1), height() - 1));
    }

    columnLine     = columnMargin * (0 + 1) + (0 + 1);
    nextColumnLine = columnMargin * (1 + 1) + (1 + 1);

    for (int row{} ; row < rowCount - 1 ; ++row)
    {
        rowLine = rowMargin * (row + 1) + (row + 1);

        painter.drawLine(0, rowLine, width() - 1, rowLine);
    }
}

void PlannerTableWidget::drawHorizontalHeadings()
{
    for (int column{} ; column < columnCount - 1 ; ++column)
    {
        painter.drawText(columnMargin * (column + 1) + (column + 1) + 2, rowMargin * 1 + 1 - 2, horizontalHeadings[column]);
    }
}

void PlannerTableWidget::drawVerticalHeadings()
{
    for (int row{} ; row < rowCount - 1 ; ++row)
    {
        painter.drawText(0, rowMargin * (row + 1) + (row + 1) - 2, verticalHeadings[row]);
    }
}

void PlannerTableWidget::paintEvent(QPaintEvent *event)
{
    painter.begin(this);

    painter.setPen(pen);

    drawTable();
    if (horizontalHeadingsVisible)
    {
        drawHorizontalHeadings();
    }
    if (verticalHeadingsVisible)
    {
        drawVerticalHeadings();
    }

    for (QRect columnRect : columnsRects)
    {
        painter.drawRect(columnRect);
    }

    painter.end();
}

PlannerTableWidget::PlannerTableWidget(QWidget* parent) : QWidget(parent)
{

}
