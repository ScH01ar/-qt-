#include "outcar.h"
#include "ui_outcar.h"
#include "pay.h"
#include <QMessageBox>
#include <QDebug>
#include<qdatetime.h>
#include <QString>


OutCar::OutCar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OutCar)
{
    ui->setupUi(this);
    setFixedSize(650,322);

    newPay = new Pay();
    count = 0;
}

OutCar::~OutCar()
{
    delete ui;
}

void OutCar::on_pushButton_return_clicked()
{
    close();
}

void OutCar::on_pushButton_pay_clicked()
{

    QString name1,carnum1,phone1,time,timeIn,seat1;
    name1 = ui->lineEdit_name->text();
    carnum1=ui->lineEdit_carnum->text();
    phone1=ui->lineEdit_phone->text();


    //出库

    QSqlQuery query6;
    query6.prepare("select * from park where name = :name1");
    query6.bindValue(":name1", name1);
    query6.exec();
    query6.next();

    timeIn = query6.value(3).toString();
    seat1 = query6.value(4).toString();
    while(query6.next()){}
    time = getTime();
    QSqlQuery query2;
    query2.prepare("delete from park where name = :name1");
    query2.bindValue(":name1", name1);
    query2.exec();

    QSqlQuery query4;
    query4.exec("SELECT count(*) FROM park");
    query4.next();
    count = query4.value(0).toInt();

    QSqlQuery query9;
    query9.exec("SELECT count(*) FROM wait");
    query9.next();
    int count_wait = query9.value(0).toInt();

    //判断便车道是否有车

    if (count == 4&&count_wait>0)
    {
        QString name2, carnum2, phone2;
        QString insert_buf_1;
        QSqlQuery query1;
        query1.prepare("select * from wait ");
        query1.exec();
        query1.next();

        name2 = query1.value(0).toString();
        carnum2 = query1.value(1).toString();
        phone2 = query1.value(2).toString();
        time = getTime();
        //进库



        //将便道车的信息转入停车场
        QSqlQuery query3;
        query3.prepare(QString::fromLocal8Bit("insert into park values(:a,:b,:c,:d,:e)"));
        query3.bindValue(":a", name2);
        query3.bindValue(":b", carnum2);
        query3.bindValue(":c", phone2);
        query3.bindValue(":d", time);
        query3.bindValue(":e", seat1);

        query3.exec();

        QSqlQuery query5;
        query5.prepare("delete from wait where name = :name1");

        query5.bindValue(":name1", name2);

        query5.exec();
    }

    int am = time.mid(0, 2).toInt();//当前时间
    int ad = time.mid(3, 2).toInt();//mid函数提取关键字
    int ah = time.mid(6, 2).toInt();
    int aM = time.mid(9, 2).toInt();
    int bm = timeIn.mid(0, 2).toInt();//停车时间
    int bd = timeIn.mid(3, 2).toInt();
    int bh = timeIn.mid(6, 2).toInt();
    int bM = timeIn.mid(9, 2).toInt();
    int distime = (am - bm) * 24 * 60 * 30 + (ad - bd) * 24 * 60 + (ah - bh) * 60 + (aM - bM);

    double price;
    if (distime < 15)
        price = 10;
    else if(distime<600){
        price = ceil(distime/30)*1.5;
    }
    else price = 30.0;

    QSqlQuery query8;
    query8.prepare("select * from money ");
    query8.exec();
    query8.next();

    double money = query8.value(0).toString().toDouble();
    money = money + price;

    QSqlQuery query7;
    QString str=QString::number(money,10,1);

    QString cmd("update money set sum =");
    cmd+=str;
    query7.exec(cmd);




    newPay->show();
}

QString OutCar::getTime() {
    time_t timep;
    time(&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%m-%d %H:%M", localtime(&timep));

    return tmp;
}

void OutCar::on_pushButton_fee_clicked()
{
    QString name1,carnum1,phone1,time,timeIn,seat1;
    name1 = ui->lineEdit_name->text();
    carnum1=ui->lineEdit_carnum->text();
    phone1=ui->lineEdit_phone->text();

    //出库

    if ((!name1.isEmpty() && (!phone1.isEmpty()) && !carnum1.isEmpty()))
    {
        QSqlQuery query6;
        query6.prepare("select * from park where name = :name1");
        query6.bindValue(":name1", name1);
        query6.exec();
        query6.next();

        timeIn = query6.value(3).toString();
        seat1 = query6.value(4).toString();
        while(query6.next()){}
        time = getTime();

    }
    else
    {
        QMessageBox::warning(this, "Incomplete information", "input the information");
        return;
    }

    int am = time.mid(0, 2).toInt();//当前时间
    int ad = time.mid(3, 2).toInt();//mid函数提取关键字
    int ah = time.mid(6, 2).toInt();
    int aM = time.mid(9, 2).toInt();
    int bm = timeIn.mid(0, 2).toInt();//停车时间
    int bd = timeIn.mid(3, 2).toInt();
    int bh = timeIn.mid(6, 2).toInt();
    int bM = timeIn.mid(9, 2).toInt();
    int distime = (am - bm) * 24 * 60 * 30 + (ad - bd) * 24 * 60 + (ah - bh) * 60 + (aM - bM);

    double price;
    if (distime < 15)
        price = 10;
    else if(distime<600){
        price = ceil(distime/30)*1.5;
    }
    else price = 30.0;
    /*
    QSqlQuery query8;
    query8.prepare("select * from money ");
    query8.exec();
    query8.next();

    double money = query8.value(0).toString().toDouble();
    money = money + price;

    QSqlQuery query7;
    QString str=QString::number(money,10,1);

    QString cmd("update money set sum =");
    cmd+=str;
    query7.exec(cmd);
*/
    ui->lineEdit->setText(timeIn);
    ui->lineEdit_2->setText(time);
    ui->lineEdit_3->setText(QString::number(price));


}
