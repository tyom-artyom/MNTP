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
    QPoint m_dragStartPos;
    bool m_dragging = false;

    QGridLayout* layout;

    QLabel* name;
    QLabel* interval;
    QLabel* description;
};


#endif // PLANNEREVENTWIDGET_H
