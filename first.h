#ifndef FIRST_H
#define FIRST_H
#include <QMainWindow>
#include<inb.h>
#include<showinfo.h>
#include<allin.h>
#include <QSqlQuery>
#include <QSqlQueryModel>
namespace Ui {
class first;
}

class first : public QMainWindow
{
    Q_OBJECT

public:
    explicit first(QWidget *parent = 0);
    InB *newInCar;
    Allin *newallin;
    ShowInfo *newShowInfo;
    void showView();
    QSqlQuery *query;
    QSqlQuery *query1;
    QSqlQueryModel *model;
    int newdiag,totaldiag,totalheal,totaldead;
    ~first();

private slots:

    void on_pushButton_in_clicked();

    void on_pushButton_exit_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_refresh_clicked();

    void on_pushButton_in_2_clicked();

private:
    Ui::first *ui;
};

#endif // FIRST_H
