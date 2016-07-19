#ifndef ATTRIBUTETAB_H
#define ATTRIBUTETAB_H

#include <QWidget>

namespace Ui {
class AttributeTab;
}

class AttributeTab : public QWidget
{
    Q_OBJECT

public:
    explicit AttributeTab(QWidget *parent = 0);
    ~AttributeTab();

private slots:
    void on_TabAddComplete_clicked();

private:
    Ui::AttributeTab *ui;
};

#endif // ATTRIBUTETAB_H
