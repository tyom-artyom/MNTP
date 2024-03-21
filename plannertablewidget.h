#ifndef PLANNERTABLEWIDGET_H
#define PLANNERTABLEWIDGET_H


#include <QDebug>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QTableWidget>
#include <QHeaderView>

#include "plannereventcell.h"


class PlannerTableWidget : public QTableWidget
{
    Q_OBJECT

public:
    PlannerTableWidget(QWidget* parent = nullptr);

private:
    QSqlQuery         query;

    QStringList       rowLabels;
    QStringList       columnLabels;

    PlannerEventCell* eventCell;
};


#endif // PLANNERTABLEWIDGET_H
