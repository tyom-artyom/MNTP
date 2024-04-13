#include "plannertablewidget.h"

//  setters/adders{{{
void PlannerTableWidget::setHorizontalHeaders(QStringList& horizontalHeaders)
{
    this->horizontalHeaders = horizontalHeaders;

    setColumnsCount(horizontalHeaders.size());
}

void PlannerTableWidget::setVerticalHeaders(QStringList& verticalHeaders)
{
    this->verticalHeaders = verticalHeaders;

    setRowsCount(verticalHeaders.size());
}

void PlannerTableWidget::setTextMargin(int textMargin)
{
    this->textMargin = textMargin;
}

void PlannerTableWidget::setTimeInterval(int timeInterval)
{
    this->timeInterval = timeInterval;
}

void PlannerTableWidget::setColumnsCount(int columnsCount)
{
    this->columnsCount = columnsCount;

    horizontalHeadersRect.resize(columnsCount);

    columnsRect.resize(columnsCount);

    columnsWidgets.resize(columnsCount);
}

void PlannerTableWidget::setRowsCount(int rowsCount)
{
    this->rowsCount = rowsCount;

    verticalHeadersRect.resize(rowsCount);
}

void PlannerTableWidget::addWidget(int column, PlannerEventWidget* plannerEventWidget)
{
    columnsWidgets[column].append(plannerEventWidget);
}
//}}}

//  counters{{{
void PlannerTableWidget::countHorizontalHeadersMaxWidth()
{
    int horizontalHeaderWidth{fontMetrics().horizontalAdvance(horizontalHeaders[0])};

    horizontalHeadersMaxWidth = horizontalHeaderWidth;

    for (int column{} ; column < columnsCount ; ++column)
    {
        horizontalHeaderWidth = fontMetrics().horizontalAdvance(horizontalHeaders[column]);

        horizontalHeadersMaxWidth = (horizontalHeadersMaxWidth < horizontalHeaderWidth ? horizontalHeaderWidth : horizontalHeadersMaxWidth);
    }

    horizontalHeadersMaxWidth += textMargin * 2;
}

void PlannerTableWidget::countVerticalHeadersMaxWidth()
{
    int verticalHeaderWidth{fontMetrics().horizontalAdvance(verticalHeaders[0])};

    verticalHeadersMaxWidth = verticalHeaderWidth;

    for (int row{} ; row < rowsCount ; ++row)
    {
        verticalHeaderWidth = fontMetrics().horizontalAdvance(verticalHeaders[row]);

        verticalHeadersMaxWidth = (verticalHeadersMaxWidth < verticalHeaderWidth ? verticalHeaderWidth : verticalHeadersMaxWidth);
    }

    verticalHeadersMaxWidth += textMargin * 2;
}

void PlannerTableWidget::countHorizontalHeadersMetrics()
{
    horizontalHeadersHeight = fontMetrics().height() + (textMargin * 2);

    horizontalHeadersAscent = fontMetrics().ascent();
    horizontalHeadersDescent = fontMetrics().descent();
}

void PlannerTableWidget::countVerticalHeadersMetrics()
{
    verticalHeadersHeight = fontMetrics().height() + (textMargin * 2);

    verticalHeadersAscent = fontMetrics().ascent();
    verticalHeadersDescent = fontMetrics().descent();
}

void PlannerTableWidget::countTimeIntervalAmount()
{
    timeIntervalAmount = (60 / timeInterval) * 24;
}

void PlannerTableWidget::countTimeIntervalSize()
{
    timeIntervalSize = ceil(float((height() - horizontalHeadersHeight)) / timeIntervalAmount);
}

void PlannerTableWidget::countTableHeight()
{
    tableHeight = horizontalHeadersHeight + (timeIntervalSize * timeIntervalAmount);

    resize(width(), tableHeight);
}

void PlannerTableWidget::countColumnsMargin()
{
    columnsMargin = (width() - verticalHeadersMaxWidth - columnsCount) / columnsCount;
}

void PlannerTableWidget::countRowsMargin()
{
    rowsMargin = (height() - horizontalHeadersHeight - rowsCount) / rowsCount;
}

void PlannerTableWidget::fillHorizontalHeadersRect()
{
    int columnLine;

    for (int column{} ; column < columnsCount ; ++column)
    {
        columnLine = verticalHeadersMaxWidth + (columnsMargin * column) + (column + 1) - 1;

        horizontalHeadersRect[column] = QRect(columnLine + 1, 0, (column < columnsCount - 1 ? columnsMargin - 1 : width() - ((columnLine + 1) + 1)), horizontalHeadersHeight - 1);
    }
}

void PlannerTableWidget::fillVerticalHeadersRect()
{
    int rowLine;

    for (int row{} ; row < rowsCount ; ++row)
    {
        rowLine = horizontalHeadersHeight + (rowsMargin * row) + (row + 1) - 1;

        verticalHeadersRect[row] = QRect(0, rowLine + 1, verticalHeadersMaxWidth - 1, (row < rowsCount - 1 ? rowsMargin - 1 : height() - ((rowLine + 1) + 1)));
    }
}

