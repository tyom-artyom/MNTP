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

    void addWidget(int column, QWidget* widget);

protected:
    void drawTable();
    void drawHorizontalHeadings();
    void drawVerticalHeadings();

    void drawRects();

    void allocateWidgets();

    void paintEvent(QPaintEvent* event);

private:
    int  columnCount{};
    int  rowCount{};

    QStringList horizontalHeadings;
    QStringList verticalHeadings;

    bool horizontalHeadingsVisible{true};
    bool verticalHeadingsVisible  {true};

    QVector<QVector <QWidget*>> columnsWidgets;

    int columnMargin;
    int rowMargin;

    QVector<QRect> columnsRect;

    QPainter painter;

public:
    QPen  pen;
    QPen  textPen;
    QFont font;
};


#endif // PLANNERTABLEWIDGET_H
