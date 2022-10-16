#include "incar.h"
#include "ui_incar.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QString>
#include <QTime>
#include <QDebug>



InCar::InCar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InCar)
{
    ui->setupUi(this);

    setFixedSize(321,322);
    query=new QSqlQuery;
    query_5=new QSqlQuery;
    count = 0;
}

InCar::~InCar()
{
    delete ui;
}

void InCar::on_pushButton_return_clicked()
{
    close();
}

void InCar::on_pushButton_add_clicked()
{

    QString name,carnum,phone,time,seat;
    name=ui->lineEdit_name->text();
    carnum=ui->lineEdit_carnum->text();
    phone=ui->lineEdit_phone->text();
    time=getTime();
    seat=ui->lineEdit_seat->text();


    query->exec("SELECT count(*) FROM park");
    query->next();
    count=query->value(0).toInt();


    if(name.isEmpty() || carnum.isEmpty() || phone.isEmpty())
    {
        QMessageBox::warning(this,"Incomplete information","请将信息输入完整");
        return;
    }
    else
    {
        if(checkAccount()){
        if (count<5)
        {

            QString insert_buf;
            insert_buf = QObject::tr("insert into park values('%1','%2','%3','%4','%5')").arg(name, carnum, phone, time,seat);
            query->exec(insert_buf);
            QMessageBox::information(NULL, "successed", "succeed");
        }
        else
        {
            QString insert_buf;
            insert_buf = QObject::tr("insert into wait values('%1','%2','%3')").arg(name, carnum, phone);
            query->exec(insert_buf);
            QMessageBox::information(NULL, "successed", "succeed");
        }

        ui->lineEdit_name->clear();
        ui->lineEdit_carnum->clear();
        ui->lineEdit_phone->clear();
        ui->lineEdit_seat->clear();


    }else{ }

    }


}

QString InCar::getTime(){
    time_t timep;
    time (&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%m-%d %H:%M",localtime(&timep) );
    return tmp;
}

bool InCar::checkAccount(){
    QString name,carnum,phone,time,seat;
    int flag=1;
    name=ui->lineEdit_name->text();
    carnum=ui->lineEdit_carnum->text();
    phone=ui->lineEdit_phone->text();
    seat=ui->lineEdit_seat->text();

    query_5->exec("select * from park");

    while(query_5->next()){
        if(carnum==query_5->value(1)){
            QMessageBox::information(NULL, "Error", "车牌号重复");
            ui->lineEdit_carnum->clear();
            flag=0;
        }else if(phone==query_5->value(2)){
            QMessageBox::information(NULL, "Error", "电话重复");
            ui->lineEdit_phone->clear();
            flag=0;
        }else if(seat==query_5->value(4)){
            QMessageBox::information(NULL, "Error", "车位重复");
            ui->lineEdit_seat->clear();
            flag=0;
        }


}
    return flag;
}








