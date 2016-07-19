#include "closeconf.h"
#include "ui_closeconf.h"
bool closeApp;

closeConf::closeConf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::closeConf)
{
    ui->setupUi(this);
}

closeConf::~closeConf()
{
    delete ui;
}

void closeConf::on_pushButton_clicked()
{
    closeApp = true;
    this->close();
}

void closeConf::on_pushButton_2_clicked()
{
    closeApp = false;
    this->close();
}
