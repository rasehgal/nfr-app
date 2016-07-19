#include "deleteattr.h"
#include "ui_deleteattr.h"
bool toAtDelete;

deleteAttr::deleteAttr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteAttr)
{
    ui->setupUi(this);
}

deleteAttr::~deleteAttr()
{
    delete ui;
}

void deleteAttr::on_deleteat_clicked()
{
    toAtDelete = true;
    this->close();
}

void deleteAttr::on_exit_clicked()
{
    toAtDelete = false;
    this->close();
}
