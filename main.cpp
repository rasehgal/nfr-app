#include "createnewproject.h"
#include "mainwindow.h"
#include "gfunc.h"
#include "qattr.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //CreateNewProject create;
   // create.setModal(true);
   // create.exec();
    w.show();

    return a.exec();
}
