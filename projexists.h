#ifndef PROJEXISTS_H
#define PROJEXISTS_H

#include <QDialog>

namespace Ui {
class projExists;
}

class projExists : public QDialog
{
    Q_OBJECT

public:
    explicit projExists(QWidget *parent = 0);
    ~projExists();

private slots:
    void on_pushButton_clicked();

private:
    Ui::projExists *ui;
};

#endif // PROJEXISTS_H
