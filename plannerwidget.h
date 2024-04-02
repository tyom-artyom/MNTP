#ifndef PLANNERWIDGET_H
#define PLANNERWIDGET_H


#include <QWidget>

#include <QVBoxLayout>

#include "plannertablewidget.h"

#include "plannereventwidget.h"


class PlannerWidget : public QWidget
{
public:
    PlannerWidget(QWidget* parent = nullptr);

private:
    QVBoxLayout*        layout;

    PlannerTableWidget* plannerTableWidget;

    PlannerEventWidget* plannerEventWidget;
    PlannerEventWidget* plannerEventWidget1;
    PlannerEventWidget* plannerEventWidget2;

    int columnCount{};
    int rowCount{};

    QStringList horizontalHeadings;
    QStringList verticalHeadings;
};


#endif // PLANNERWIDGET_H
