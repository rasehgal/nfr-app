// Create new attribute window
// Created upon the selection of attribute creation
// in the toolbar of main screen.
// Designed to pass along correct category to main for
// later attribute commit.

#include "createnewattribute.h"
#include "ui_createnewattribute.h"
#include "mainwindow.h"
bool new_at;

QString categ; //accessible by main for attribute creation

CreateNewAttribute::CreateNewAttribute(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateNewAttribute)
{
    ui->setupUi(this);
}

CreateNewAttribute::~CreateNewAttribute()
{
    delete ui;
}

// After accepting, create a category string appropriately
void CreateNewAttribute::on_acc_categ_clicked()
{
    if(ui->sft_radio->isChecked())
        categ = "sft";

    if(ui->sct_radio->isChecked())
        categ = "sec";

    if (ui->avb_radio->isChecked())
        categ = "avb";

    if(ui->cmp_radio->isChecked())
        categ = "cmp";

    if(ui->ftl_radio->isChecked())
        categ = "ftl";

    this->close();

    new_at = true;
}

// Close with no other action
void CreateNewAttribute::on_exit_categ_clicked()
{
    this->close();
}
