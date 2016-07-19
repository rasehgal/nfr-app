#include "printclose.h"
#include "ui_printclose.h"
bool toClose;

PrintClose::PrintClose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrintClose)
{
    ui->setupUi(this);
}

PrintClose::~PrintClose()
{
    delete ui;
}


void PrintClose::on_closeApp_clicked()
{
    toClose = true;
    this->close();
}

void PrintClose::on_noClose_clicked()
{
    toClose = false;
    this->close();
}
