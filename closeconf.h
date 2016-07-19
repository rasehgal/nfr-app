#ifndef CLOSECONF_H
#define CLOSECONF_H

#include <QDialog>

namespace Ui {
class closeConf;
}

class closeConf : public QDialog
{
    Q_OBJECT

public:
    explicit closeConf(QWidget *parent = 0);
    ~closeConf();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::closeConf *ui;
};

#endif // CLOSECONF_H
