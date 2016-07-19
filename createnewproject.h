#ifndef CREATENEWPROJECT_H
#define CREATENEWPROJECT_H

#include <QDialog>

namespace Ui {
class CreateNewProject;
}

class CreateNewProject : public QDialog
{
    Q_OBJECT

public:
    explicit CreateNewProject(QWidget *parent = 0);
    ~CreateNewProject();

private slots:
    void on_Accept_clicked();

    void on_Exit_clicked();

private:
    Ui::CreateNewProject *ui;
};

#endif // CREATENEWPROJECT_H
