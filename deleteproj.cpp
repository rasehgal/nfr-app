#include "deleteproj.h"
#include "ui_deleteproj.h"
bool toProjDelete;

deleteProj::deleteProj(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteProj)
{
    ui->setupUi(this);
}

deleteProj::~deleteProj()
{
    delete ui;
}

void deleteProj::on_pushButton_2_clicked()
{
    toProjDelete = true;
    this->close();
}



void deleteProj::on_pushButton_clicked()
{
    toProjDelete = false;
    this->close();
}
