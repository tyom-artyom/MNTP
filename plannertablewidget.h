#ifndef PLANNERTABLEWIDGET_H
#define PLANNERTABLEWIDGET_H


#include <QDebug>

#include <QWidget>

#include "plannereventwidget.h"

#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QColor>

#include <QMouseEvent>

#include <QResizeEvent>


class PlannerTableWidget : public QWidget
{
    Q_OBJECT

public:
    PlannerTableWidget(QWidget* parent = nullptr);

    //  setters/adders{{{
    void setHorizontalHeaders(QStringList& horizontalHeaders);
    void setVerticalHeaders  (QStringList& verticalHeaders);

    void setTextMargin(int textMargin = 5);

    void setTimeInterval(int timeInterval = 5);

    void setColumnsCount(int columnsCount = 0);
    void setRowsCount   (int rowsCount    = 0);

    void addWidget(int column, PlannerEventWidget* plannerEventWidget);
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

    void resizeEvent(QResizeEvent* event) override;
    //}}}

    //  painters{{{
    void drawHorizontalHeaders();
    void drawVerticalHeaders();

    void drawTable();

    void paintEvent(QPaintEvent* event);
    //}}}

    //  movers{{{
    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;
    //}}}

    //  values{{{
    QStringList horizontalHeaders;
    QStringList verticalHeaders;

    int textMargin{5};

    int timeInterval{30};

    int columnsCount{0};
    int rowsCount{0};

    QVector<QVector<PlannerEventWidget*>> columnsWidgets;

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

    QPoint              dragStartPos;
    QPoint              dragStartChildPos;
    PlannerEventWidget* dragChild;
    bool                dragging = false;
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
