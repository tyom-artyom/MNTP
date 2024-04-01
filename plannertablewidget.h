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

    void setColumnCount(int drawCount);
    void setRowCount   (int rowCount);

    void setHorizontalHeadings(QStringList& horizontalHeadings);
    void setVerticalHeadings  (QStringList& verticalHeadings);

    void setHorizontalHeadingsVisible(bool horizontalHeadingsVisible);
    void setVerticalHeadingsVisible  (bool verticalHeadingsVisible);

    void addWidget(QWidget* widget);

protected:
    void drawTable();
    void drawHorizontalHeadings();
    void drawVerticalHeadings();

    void paintEvent(QPaintEvent* event);

private:
    int  columnCount{};
    int  rowCount{};

    QStringList horizontalHeadings;
    QStringList verticalHeadings;

    bool horizontalHeadingsVisible{true};
    bool verticalHeadingsVisible  {true};

    QPainter painter;

public:
    QPen     pen;

private:
    int columnMargin;
    int rowMargin;

    int columnLine;
    int nextColumnLine;
    int rowLine;

    QVector<QRect> columnsRects;
};


#endif // PLANNERTABLEWIDGET_H
