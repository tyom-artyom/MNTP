#ifndef PLANNERTABLEWIDGET_H
#define PLANNERTABLEWIDGET_H


#include <QWidget>

#include <QPaintEvent>
#include <QPainter>
#include <QPen>


class PlannerTableWidget : public QWidget
{
public:
    PlannerTableWidget(QWidget* parent = nullptr);

private:
    void paintEvent(QPaintEvent* event);

    QPen pen;
};


#endif // PLANNERTABLEWIDGET_H
