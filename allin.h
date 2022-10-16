#ifndef ALLIN_H
#define ALLIN_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMainWindow>

namespace Ui {
class Allin;
}

class Allin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Allin(QWidget *parent = 0);
    QSqlQuery query;
    ~Allin();

private slots:
    void on_pushButton_exit_clicked();
    void OnSelectChanged();
    void on_pushButton_add_clicked();

private:
    Ui::Allin *ui;
};

#endif // ALLIN_H
