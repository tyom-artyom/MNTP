#ifndef PLANNEREVENTWIDGET_H
#define PLANNEREVENTWIDGET_H


#include <QWidget>

#include <QPaintEvent>

#include <QPainter>

#include <QStyleOption>
#include <QStyle>


class PlannerEventWidget : public QWidget
{
    Q_OBJECT

public:
    PlannerEventWidget(QWidget* parent = nullptr);

    virtual ~PlannerEventWidget();

    void paintEvent(QPaintEvent* event) override;

    //  setters/getters{{{
    void setEventTimeInterval(std::pair<int, int> eventTimeInterval);

    std::pair<int, int> getEventTimeInterval();
    //}}}

private:
    std::pair<int, int> eventTimeInterval{0, 60};
};


#endif // PLANNEREVENTWIDGET_H
