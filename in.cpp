#include "in.h"
#include "ui_in.h"

In::In(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::In)
{
    ui->setupUi(this);
}

In::~In()
{
    delete ui;
}
