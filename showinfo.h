#ifndef SHOWINFO_H
#define SHOWINFO_H

#include <QMainWindow>

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <inb.h>

namespace Ui {
class ShowInfo;
}

class ShowInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShowInfo(QWidget *parent = nullptr);
    ~ShowInfo();

    QSqlQueryModel *model;
    QSqlQueryModel *model1;



private slots:
    void on_pushButton_exit_clicked();
    void OnSelectChanged();

    void on_pushButton_search_1_clicked();

    void on_pushButton_search_2_clicked();

private:
    Ui::ShowInfo *ui;




};

#endif // SHOWINFO_H
