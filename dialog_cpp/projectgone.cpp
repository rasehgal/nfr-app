#include "projectgone.h"
#include "ui_projectgone.h"

projectGone::projectGone(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::projectGone)
{
    ui->setupUi(this);
}

projectGone::~projectGone()
{
    delete ui;
}

void projectGone::on_pushButton_clicked()
{
    this->close();
}
