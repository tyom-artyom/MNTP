#include "plannertablewidget.h"

//  setters/adders{{{
void PlannerTableWidget::setHorizontalHeadings(QStringList& horizontalHeadings)
{
    this->horizontalHeadings = horizontalHeadings;

    setColumnsCount(horizontalHeadings.size());
}

void PlannerTableWidget::setVerticalHeadings(QStringList& verticalHeadings)
{
    this->verticalHeadings = verticalHeadings;

    setRowsCount(verticalHeadings.size());
}

void PlannerTableWidget::setColumnsCount(int columnsCount)
{
    this->columnsCount = columnsCount;

    horizontalHeadingsRect.resize(columnsCount);

    columnsRect.resize(columnsCount);

    columnsWidgets.resize(columnsCount);
}

void PlannerTableWidget::setRowsCount(int rowsCount)
{
    this->rowsCount = rowsCount;

    verticalHeadingsRect.resize(rowsCount);
}

void PlannerTableWidget::addWidget(int column, QWidget* widget)
{
    columnsWidgets[column].append(widget);
}
//}}}

//  counters{{{
void PlannerTableWidget::countHorizontalHeadingsMaxWidth()
{
    int horizontalHeadingWidth{fontMetrics().horizontalAdvance(horizontalHeadings[0])};

    horizontalHeadingsMaxWidth = horizontalHeadingWidth;

    for (int column{} ; column < columnsCount ; ++column)
    {
        horizontalHeadingWidth = fontMetrics().horizontalAdvance(horizontalHeadings[column]);

        horizontalHeadingsMaxWidth = (horizontalHeadingsMaxWidth < horizontalHeadingWidth ? horizontalHeadingWidth : horizontalHeadingsMaxWidth);
    }

    horizontalHeadingsMaxWidth += textMargin * 2;
}

void PlannerTableWidget::countVerticalHeadingsMaxWidth()
{
    int verticalHeadingWidth{fontMetrics().horizontalAdvance(verticalHeadings[0])};

    verticalHeadingsMaxWidth = verticalHeadingWidth;

    for (int row{} ; row < rowsCount ; ++row)
    {
        verticalHeadingWidth = fontMetrics().horizontalAdvance(verticalHeadings[row]);

        verticalHeadingsMaxWidth = (verticalHeadingsMaxWidth < verticalHeadingWidth ? verticalHeadingWidth : verticalHeadingsMaxWidth);
    }

    verticalHeadingsMaxWidth += textMargin * 2;
}

void PlannerTableWidget::countHorizontalHeadingsMetrics()
{
    horizontalHeadingsHeight = fontMetrics().height() + (textMargin * 2);

    horizontalHeadingsAscent = fontMetrics().ascent();
    horizontalHeadingsDescent = fontMetrics().descent();
}

void PlannerTableWidget::countVerticalHeadingsMetrics()
{
    verticalHeadingsHeight = fontMetrics().height() + (textMargin * 2);

    verticalHeadingsAscent = fontMetrics().ascent();
    verticalHeadingsDescent = fontMetrics().descent();
}

void PlannerTableWidget::countColumnsMargin()
{
    columnsMargin = (width() - verticalHeadingsMaxWidth - columnsCount) / columnsCount;
}

void PlannerTableWidget::countRowsMargin()
{
    rowsMargin = (height() - horizontalHeadingsHeight - rowsCount) / rowsCount;
}

void PlannerTableWidget::fillHorizontalHeadingsRect()
{
    int columnLine;

    for (int column{} ; column < columnsCount ; ++column)
    {
        columnLine = verticalHeadingsMaxWidth + (columnsMargin * column) + (column + 1) - 1;

        horizontalHeadingsRect[column] = QRect(columnLine + 1, 0, (column < columnsCount - 1 ? columnsMargin - 1 : width() - ((columnLine + 1) + 1)), horizontalHeadingsHeight - 1);
    }
}

