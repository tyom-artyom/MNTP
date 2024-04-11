#ifndef PLANNERWIDGET_H
#define PLANNERWIDGET_H


#include <QWidget>

#include <QVBoxLayout>

#include <QScrollArea>

#include "plannertablewidget.h"

#include "plannereventwidget.h"


class PlannerWidget : public QWidget
{
public:
    PlannerWidget(QWidget* parent = nullptr);

private:
    void passSize();

    void resizeEvent(QResizeEvent* event);


    QVBoxLayout*        layout;

    QScrollArea*        scrollArea;

    PlannerTableWidget* plannerTableWidget;

    PlannerEventWidget* plannerEventWidget;
    PlannerEventWidget* plannerEventWidget1;
    PlannerEventWidget* plannerEventWidget2;

    int columnCount{};
    int rowCount{};

    QStringList horizontalHeaders;
    QStringList verticalHeaders;
};


#endif // PLANNERWIDGET_H
