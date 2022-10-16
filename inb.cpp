#include "inb.h"
#include "ui_inb.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QString>
#include <QTime>
#include <QDebug>
#include <QSqlError>

InB::InB(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InB)
{
    ui->setupUi(this);
    connect(ui->comboBox_1,SIGNAL(currentIndexChanged(int)),this,SLOT(OnSelectChanged()));

}

InB::~InB()
{
    delete ui;
}

void InB::on_pushButton_return_clicked()
{
    close();
}

void InB::on_pushButton_add_clicked()
{

    QString name,province1,city1,date;
    name=ui->lineEdit_name->text();
    province1=ui->comboBox_1->currentText();
    city1=ui->comboBox_2->currentText();
    date=ui->lineEdit_date->text();


    if(name.isEmpty() || province1.isEmpty() || city1.isEmpty())
    {
        QMessageBox::warning(this,"Incomplete information","请将信息输入完整");
        return;
    }

    query.exec(QObject::tr("SELECT * FROM country WHERE city=='%1';").arg(city1));
    if(query.next())
    {
        qDebug()<<"000";
        QString insert_buff;
        insert_buff = QObject::tr("update country set newdiagnosed=newdiagnosed+1,nowdiagnosed=nowdiagnosed+1,totaldiagnosed=totaldiagnosed+1 WHERE city =='%1'").arg(city1);
        query.exec(insert_buff);
        query.next();
    }
    else
    {
        qDebug()<<"123";
        query.exec(QObject::tr("INSERT INTO country VALUES('%1','%2',1,0,0,0,1,0,1,0,0,0,'%3')").arg(province1,city1,date));
        if(!query.next())
        {
            qDebug()<<query.lastError();
        }
    }
    query.finish();

    QString flight,train,bus;
    flight=ui->lineEdit_flight->text();
    train=ui->lineEdit_train->text();
    bus=ui->lineEdit_bus->text();
    date=ui->lineEdit_date->text();
    query1.exec(QObject::tr("INSERT INTO people VALUES('%1','%2','%3','%4','%5')").arg(name,flight,train,bus,date));
    query1.next();

}
void InB::OnSelectChanged()
{
    if(ui->comboBox_1->currentIndex() == 0){ //判断选择的为第0项
          ui->comboBox_2->clear();                 //清除ComboBox中的内容
          ui->comboBox_2->addItem("海淀区");        //添加下拉列表项
          ui->comboBox_2->addItem("丰台区");
          ui->comboBox_2->addItem("朝阳区");
      }else if(ui->comboBox_1->currentIndex() == 1){
          ui->comboBox_2->clear();
          ui->comboBox_2->addItem("盘锦市");
          ui->comboBox_2->addItem("沈阳市");
          ui->comboBox_2->addItem("大连市");
      }else if(ui->comboBox_1->currentIndex() == 2){
          ui->comboBox_2->clear();
          ui->comboBox_2->addItem("太原市");
          ui->comboBox_2->addItem("运城市");
          ui->comboBox_2->addItem("平遥市");
      }

}








