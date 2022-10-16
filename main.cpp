#include "login.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("country.db");
    if(!db.open())
        qDebug()<<"failed";


    Login w;
    w.show();
    return a.exec();
}

