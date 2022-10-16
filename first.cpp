#include "first.h"
#include "ui_first.h"
#include <QSqlQueryModel>
#include<qdebug.h>
first::first(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::first)
{
    ui->setupUi(this); 
    model=new QSqlQueryModel;
    query=new QSqlQuery;
    query->exec("create table country(province text ,city text,newdiagnosed int,newsuspect int,newheal int,newdead int,nowdiagnosed int,nowsuspect int,totaldiagnosed int,totalsuspect int,totalheal int,totaldead int,date text)");
    query1=new QSqlQuery;
    query1->exec("create table people(name text primary key,flght text,train text,bus text,date text)");
    showView();
    newdiag=0;
    totaldiag=0;
    totalheal=0;
    totaldead=0;
}

first::~first()
{
    delete ui;
}

void first::on_pushButton_in_clicked()
{
    newInCar=new InB();
    newInCar->show();
}

void first::on_pushButton_exit_clicked()
{
    close();
}

void first::on_pushButton_search_clicked()
{
    newShowInfo=new ShowInfo();
    newShowInfo->show();
}
void first::showView()
{
    model->setQuery("select * from country");
    model->setHeaderData(0,Qt::Horizontal,tr("省/市"));
    model->setHeaderData(1,Qt::Horizontal,tr("市/区"));
    model->setHeaderData(2,Qt::Horizontal,tr("新增确诊"));
    model->setHeaderData(3,Qt::Horizontal,tr("新增疑似"));
    model->setHeaderData(4,Qt::Horizontal,tr("新增治愈"));
    model->setHeaderData(5,Qt::Horizontal,tr("新增死亡"));
    model->setHeaderData(6,Qt::Horizontal,tr("现有确诊"));
    model->setHeaderData(7,Qt::Horizontal,tr("现有疑似"));
    model->setHeaderData(8,Qt::Horizontal,tr("总确诊病例"));
    model->setHeaderData(9,Qt::Horizontal,tr("总疑似病例"));
    model->setHeaderData(10,Qt::Horizontal,tr("总治愈病例"));
    model->setHeaderData(11,Qt::Horizontal,tr("总死亡病例"));
    model->setHeaderData(12,Qt::Horizontal,tr("日期"));
    ui->tableView_now->setModel(model);

    QSqlQuery query1;
    query1.exec("select sum(newdiagnosed) from country");
    query1.next();
    newdiag=query1.value(0).toInt();

    QSqlQuery query2;
    query2.exec("SELECT sum(totaldiagnosed) FROM country");
    query2.next();
    totaldiag = query2.value(0).toInt();
    QSqlQuery query3;

    query3.exec("SELECT sum(totalheal) FROM country");
    query3.next();
    totalheal = query3.value(0).toInt();
    QSqlQuery query4;

    query4.exec("SELECT sum(totaldead) FROM country");
    query4.next();
    totaldead = query4.value(0).toInt();

    ui->lineEdit_new->setText(QString::number(newdiag));
    ui->lineEdit_2->setText(QString::number(totaldiag));
    ui->lineEdit_3->setText(QString::number(totalheal));
    ui->lineEdit_4->setText(QString::number(totaldead));

}

void first::on_pushButton_refresh_clicked()
{
    showView();
}

void first::on_pushButton_in_2_clicked()
{
    newallin= new Allin();
    newallin->show();

}
