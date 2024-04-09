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
    void setHorizontalHeadingsVisible(bool horizontalHeadingsVisible = true);
    void setVerticalHeadingsVisible  (bool verticalHeadingsVisible   = true);

    void setHorizontalHeadings(QStringList& horizontalHeadings);
    void setVerticalHeadings  (QStringList& verticalHeadings);

    void setColumnCount(int columnCount = 0);
    void setRowCount   (int rowCount    = 0);

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

    void resizeEvent(QResizeEvent* event);
    //}}}

protected:
    //  drawers{{{
    void drawHorizontalHeadings();
    void drawVerticalHeadings();
    void drawTable();

    void drawRects();

    void allocateWidgets();

    void paintEvent(QPaintEvent* event);
    //}}}

private:
    //  values{{{
    bool horizontalHeadingsVisible{true};
    bool verticalHeadingsVisible{true};

    int horizontalHeadingsMaxWidth;
    int verticalHeadingsMaxWidth;

    int horizontalHeadingsHeight;
    int verticalHeadingsHeight;

    int horizontalHeadingsAscent;
    int horizontalHeadingsDescent;

    int verticalHeadingsAscent;
    int verticalHeadingsDescent;

    int textMargin{5};

    QVector<QRect> horizontalHeadingsRect;
    QVector<QRect> verticalHeadingsRect;

    QStringList horizontalHeadings;
    QStringList verticalHeadings;

    int columnCount{0};
    int rowCount{0};

    int columnsMargin;
    int rowsMargin;

    QVector<QRect> columnsRect;

    QVector<QVector<QWidget*>> columnsWidgets;

    QSize minimumSize;
    //}}}

    //  painter values{{{
    QPainter painter;

public:
    QPen  pen;
    QPen  textPen;
    QFont font;
    //}}}
};


#endif // PLANNERTABLEWIDGET_H
