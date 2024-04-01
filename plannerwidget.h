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

    int columnCount{};
    int rowCount{};

    QStringList horizontalHeadings;
    QStringList verticalHeadings;

public slots:
    void setInterval();
};


#endif // PLANNERWIDGET_H
