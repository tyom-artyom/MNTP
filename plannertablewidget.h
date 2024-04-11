#ifndef PLANNERTABLEWIDGET_H
#define PLANNERTABLEWIDGET_H


#include <QDebug>

#include <QWidget>

#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QColor>


class PlannerTableWidget : public QWidget
{
public:
    PlannerTableWidget(QWidget* parent = nullptr);

    //  setters/adders{{{
    void setHorizontalHeaders(QStringList& horizontalHeaders);
    void setVerticalHeaders  (QStringList& verticalHeaders);

    void setTextMargin(int textMargin = 5);

    void setTimeInterval(int timeInterval = 5);

    void setColumnsCount(int columnsCount = 0);
    void setRowsCount   (int rowsCount    = 0);

    void addWidget(int column, QWidget* widget);
    //}}}

private:
    //  counters{{{
    void countHorizontalHeadersMaxWidth();
    void countVerticalHeadersMaxWidth();

    void countHorizontalHeadersMetrics();
    void countVerticalHeadersMetrics();

    void countTimeIntervalAmount();

    void countTimeIntervalSize();

    void countTableHeight();

    void countColumnsMargin();
    void countRowsMargin();

    void fillHorizontalHeadersRect();
    void fillVerticalHeadersRect();

    void fillColumnsRect();

    void countMinimumSize();

    void allocateWidgets();

    void resizeEvent(QResizeEvent* event);
    //}}}

protected:
    //  drawers{{{
    void drawHorizontalHeaders();
    void drawVerticalHeaders();

    void drawTable();

    void paintEvent(QPaintEvent* event);
    //}}}

private:
    //  values{{{
    QStringList horizontalHeaders;
    QStringList verticalHeaders;

    int textMargin{5};      //pixels

    int timeInterval{5};    //minutes <= 60 minutes

    int columnsCount{0};    //amount
    int rowsCount{0};       //amount

    QVector<QVector<QWidget*>> columnsWidgets;

    int horizontalHeadersMaxWidth;
    int verticalHeadersMaxWidth;

    int horizontalHeadersHeight;
    int verticalHeadersHeight;

    int horizontalHeadersAscent;
    int verticalHeadersAscent;

    int horizontalHeadersDescent;
    int verticalHeadersDescent;

    int timeIntervalAmount;

    int timeIntervalSize;

    int tableHeight;

    int columnsMargin;
    int rowsMargin;

    QVector<QRect> horizontalHeadersRect;
    QVector<QRect> verticalHeadersRect;

    QVector<QRect> columnsRect;

    QSize minimumSize;
    //}}}

    //  painter values{{{
public:
    QPen  pen;
    QPen  textPen;
    QFont font;

private:
    QPainter painter;
    //}}}
};


#endif // PLANNERTABLEWIDGET_H
