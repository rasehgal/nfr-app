#ifndef DELETEATTR_H
#define DELETEATTR_H

#include <QDialog>

namespace Ui {
class deleteAttr;
}

class deleteAttr : public QDialog
{
    Q_OBJECT

public:
    explicit deleteAttr(QWidget *parent = 0);
    ~deleteAttr();

private slots:
    void on_deleteat_clicked();

    void on_exit_clicked();

private:
    Ui::deleteAttr *ui;
};

#endif // DELETEATTR_H