void PlannerTableWidget::fillColumnsRect()
{
    int columnLine;
    int rowLine = (horizontalHeadersHeight + 1) - 1;

    for (int column{} ; column < columnsCount ; ++column)
    {
        columnLine = verticalHeadersMaxWidth + (columnsMargin * column) + (column + 1) - 1;

        columnsRect[column] = QRect(columnLine + 1, rowLine, (column < columnsCount - 1 ? columnsMargin - 1 : width() - ((columnLine + 1) + 1)), height() - ((rowLine + 1) + 1));
    }
}

void PlannerTableWidget::countMinimumSize()
{
    int minimumTableWidth{verticalHeadersMaxWidth + (horizontalHeadersMaxWidth * columnsCount) + columnsCount};
    int minimumTableHeight{horizontalHeadersHeight + (verticalHeadersHeight * rowsCount) + rowsCount};

    setMinimumSize(minimumTableWidth, minimumTableHeight);
}

void PlannerTableWidget::allocateWidgets()
{
    for (int column{} ; column  < columnsCount ; ++column)
    {
        for (PlannerEventWidget* columnWidget : columnsWidgets[column])
        {
            columnWidget->move(columnsRect[column].x(), columnsRect[column].y() + (timeIntervalSize * columnWidget->getEventInterval().first));
            columnWidget->resize(columnsRect[column].width() + 1, timeIntervalSize * ((columnWidget->getEventInterval().second - columnWidget->getEventInterval().first) / timeInterval));
        }
    }
}

void PlannerTableWidget::resizeEvent(QResizeEvent* event)
{
    countHorizontalHeadersMaxWidth();
    countVerticalHeadersMaxWidth();

    countHorizontalHeadersMetrics();
    countVerticalHeadersMetrics();

    countTimeIntervalAmount();

    countTimeIntervalSize();

    countTableHeight();

    countColumnsMargin();
    countRowsMargin();

    fillHorizontalHeadersRect();
    fillVerticalHeadersRect();

    fillColumnsRect();

    countMinimumSize();

    allocateWidgets();
}
//}}}

//  painters{{{
void PlannerTableWidget::drawHorizontalHeaders()
{
    int horizontalHeadersTextMargin;

    for (int column{} ; column < columnsCount ; ++column)
    {
        horizontalHeadersTextMargin = (((((horizontalHeadersRect[column].width() + 1) - fontMetrics().horizontalAdvance(horizontalHeaders[column])) / 2) - 1) + 1);

        painter.drawText(horizontalHeadersRect[column].x() + horizontalHeadersTextMargin, horizontalHeadersRect[column].y() + textMargin + horizontalHeadersAscent, horizontalHeaders[column]);
    }
}

void PlannerTableWidget::drawVerticalHeaders()
{
    for (int row{} ; row < rowsCount ; ++row)
    {
        painter.drawText(verticalHeadersRect[row].x() + textMargin, verticalHeadersRect[row].y() + textMargin + verticalHeadersAscent, verticalHeaders[row]);
    }
}

void PlannerTableWidget::drawTable()
{
    for (int column{} ; column < columnsCount ; ++column)
    {
        painter.drawLine(horizontalHeadersRect[column].x() - 1, 0, horizontalHeadersRect[column].x() - 1, height() - 1);
    }

    for (int row{} ; row < rowsCount ; ++row)
    {
        painter.drawLine(0, verticalHeadersRect[row].y() - 1, width() - 1, verticalHeadersRect[row].y() - 1);
    }
}

void PlannerTableWidget::paintEvent(QPaintEvent *event)
{
    painter.begin(this);

    painter.setPen(textPen);

    drawHorizontalHeaders();
    drawVerticalHeaders();

    painter.setPen(pen);

    drawTable();

    painter.end();
}
//}}}

//  movers{{{
void PlannerTableWidget::mousePressEvent(QMouseEvent *event)
{
    if (dynamic_cast<PlannerEventWidget*>(childAt(event->pos())) == nullptr)
    {
        return;
    }

    dragStartPos = event->pos();

    dragChild = qobject_cast<PlannerEventWidget*>(childAt(dragStartPos));

    dragStartChildPos = dragChild->pos();

    dragging = true;
}

void PlannerTableWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (!dragging)
    {
        return;
    }

    QPoint newPos = QPoint(dragStartChildPos.x(), dragStartChildPos.y() + (event->position().y() - dragStartPos.y()));

    if (((newPos.y() - horizontalHeadersHeight) % timeIntervalSize == 0) && (newPos.y() + 1 > horizontalHeadersHeight))
    {
        dragChild->move(newPos);

        dragChild->setEventInterval(std::pair<int, int>(dragChild->getEventInterval().first + timeInterval, dragChild->getEventInterval().second + timeInterval));
    }
}

void PlannerTableWidget::mouseReleaseEvent(QMouseEvent *event)
{
    dragging = false;
}
//}}}

PlannerTableWidget::PlannerTableWidget(QWidget* parent) : QWidget(parent)
{

}
