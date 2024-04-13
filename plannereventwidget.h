#ifndef PLANNEREVENTWIDGET_H
#define PLANNEREVENTWIDGET_H


#include <QWidget>


class PlannerEventWidget : public QWidget
{
    Q_OBJECT

public:
    PlannerEventWidget(QWidget* parent = nullptr);

    //  setters/getters{{{
    void setEventInterval(std::pair<int, int> eventInterval);

    std::pair<int, int> getEventInterval();
    //}}}

    virtual ~PlannerEventWidget(){};

private:
    std::pair<int, int> eventInterval{0, 60};
};


#endif // PLANNEREVENTWIDGET_H
