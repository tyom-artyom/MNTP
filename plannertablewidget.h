#ifndef PLANNERTABLEWIDGET_H
#define PLANNERTABLEWIDGET_H


#include <QDebug>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QTableWidget>
#include <QHeaderView>


class PlannerTableWidget : public QTableWidget
{
    Q_OBJECT

public:
    PlannerTableWidget(QWidget* parent = nullptr);
    ~PlannerTableWidget();

private:
    QSqlQuery   query;

    QStringList rowLabels;
    QStringList columnLabels;

public slots:
    void updateDb();
    void updateTable();
};


#endif // PLANNERTABLEWIDGET_H
