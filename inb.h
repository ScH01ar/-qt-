#ifndef INB_H
#define INB_H

#include <QMainWindow>
#include <QSqlQuery>



namespace Ui {
class InB;
}

class InB : public QMainWindow
{
    Q_OBJECT

public:
    explicit InB(QWidget *parent = nullptr);
    ~InB();
    QSqlQuery query;
    QSqlQuery query1;






private slots:
    void on_pushButton_return_clicked();

    void on_pushButton_add_clicked();
    void OnSelectChanged();

private:
    Ui::InB *ui;
};



#endif // INCAR_H

