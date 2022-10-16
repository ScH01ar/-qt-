#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "first.h"
#include <QSqlQuery>


QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);

    ~Login();

    QSqlQuery* query_3;

private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_login_clicked();


private:
    Ui::Login *ui;
    first *newfirst;
};



#endif // LOGIN_H
