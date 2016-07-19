#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    // Adds a root to the TreeWidget
    QTreeWidgetItem* addRoot(QString ID);

    // Adopts nodes to the TreeWidget
    QTreeWidgetItem* addNodeChild (QTreeWidgetItem* parent, QString ID);


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:

    // Attribute Pane >> Commit
    // Commits current attribute to project and
    // visual tree
    void on_addComplete_clicked();

    // Create >> Project
    // Displays window allowing for project title
    // before continuing to category/attribute editor
    void on_actionProject_triggered();

    // Create >> Attribute
    // Displays window allowing attribute creation
    // under category of choice.
    void on_actionAttribute_triggered();

    // File >> Print to File
    // Prints the project specifications at current to
    // a filename of choice on the Desktop. Best opened
    // in MS Office, etc.
    void on_actionPrint_to_File_triggered();

    // Destroy >> Project
    // Destroys entire project
    void on_destroyproj_triggered();

    // Destroy >> Attribute
    // Removes one attribute of choice from the project and
    // visual tree
    void on_destroyComplete_clicked();

    // Displays warning prior to closing to prevent
    // user info loss
    void closeEvent(QCloseEvent *event);

    // Accesses attribute info on double click
    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
