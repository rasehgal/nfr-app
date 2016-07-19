// Attribute Tab ui, etc.
// Unused at current due to implementation
// issues. Should be integrated in the future
// so as to enable multi-attribute editing.


#include "attributetab.h"
#include "ui_attributetab.h"
#include "gfunc.h"
#include "qattr.h"
//#include "mainwindow.h"
#include <cstring>

extern QString categ;


AttributeTab::AttributeTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AttributeTab)
{
    ui->setupUi(this);
}

AttributeTab::~AttributeTab()
{
    delete ui;
}

void AttributeTab::on_TabAddComplete_clicked()
{
    // disable commit button and enable destroy button
    ui->TabAddComplete->setEnabled(true);
    ui->TabDestroyComplete->setEnabled(false);
}
