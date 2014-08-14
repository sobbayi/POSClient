#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "adminlogindlg.h"
#include "qwertykb.h"
#include "postableview.h"
#include "posmaintablemodel.h"
#include "maintabledelegate.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QwertyKb *kb;
    bool isadminable;

    
private slots:
    void on_transferOwnershipBut_pressed();
    void on_outgoingTransfersBut_pressed();
    void on_incomingTransfersBut_pressed();
    void on_finalSaleBut_pressed();
    void on_returnedItemsBut_pressed();
    void on_forensicsBut_pressed();
    void on_activateItemsBut_pressed();
    void on_adminBut_pressed();

private:
    Ui::MainWindow *ui;
    AdminLoginDlg *adminLogin;
    QAbstractTableModel *model;


};

#endif // MAINWINDOW_H
