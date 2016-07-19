#include "projexists.h"
#include "ui_projexists.h"

projExists::projExists(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::projExists)
{
    ui->setupUi(this);
}

projExists::~projExists()
{
    delete ui;
}

void projExists::on_pushButton_clicked()
{
    this->close();
}
