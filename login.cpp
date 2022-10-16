#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QDebug>

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    setFixedSize(301,287);

    query_3=new QSqlQuery;
    query_3->exec("create table account(acc vchar primary key,pw vchar)");
    query_3->exec("insert into account values('yy','112233')");
    query_3->exec("insert into account values('admin1','admin1')");

}

Login::~Login()
{
    delete ui;
}


void Login::on_pushButton_exit_clicked()
{
    close();
}

void Login::on_pushButton_login_clicked()
{

    int flag=0;
    QString inputacc=ui->lineEdit_account->text();
    QString inputpw=ui->lineEdit_pw->text();

    query_3->exec("select * from account");

    while(query_3->next()){
        if(inputacc==query_3->value(0)&&inputpw==query_3->value(1)){
            newfirst=new first;
            newfirst->show();
            this->close();
            flag=1;
        }
    }

    if(flag==0){
        QMessageBox::information(NULL, "Error", "用户名或密码错误");
    }


}

