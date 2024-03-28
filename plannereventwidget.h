#ifndef PLANNEREVENTWIDGET_H
#define PLANNEREVENTWIDGET_H


#include <QMouseEvent>

#include <QGridLayout>

#include <QLabel>


class PlannerEventWidget : public QWidget
{
public:
    PlannerEventWidget(QWidget* parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QGridLayout* layout;

    QLabel* label;
    QLabel* interval;
    QLabel* description;

    QPoint dragStartPos;
    bool   dragging = false;
};


#endif // PLANNEREVENTWIDGET_H
