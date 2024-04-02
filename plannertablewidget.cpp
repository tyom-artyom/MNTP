#include "plannertablewidget.h"


void PlannerTableWidget::setColumnCount(int columnCount)
{
    this->columnCount = columnCount + 1;

    for (int i{} ; i < columnCount ; ++i)
    {
        columnsRect.append(QRect(0, 0, 0, 0));
    }

    for (int i{} ; i < columnCount ; ++i)
    {
        columnsWidgets.append(QVector<QWidget*>());
    }
}

void PlannerTableWidget::setRowCount(int rowCount)
{
    this->rowCount    = rowCount + 1;
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

void PlannerTableWidget::addWidget(int column, QWidget* widget)
{
    columnsWidgets[column].append(widget);
}

void PlannerTableWidget::drawTable()
{
    columnMargin = (width()  - (columnCount - 1))  / columnCount;
    rowMargin    = (height() - (rowCount - 1))     / rowCount;

    int columnLine;
    int nextColumnLine;
    int rowLine = rowMargin * (0 + 1) + (0 + 1);

    for (int column{} ; column < columnCount - 1 ; ++column)
    {
        columnLine     = columnMargin * (column + 1)     + (column + 1);
        nextColumnLine = columnMargin * (column + 1 + 1) + (column + 1 + 1);

        painter.drawLine(columnLine, 0, columnLine, height() - 1);
        columnsRect[column] = QRect(columnLine + 1, rowLine + 1, (column + 1 == columnCount - 1 ? (width() - 1) - (columnLine + 1) : columnMargin - 1) + 1, (height() - 1) - (rowLine + 1));
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
    int columnLine;
    int rowLine = rowMargin * (0 + 1) + (0 + 1);

    for (int column{} ; column < columnCount - 1 ; ++column)
    {
        columnLine     = columnMargin * (column + 1)     + (column + 1);

        painter.drawText(columnLine + 2, rowLine - 2, horizontalHeadings[column]);
    }
}

void PlannerTableWidget::drawVerticalHeadings()
{
    for (int row{} ; row < rowCount - 1 ; ++row)
    {
        painter.drawText(0, rowMargin * (row + 1) + (row + 1) - 2, verticalHeadings[row]);
    }
}

void PlannerTableWidget::drawRects()
{
    for (QRect columnRect : columnsRect)
    {
        painter.drawRect(columnRect);
    }
}

void PlannerTableWidget::allocateWidgets()
{
    for (int column{} ; column  < columnCount - 1 ; ++column)
    {
        for (QWidget* widget : columnsWidgets[column])
        {
            widget->move(columnsRect[column].x(), columnsRect[column].y());
            widget->resize(columnsRect[column].width(), widget->height());
        }
    }
}

void PlannerTableWidget::paintEvent(QPaintEvent *event)
{
    painter.begin(this);

    painter.setPen(pen);

    drawTable();

    painter.setPen(textPen);

    if (horizontalHeadingsVisible)
    {
        drawHorizontalHeadings();
    }
    if (verticalHeadingsVisible)
    {
        drawVerticalHeadings();
    }

    allocateWidgets();

    painter.end();
}

PlannerTableWidget::PlannerTableWidget(QWidget* parent) : QWidget(parent)
{

}
