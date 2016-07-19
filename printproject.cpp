#include "printproject.h"
#include "ui_printproject.h"
#include "mainwindow.h"
QString FileName;
bool toPrint;
PrintProject::PrintProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrintProject)
{
    ui->setupUi(this);
}

PrintProject::~PrintProject()
{
    delete ui;
}

void PrintProject::on_pushButton_2_clicked()
{
    FileName = ui->fileNameEdit->text();
    toPrint = true;
    this->close();
}



void PrintProject::on_pushButton_clicked()
{
    toPrint = false;
    this->close();
}
