#include "pay.h"
#include "ui_pay.h"
#include <QMessageBox>

Pay::Pay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pay)
{
    ui->setupUi(this);
    setFixedSize(283,330);
}

Pay::~Pay()
{
    delete ui;
}

void Pay::on_pushButton_pay_clicked()
{

    QMessageBox::information(NULL, "successed", "支付成功");
}

void Pay::on_pushButton_return_clicked()
{
    close();
}


