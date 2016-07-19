#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "gfunc.h"
#include "qattr.h"
#include "projexists.h"
#include "createnewproject.h"
#include "createnewattribute.h"
//#include "attributetab.h"
#include "printproject.h"
#include "printclose.h"
#include "deleteattr.h"
#include "deleteproj.h"
#include "projectgone.h"
#include "closeconf.h"

#include <cstring>
#include <QMessageBox>
#include <QTreeWidgetItem>

extern QString title;
extern QString categ;
extern bool new_at;
extern QString FileName;
extern bool toPrint;
extern bool toClose;
extern bool toAtDelete;
extern bool toProjDelete;
extern bool closeApp;
QTreeWidgetItem* TreeRoot;

FILE* projfile;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //tabBar()->hide();

    CreateNewProject create;
    create.setModal(true);
    create.exec();
    TreeRoot = addRoot(title);


    CreateNewAttribute begin;
    begin.setModal(true);
    begin.exec();
    ui->tabBar->setCurrentIndex(1);
    ui->treeWidget->setColumnCount(1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// ---------------------------------------------
// TOOLBAR COMMANDS
// ---------------------------------------------

// Create >> Project
// Displays window allowing for project title
// before continuing to category/attribute editor
void MainWindow::on_actionProject_triggered()
{
    // only create new project if
    // there is not already one
    // if one exists, error
    if (proj_root == NULL) {
        CreateNewProject create;
        create.setModal(true);
        create.exec();
        addRoot(title);

    } else {
        projExists stop;
        stop.setModal(true);
        stop.exec();
    }
}

// Create >> Attribute
// Displays window allowing attribute creation
// under category of choice.
void MainWindow::on_actionAttribute_triggered()
{

    // create attribute/category window (radio buttons category)
    CreateNewAttribute start;
    start.setModal(true);
    start.exec();

    // ultimately creates new attribute tab
    // implementation was not working correctly;
    // commit push button not responding in
    // attributetab.cpp. should function exactly as main screen.
    // rolling back to alternate/previous solution below.
    /*
    if (new_at == true) {
        //create new tab to make way for new attr info
        //or clear form
        ui->tabBar->insertTab(ui->tabBar->count(), new AttributeTab(), QIcon(QString("")), "Attr");
        ui->tabBar->setCurrentIndex(ui->tabBar->count()-1);
    }
    */

    // implemented previous solution described here
    // checks if new attribute is being created
    // if so, clear all forms in main, toggle enabled
    // push buttons
    if (new_at == true) {
        //clear all forms & attr/confirmation label
        ui->srced->clear();
        ui->stimed->clear();
        ui->enved->clear();
        ui->afcted->clear();
        ui->rsped->clear();
        ui->rspmed->clear();
        ui->idLabel->clear();
        ui->commit_confirm->clear();

        // set read only to be false
        ui->srced->setReadOnly(false);
        ui->stimed->setReadOnly(false);
        ui->enved->setReadOnly(false);
        ui->afcted->setReadOnly(false);
        ui->rsped->setReadOnly(false);
        ui->rspmed->setReadOnly(false);

        // toggle push buttons
        ui->addComplete->setEnabled(true);
        ui->destroyComplete->setEnabled(false);
    }

}


// File >> Print to File
// Prints the project specifications at current to
// a filename of choice on the Desktop. Best opened
// in MS Office, etc.
void MainWindow::on_actionPrint_to_File_triggered()
{

    // Window asking for file name
    PrintProject prinwin;
    prinwin.setModal(true);
    prinwin.exec();

    if (toPrint == true)
    {
        // convert file name appropriately
        std::string name = FileName.toLocal8Bit().constData();
        projfile = fopen(name.c_str(), "w");

        // use print function
        dump_project(projfile, proj_root);

        // warning dialog and close
        PrintClose exit;
        exit.setModal(true);
        exit.exec();

        if (toClose == true) { this->close();}
    }
}

// Destroy >> Attribute
// Removes one attribute of choice from the project and
// visual tree
void MainWindow::on_destroyComplete_clicked()
{
    // get attribute ID
    QString ID = ui->idLabel->text();

    // get categ portion
    QString cat = ID.mid(0, 3);

    // q->c string
    std::string cID = ID.toLocal8Bit().constData();
    std::string c_cat = cat.toLocal8Bit().constData();

    deleteAttr murder;
    murder.setModal(true);
    murder.exec();

    // if dialog bool returns true
    // (user selected destroy attr)
    if (toAtDelete == true) {
        // delete function
        rem_attr(proj_root, c_cat, cID);

        // deletion confirmation
        QString confirm_delete = "Attribute has been deleted.";
        ui->commit_confirm->setText(confirm_delete);
        ui->destroyComplete->setEnabled(false);
        QString nullID = "NULL";
        ui->idLabel->setText(nullID);
    }

    // remove from tree view
    QTreeWidgetItem* tobedel;
    QList<QTreeWidgetItem*> clist = ui->treeWidget->findItems(ID, Qt::MatchExactly|Qt::MatchRecursive, 0);
    if (clist.count() == 1) {
        tobedel = clist.at(0);
        delete tobedel;
    }
}


// Destroy >> Project
// Destroys entire project
void MainWindow::on_destroyproj_triggered()
{
    // halting dialog
    deleteProj quitAll;
    quitAll.setModal(true);
    quitAll.exec();

    // if deletion desired
    if (toProjDelete == true) {
        // deletion
        rem_project(proj_root);
        delete TreeRoot;
        // confirmation dialog
        projectGone byebye;
        byebye.setModal(true);
        byebye.exec();

        // CLEAR ATTR TAB FOR NEW INPUTS

        //clear all forms & attr/confirmation label
        ui->srced->clear();
        ui->stimed->clear();
        ui->enved->clear();
        ui->afcted->clear();
        ui->rsped->clear();
        ui->rspmed->clear();
        ui->idLabel->clear();
        ui->commit_confirm->clear();

        // set read only to be false
        ui->srced->setReadOnly(false);
        ui->stimed->setReadOnly(false);
        ui->enved->setReadOnly(false);
        ui->afcted->setReadOnly(false);
        ui->rsped->setReadOnly(false);
        ui->rspmed->setReadOnly(false);

        // toggle push buttons
        ui->addComplete->setEnabled(true);
        ui->destroyComplete->setEnabled(false);

        // go to welcome tab
        ui->tabBar->setCurrentIndex(0);
    }
}


//------------------------------------------------
// PANE COMMANDS
//------------------------------------------------

// Attribute Pane >> Commit
// Commits current attribute to project and
// visual tree
void MainWindow::on_addComplete_clicked()
{
    // setting up values to be placed in add function from gfunc
    // set values to qstring
    QString src = ui->srced->toPlainText();
    QString stim = ui->stimed->toPlainText();
    QString env = ui->enved->toPlainText();
    QString afct = ui->afcted->toPlainText();
    QString rsp = ui->rsped->toPlainText();
    QString rspm = ui->rspmed->toPlainText();

    // modify values to c++ string  
    std::string a_src = src.toLocal8Bit().constData();
    std::string a_stim = stim.toLocal8Bit().constData();
    std::string a_env = env.toLocal8Bit().constData();
    std::string a_afct = afct.toLocal8Bit().constData();
    std::string a_rsp = rsp.toLocal8Bit().constData();
    std::string a_rspm = rspm.toLocal8Bit().constData();

    // modify pre-existing categ value to c++ string
    const char* a_categ = categ.toStdString().c_str();


    QTreeWidgetItem* parent;
    QList<QTreeWidgetItem*> clist = ui->treeWidget->findItems(categ, Qt::MatchExactly|Qt::MatchRecursive, 0);
    if (clist.count() == 1) {
        parent = clist.at(0);
    } else {
        parent = addNodeChild(TreeRoot, categ);
    }

    // commit button clicked, so add to tree
    string idText = add_attr(proj_root, a_categ, a_src, a_stim, a_env, a_afct, a_rsp, a_rspm);
    QString getID = QString::fromStdString(idText);

    // place attribute ID labels and tab names
    ui->idLabel->setText(getID);

    // add attribute to tree-view
    addNodeChild(parent, getID);

    // change screen to show confirmation
    QString confirm_commit = "Attribute has been committed.";
    ui->commit_confirm->setText(confirm_commit);

    // make attribute info un-editable (can change once edit function is implemented in
    // gfunc
    ui->srced->setReadOnly(true);
    ui->stimed->setReadOnly(true);
    ui->enved->setReadOnly(true);
    ui->afcted->setReadOnly(true);
    ui->rsped->setReadOnly(true);
    ui->rspmed->setReadOnly(true);

    // disable commit button and enable destroy button
    ui->addComplete->setEnabled(false);
    ui->destroyComplete->setEnabled(true);

}

// Displays warning prior to closing to prevent
// user info loss
void MainWindow::closeEvent(QCloseEvent *event)
{
    closeConf die;
    die.setModal(true);
    die.exec();

    // check user input
    if (closeApp == true) {
        event->accept();
    } else if (closeApp == false) {
        event->ignore();
    }

}

//------------------------------------------------
// TREE WIDGET COMMANDS
//------------------------------------------------

// Adds a root to the TreeWidget
QTreeWidgetItem* MainWindow::addRoot(QString ID) {
    QTreeWidgetItem* itm = new QTreeWidgetItem(ui->treeWidget);
    itm->setText(0, ID);
    ui->treeWidget->addTopLevelItem(itm);
    return itm;
}

// Adopts nodes to the TreeWidget
QTreeWidgetItem* MainWindow::addNodeChild (QTreeWidgetItem* parent, QString ID) {
    QTreeWidgetItem* itm = new QTreeWidgetItem();
    itm->setText(0, ID);
    parent->addChild(itm);
    return itm;
}

// Accesses attribute info on double click
void MainWindow::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    // item clicked?
    if (item != 0) {

        // is it an attribute??
        // change to c_str()
        QString gid = item->text(column);
        const char* item_id = gid.toStdString().c_str();

        QString cat = gid.mid(0, 3);
        std::string c_cat = cat.toLocal8Bit().constData();
        QString confirm_commit = "Attribute has been committed.";
        qaNode* attr = find_attr(proj_root, c_cat, item_id);

        // if attr exists:
        if (attr != NULL) {
            // get info from node
            QString getsrc = QString::fromStdString(attr->src);
            QString getstim = QString::fromStdString(attr->stim);
            QString getenv = QString::fromStdString(attr->env);
            QString getafct = QString::fromStdString(attr->afct);
            QString getrsp = QString::fromStdString(attr->rsp);
            QString getrspm = QString::fromStdString(attr->rspm);

            // post info to form
            ui->srced->setPlainText(getsrc);
            ui->stimed->setPlainText(getstim);
            ui->enved->setPlainText(getenv);
            ui->afcted->setPlainText(getafct);
            ui->rsped->setPlainText(getrsp);
            ui->rspmed->setPlainText(getrspm);
            ui->idLabel->setText(gid);
            ui->commit_confirm->setText(confirm_commit);

            // set read only to be false
            ui->srced->setReadOnly(false);
            ui->stimed->setReadOnly(false);
            ui->enved->setReadOnly(false);
            ui->afcted->setReadOnly(false);
            ui->rsped->setReadOnly(false);
            ui->rspmed->setReadOnly(false);

            // toggle push buttons
            ui->addComplete->setEnabled(false);
            ui->destroyComplete->setEnabled(true);
        }

    }
}
