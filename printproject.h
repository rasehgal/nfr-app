#ifndef PRINTPROJECT_H
#define PRINTPROJECT_H

#include <QDialog>

namespace Ui {
class PrintProject;
}

class PrintProject : public QDialog
{
    Q_OBJECT

public:
    explicit PrintProject(QWidget *parent = 0);
    ~PrintProject();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::PrintProject *ui;
};

#endif // PRINTPROJECT_H
