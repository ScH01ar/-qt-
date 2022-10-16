#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ChartView = new QChartView(this);
    ui->verticalLayout->addWidget(ChartView);
}

Dialog::~Dialog()
{
    delete ui;
}
