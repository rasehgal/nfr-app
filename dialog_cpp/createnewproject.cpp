#include "createnewproject.h"
#include "ui_createnewproject.h"
#include "gfunc.h"
#include <mainwindow.h>
#include <cstring>

QString title;
CreateNewProject::CreateNewProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateNewProject)
{
    ui->setupUi(this);
}

CreateNewProject::~CreateNewProject()
{
    delete ui;
}

void CreateNewProject::on_Accept_clicked()
{
    QString proj_name = ui->lineEdit->text();
    title = proj_name;
    std::string nameproj = proj_name.toLocal8Bit().constData();
    create_proj(nameproj);
    this->close();
}

void CreateNewProject::on_Exit_clicked()
{
    this->close();
    exit(1);
}
