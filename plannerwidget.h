#ifndef PLANNERWIDGET_H
#define PLANNERWIDGET_H


#include <QGridLayout>

#include "plannertablewidget.h"


class PlannerWidget : public QWidget
{
public:
    PlannerWidget(QWidget* parent = nullptr);

private:
    QGridLayout* layout;

    PlannerTableWidget* plannerTableWidget;
};

#endif // PLANNERWIDGET_H
