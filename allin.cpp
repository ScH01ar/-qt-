#include "allin.h"
#include "ui_allin.h"
#include<qdebug.h>
Allin::Allin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Allin)
{
    ui->setupUi(this);
    connect(ui->comboBox_1,SIGNAL(currentIndexChanged(int)),this,SLOT(OnSelectChanged()));
}

Allin::~Allin()
{
    delete ui;
}

void Allin::on_pushButton_exit_clicked()
{
    close();
}
void Allin::OnSelectChanged()
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



void Allin::on_pushButton_add_clicked()
{
    QString province1,city1,date;
    int newd,news,newh,newde;
    province1=ui->comboBox_1->currentText();
    city1=ui->comboBox_2->currentText();
    date=ui->lineEdit_5->text();
    newd=ui->lineEdit->text().toInt();
    news=ui->lineEdit_2->text().toInt();
    newh=ui->lineEdit_3->text().toInt();
    newde=ui->lineEdit_4->text().toInt();
    query.exec(QObject::tr("SELECT * FROM country WHERE city=='%1';").arg(city1));
    if(query.next())
    {

        int nowd=query.value(6).toInt();
        int nows=query.value(7).toInt();
        int totald=query.value(8).toInt();
        int totals=query.value(9).toInt();
        int totalh=query.value(10).toInt();
        int totalde=query.value(11).toInt();
        query.prepare(QObject::tr("update country set newdiagnosed=:newd,newsuspect=:news,newheal=:newh,newdead=:newde,nowdiagnosed=:nowd,nowsuspect=:nows,totaldiagnosed=:totald,totalsuspect=:totals,totalheal=:totalh,totaldead=:totalde where city=='%1'").arg(city1));
        query.bindValue(":newd",newd);
        query.bindValue(":news",news);
        query.bindValue(":newh",newh);
        query.bindValue(":newde",newde);
        query.bindValue(":nowde",newde);
        query.bindValue(":nowd",newd+nowd-newh-newde);
        query.bindValue(":nows",news+nows);
        query.bindValue(":totald",newd+totald);
        query.bindValue(":totals",news+totals);
        query.bindValue(":totalh",newh+totalh);
        query.bindValue(":totalde",newde+totalde);
        query.exec();
        query.next();

    }
    else
    {
        int nowd=query.value(6).toInt();
        int nows=query.value(7).toInt();
        int totald=query.value(8).toInt();
        int totals=query.value(9).toInt();
        int totalh=query.value(10).toInt();
        int totalde=query.value(11).toInt();
        query.prepare(QObject::tr("INSERT INTO country VALUES('%1','%2',:newd,:news,:newh,:newde,:nowd,:nows,:totald,:totals,:totalh,:totalde,'%3')").arg(province1,city1,date));
        query.bindValue(":newd",newd);
        query.bindValue(":news",news);
        query.bindValue(":newh",newh);
        query.bindValue(":newde",newde);
        query.bindValue(":nowde",newde);
        query.bindValue(":nowd",newd+nowd-newh-newde);
        query.bindValue(":nows",news+nows);
        query.bindValue(":totald",newd+totald);
        query.bindValue(":totals",news+totals);
        query.bindValue(":totalh",newh+totalh);
        query.bindValue(":totalde",newde+totalde);
        query.exec();
        query.next();
    }

}
