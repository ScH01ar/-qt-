#ifndef OUTCAR_H
#define OUTCAR_H

#include <QMainWindow>
#include "pay.h"
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class OutCar;
}

class OutCar : public QMainWindow
{
    Q_OBJECT

public:
    explicit OutCar(QWidget *parent = nullptr);
    ~OutCar();


    QString getTime();
    int count;

private slots:
    void on_pushButton_return_clicked();

    void on_pushButton_pay_clicked();

    void on_pushButton_fee_clicked();

private:
    Ui::OutCar *ui;

    Pay *newPay;
};

#endif // OUTCAR_H
