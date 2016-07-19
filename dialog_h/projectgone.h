#ifndef PROJECTGONE_H
#define PROJECTGONE_H

#include <QDialog>

namespace Ui {
class projectGone;
}

class projectGone : public QDialog
{
    Q_OBJECT

public:
    explicit projectGone(QWidget *parent = 0);
    ~projectGone();

private slots:
    void on_pushButton_clicked();

private:
    Ui::projectGone *ui;
};

#endif // PROJECTGONE_H
