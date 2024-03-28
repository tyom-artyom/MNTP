#ifndef PLANNERWIDGET_H
#define PLANNERWIDGET_H


#include <QWidget>

#include <QVBoxLayout>

#include "plannertablewidget.h"


class PlannerWidget : public QWidget
{
public:
    PlannerWidget(QWidget* parent = nullptr);

private:
    QVBoxLayout*        layout;

    PlannerTableWidget* plannerTableWidget;
};


#endif // PLANNERWIDGET_H
