#ifndef PLANNERWIDGET_H
#define PLANNERWIDGET_H


#include <QWidget>

#include <QVBoxLayout>

#include <QScrollArea>

#include "plannertablewidget.h"

#include "plannereventwidget.h"

#include <QResizeEvent>


class PlannerWidget : public QWidget
{
public:
    PlannerWidget(QWidget* parent = nullptr);

private:
    void passSize();

    void passMinimumSize();

    void resizeEvent(QResizeEvent* event) override;


    QVBoxLayout*        layout;

    QScrollArea*        scrollArea;

    PlannerTableWidget* plannerTableWidget;

    PlannerEventWidget* plannerEventWidget;
    PlannerEventWidget* plannerEventWidget1;
    PlannerEventWidget* plannerEventWidget2;

    QStringList horizontalHeaders;
    QStringList verticalHeaders;
};


#endif // PLANNERWIDGET_H
