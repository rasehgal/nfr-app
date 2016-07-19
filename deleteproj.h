#ifndef DELETEPROJ_H
#define DELETEPROJ_H

#include <QDialog>

namespace Ui {
class deleteProj;
}

class deleteProj : public QDialog
{
    Q_OBJECT

public:
    explicit deleteProj(QWidget *parent = 0);
    ~deleteProj();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::deleteProj *ui;
};

#endif // DELETEPROJ_H
