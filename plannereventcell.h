#ifndef PLANNEREVENTCELL_H
#define PLANNEREVENTCELL_H


#include <QWidget>

#include "plannereventwidget.h"


class PlannerEventCell : public QWidget
{
public:
    PlannerEventCell(QWidget* parent = nullptr);

private:
    PlannerEventWidget* eventWidget;
};


#endif // PLANNEREVENTCELL_H