void PlannerTableWidget::fillVerticalHeadingsRect()
{
    int rowLine;

    for (int row{} ; row < rowsCount ; ++row)
    {
        rowLine = horizontalHeadingsHeight + (rowsMargin * row) + (row + 1) - 1;

        verticalHeadingsRect[row] = QRect(0, rowLine + 1, verticalHeadingsMaxWidth - 1, (row < rowsCount - 1 ? rowsMargin - 1 : height() - ((rowLine + 1) + 1)));
    }
}

void PlannerTableWidget::fillColumnsRect()
{
    int columnLine;
    int rowLine = (horizontalHeadingsHeight + 1) - 1;

    for (int column{} ; column < columnsCount ; ++column)
    {
        columnLine = verticalHeadingsMaxWidth + (columnsMargin * column) + (column + 1) - 1;

        columnsRect[column] = QRect(columnLine + 1, rowLine + 1, (column < columnsCount - 1 ? columnsMargin - 1 : width() - ((columnLine + 1) + 1)), height() - ((rowLine + 1) + 1));
    }
}

void PlannerTableWidget::countMinimumSize()
{
    int minimumTableWidth{verticalHeadingsMaxWidth + (horizontalHeadingsMaxWidth * columnsCount) + columnsCount};
    int minimumTableHeight{horizontalHeadingsHeight + (verticalHeadingsHeight * rowsCount) + rowsCount};

    minimumSize = QSize(minimumTableWidth, minimumTableHeight);

    setMinimumSize(minimumSize);
}

void PlannerTableWidget::allocateWidgets()
{
    for (int column{} ; column  < columnsCount ; ++column)
    {
        for (QWidget* columnWidget : columnsWidgets[column])
        {
            columnWidget->move(columnsRect[column].x(), columnsRect[column].y());
            columnWidget->resize(columnsRect[column].width() + 1, columnWidget->height());
        }
    }
}

void PlannerTableWidget::resizeEvent(QResizeEvent* event)
{
    countHorizontalHeadingsMaxWidth();
    countVerticalHeadingsMaxWidth();

    countHorizontalHeadingsMetrics();
    countVerticalHeadingsMetrics();

    countColumnsMargin();
    countRowsMargin();

    fillHorizontalHeadingsRect();
    fillVerticalHeadingsRect();

    fillColumnsRect();

    countMinimumSize();

    allocateWidgets();
}
//}}}

//  painters{{{
void PlannerTableWidget::drawHorizontalHeadings()
{
    int horizontalHeadingsTextMargin;

    for (int column{} ; column < columnsCount ; ++column)
    {
        horizontalHeadingsTextMargin = (((((horizontalHeadingsRect[column].width() + 1) - fontMetrics().horizontalAdvance(horizontalHeadings[column])) / 2) - 1) + 1);

        painter.drawText(horizontalHeadingsRect[column].x() + horizontalHeadingsTextMargin, horizontalHeadingsRect[column].y() + textMargin + horizontalHeadingsAscent, horizontalHeadings[column]);
    }
}

void PlannerTableWidget::drawVerticalHeadings()
{
    for (int row{} ; row < rowsCount ; ++row)
    {
        painter.drawText(verticalHeadingsRect[row].x() + textMargin, verticalHeadingsRect[row].y() + textMargin + verticalHeadingsAscent, verticalHeadings[row]);
    }
}

void PlannerTableWidget::drawTable()
{
    for (int column{} ; column < columnsCount ; ++column)
    {
        painter.drawLine(horizontalHeadingsRect[column].x() - 1, 0, horizontalHeadingsRect[column].x() - 1, height() - 1);
    }

    for (int row{} ; row < rowsCount ; ++row)
    {
        painter.drawLine(0, verticalHeadingsRect[row].y() - 1, width() - 1, verticalHeadingsRect[row].y() - 1);
    }
}

void PlannerTableWidget::paintEvent(QPaintEvent *event)
{
    painter.begin(this);

    painter.setPen(textPen);

    drawHorizontalHeadings();
    drawVerticalHeadings();

    painter.setPen(pen);

    drawTable();

    painter.end();
}
//}}}

PlannerTableWidget::PlannerTableWidget(QWidget* parent) : QWidget(parent)
{

}
