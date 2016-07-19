#ifndef CREATENEWATTRIBUTE_H
#define CREATENEWATTRIBUTE_H

#include <QDialog>

namespace Ui {
class CreateNewAttribute;
}

class CreateNewAttribute : public QDialog
{
    Q_OBJECT

public:
    explicit CreateNewAttribute(QWidget *parent = 0);
    ~CreateNewAttribute();

private slots:
    void on_acc_categ_clicked();

    void on_exit_categ_clicked();

private:
    Ui::CreateNewAttribute *ui;
};

#endif // CREATENEWATTRIBUTE_H
