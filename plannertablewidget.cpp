#include "plannertablewidget.h"

//  setters/adders{{{
void PlannerTableWidget::setHorizontalHeadingsVisible(bool horizontalHeadingsVisible)
{
    this->horizontalHeadingsVisible = horizontalHeadingsVisible;
}

void PlannerTableWidget::setVerticalHeadingsVisible(bool verticalHeadingsVisible)
{
    this->verticalHeadingsVisible = verticalHeadingsVisible;
}

void PlannerTableWidget::setHorizontalHeadings(QStringList& horizontalHeadings)
{
    this->horizontalHeadings = horizontalHeadings;
}

void PlannerTableWidget::setVerticalHeadings(QStringList& verticalHeadings)
{
    this->verticalHeadings = verticalHeadings;
}

void PlannerTableWidget::setColumnCount(int columnCount)
{
    this->columnCount = columnCount;

    horizontalHeadingsRect.resize(columnCount);

    columnsRect.resize(columnCount);

    columnsWidgets.resize(columnCount);
}

void PlannerTableWidget::setRowCount(int rowCount)
{
    this->rowCount = rowCount;

    verticalHeadingsRect.resize(rowCount);
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

    for (int column{} ; column < columnCount ; ++column)
    {
        horizontalHeadingWidth = fontMetrics().horizontalAdvance(horizontalHeadings[column]);

        horizontalHeadingsMaxWidth = (horizontalHeadingsMaxWidth < horizontalHeadingWidth ? horizontalHeadingWidth : horizontalHeadingsMaxWidth);
    }
}

void PlannerTableWidget::countVerticalHeadingsMaxWidth()
{
    int verticalHeadingWidth{fontMetrics().horizontalAdvance(verticalHeadings[0])};

    verticalHeadingsMaxWidth = verticalHeadingWidth;

    for (int row{} ; row < rowCount ; ++row)
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
    verticalHeadingsHeight = fontMetrics().height();

    verticalHeadingsAscent = fontMetrics().ascent();
    verticalHeadingsDescent = fontMetrics().descent();
}

void PlannerTableWidget::countColumnsMargin()
{
    columnsMargin = (width() - verticalHeadingsMaxWidth - columnCount) / columnCount;
}

void PlannerTableWidget::countRowsMargin()
{
    rowsMargin = (height() - horizontalHeadingsHeight - rowCount) / rowCount;
}

void PlannerTableWidget::fillHorizontalHeadingsRect()
{
    int columnLine;

    for (int column{} ; column < columnCount ; ++column)
    {
        columnLine = verticalHeadingsMaxWidth + (columnsMargin * column) + (column + 1) - 1;

        horizontalHeadingsRect[column] = QRect(columnLine + 1, 0, (column < columnCount - 1 ? columnsMargin - 1 : width() - ((columnLine + 1) + 1)), horizontalHeadingsHeight - 1);
    }
}

void PlannerTableWidget::fillVerticalHeadingsRect()
{
    int rowLine;

    for (int row{} ; row < rowCount ; ++row)
    {
        rowLine = horizontalHeadingsHeight + (rowsMargin * row) + (row + 1) - 1;

        verticalHeadingsRect[row] = QRect(0, rowLine + 1, verticalHeadingsMaxWidth - 1, (row < rowCount - 1 ? rowsMargin - 1 : height() - ((rowLine + 1) + 1)));
    }
}

void PlannerTableWidget::fillColumnsRect()  //REWRITE
{
    int columnLine;
    int rowLine = (horizontalHeadingsHeight + 1) - 1;

    for (int column{} ; column < columnCount ; ++column)
    {
        columnLine = verticalHeadingsMaxWidth + (columnsMargin * column) + (column + 1) - 1;

        columnsRect[column] = QRect(columnLine + 1, rowLine + 1, (column < columnCount - 1 ? columnsMargin - 1 : width() - ((columnLine + 1) + 1)), height() - ((rowLine + 1) + 1));
    }
}

void PlannerTableWidget::countMinimumSize()
{
    int minimumTableWidth{verticalHeadingsMaxWidth + (horizontalHeadingsMaxWidth * columnCount) + columnCount};
    int minimumTableHeight{horizontalHeadingsHeight + (verticalHeadingsHeight * rowCount) + rowCount};

    minimumSize = QSize(minimumTableWidth, minimumTableHeight);

    setMinimumSize(minimumSize);
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
}
//}}}

//  painters{{{
void PlannerTableWidget::drawHorizontalHeadings()
{
    int horizontalHeadingsTextMargin;

    for (int column{} ; column < columnCount ; ++column)
    {
        horizontalHeadingsTextMargin = (((((horizontalHeadingsRect[column].width() + 1) - fontMetrics().horizontalAdvance(horizontalHeadings[column])) / 2) - 1) + 1);

        painter.drawText(horizontalHeadingsRect[column].x() + horizontalHeadingsTextMargin, horizontalHeadingsRect[column].y() + textMargin + horizontalHeadingsAscent, horizontalHeadings[column]);
    }
}

void PlannerTableWidget::drawVerticalHeadings()
{
    for (int row{} ; row < rowCount ; ++row)
    {
        painter.drawText(verticalHeadingsRect[row].x() + textMargin, verticalHeadingsRect[row].y() + verticalHeadingsAscent, verticalHeadings[row]);
    }
}

void PlannerTableWidget::drawTable()
{
    for (int column{} ; column < columnCount ; ++column)
    {
        painter.drawLine(horizontalHeadingsRect[column].x() - 1, 0, horizontalHeadingsRect[column].x() - 1, height() - 1);
    }

    for (int row{} ; row < rowCount ; ++row)
    {
        painter.drawLine(0, verticalHeadingsRect[row].y() - 1, width() - 1, verticalHeadingsRect[row].y() - 1);
    }
}

void PlannerTableWidget::allocateWidgets()
{
    for (int column{} ; column  < columnCount ; ++column)
    {
        for (QWidget* widget : columnsWidgets[column])
        {
            widget->move(columnsRect[column].x(), columnsRect[column].y());
            widget->resize(columnsRect[column].width() + 1, widget->height());
        }
    }
}

void PlannerTableWidget::paintEvent(QPaintEvent *event)
{
    painter.begin(this);

    painter.setPen(textPen);

    if (horizontalHeadingsVisible)
    {
        drawHorizontalHeadings();
    }
    if (verticalHeadingsVisible)
    {
        drawVerticalHeadings();
    }

    painter.setPen(pen);

    drawTable();

    allocateWidgets();

    painter.end();
}
//}}}

PlannerTableWidget::PlannerTableWidget(QWidget* parent) : QWidget(parent)
{

}
