#include <QApplication>

#include <QSettings>

#include <QTranslator>
#include <QLocale>

#include <QSqlDatabase>
#include <QSqlQuery>

#include <QSqlError>
#include <QDebug>

#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    QSettings settings("Tyoma Corp", "MNTP");

    //  translator{{{
        QTranslator translator;
        const QStringList uiLanguages = QLocale::system().uiLanguages();

        for (const QString& locale : uiLanguages)
        {
            const QString baseName = "MNTP_" + QLocale(locale).name();

            if (translator.load(":/i18n/" + baseName))
            {
                application.installTranslator(&translator);
                break;
            }
        }
    //}}}

    //  db{{{
        QSqlQuery    query;
        QString      dbName{"MNTP"};

        QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName("localhost");
        db.setUserName("postgres");
        db.setPort(5432);
        db.setDatabaseName("postgres");

        if (!db.open())
        {
            qDebug() << db.lastError().text();
        }

        query.prepare("CREATE DATABASE " + dbName);

        db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName("localhost");
        db.setUserName("postgres");
        db.setDatabaseName(dbName);

        if (!db.open())
        {
            qDebug() << db.lastError().text();
        }
    //}}}

    MainWindow mainWindow;

    mainWindow.show();

    return application.exec();
}
