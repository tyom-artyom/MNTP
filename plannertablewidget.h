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
    void setHorizontalHeadings(QStringList& horizontalHeadings);
    void setVerticalHeadings  (QStringList& verticalHeadings);

    void setColumnsCount(int columnsCount = 0);
    void setRowsCount   (int rowsCount    = 0);

    void addWidget(int column, QWidget* widget);
    //}}}

private:
    //  counters{{{
    void countHorizontalHeadingsMaxWidth();
    void countVerticalHeadingsMaxWidth();

    void countHorizontalHeadingsMetrics();
    void countVerticalHeadingsMetrics();

    void countColumnsMargin();
    void countRowsMargin();

    void fillHorizontalHeadingsRect();
    void fillVerticalHeadingsRect();

    void fillColumnsRect();

    void countMinimumSize();

    void allocateWidgets();

    void resizeEvent(QResizeEvent* event);
    //}}}

protected:
    //  drawers{{{
    void drawHorizontalHeadings();
    void drawVerticalHeadings();

    void drawTable();

    void paintEvent(QPaintEvent* event);
    //}}}

private:
    //  values{{{
    QStringList horizontalHeadings;
    QStringList verticalHeadings;

    int textMargin{5};

    int columnsCount{0};
    int rowsCount{0};

    QVector<QVector<QWidget*>> columnsWidgets;

    int horizontalHeadingsMaxWidth;
    int verticalHeadingsMaxWidth;

    int horizontalHeadingsHeight;
    int verticalHeadingsHeight;

    int horizontalHeadingsAscent;
    int verticalHeadingsAscent;

    int horizontalHeadingsDescent;
    int verticalHeadingsDescent;

    int columnsMargin;
    int rowsMargin;

    QVector<QRect> horizontalHeadingsRect;
    QVector<QRect> verticalHeadingsRect;

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
