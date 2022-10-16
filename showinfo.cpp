#include "showinfo.h"
#include "ui_showinfo.h"
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>

ShowInfo::ShowInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowInfo)
{
    ui->setupUi(this);
    connect(ui->comboBox_1,SIGNAL(currentIndexChanged(int)),this,SLOT(OnSelectChanged()));
    model=new QSqlQueryModel;
    model1=new QSqlQueryModel;

}

ShowInfo::~ShowInfo()
{
    delete ui;
}
void ShowInfo::OnSelectChanged()
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

void ShowInfo::on_pushButton_exit_clicked()
{
    close();
}

void ShowInfo::on_pushButton_search_1_clicked()
{

    QString province1,city1;
    province1=ui->comboBox_1->currentText();
    city1=ui->comboBox_2->currentText();
    QString insert_bufff;
    insert_bufff=QObject::tr("select * from country where  city=='%2';").arg(city1);

    model->setQuery(insert_bufff);
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
    ui->tableView_city->setModel(model);

}

void ShowInfo::on_pushButton_search_2_clicked()
{
    QString search;
    search=ui->lineEdit_name->text();
    model1->setQuery(QObject::tr("select * from people where flght=='%1' or train=='%1' or bus=='%1';").arg(search));
    model1->setHeaderData(0,Qt::Horizontal,tr("姓名"));
    model1->setHeaderData(1,Qt::Horizontal,tr("航班"));
    model1->setHeaderData(2,Qt::Horizontal,tr("火车车次"));
    model1->setHeaderData(3,Qt::Horizontal,tr("大巴车号"));
    model1->setHeaderData(4,Qt::Horizontal,tr("确诊日期"));
    ui->tableView_name->setModel(model1);
}
