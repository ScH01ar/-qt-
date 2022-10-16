#ifndef INCAR_H
#define INCAR_H

#include <QMainWindow>
#include <QSqlQuery>



namespace Ui {
class InCar;
}

class InCar : public QMainWindow
{
    Q_OBJECT

public:
    explicit InCar(QWidget *parent = nullptr);
    ~InCar();
    int count;
    QSqlQuery *query;

    QSqlQuery* query_5;

    QString getTime();

    bool checkAccount();



private slots:
    void on_pushButton_return_clicked();

    void on_pushButton_add_clicked();

private:
    Ui::InCar *ui;
};



#endif // INCAR_H

