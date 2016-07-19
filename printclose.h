#ifndef PRINTCLOSE_H
#define PRINTCLOSE_H

#include <QDialog>

namespace Ui {
class PrintClose;
}

class PrintClose : public QDialog
{
    Q_OBJECT

public:
    explicit PrintClose(QWidget *parent = 0);
    ~PrintClose();

private slots:

    void on_closeApp_clicked();

    void on_noClose_clicked();

private:
    Ui::PrintClose *ui;
};

#endif // PRINTCLOSE_H
