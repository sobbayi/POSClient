#ifndef ADMINLOGINDLG_H
#define ADMINLOGINDLG_H

#include <QDialog>
#include "sqlite3.h"


namespace Ui {
class AdminLoginDlg;
}

class AdminLoginDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit AdminLoginDlg(QWidget *parent = 0);
    ~AdminLoginDlg();
    
private slots:
    void on_cancelBut_clicked();

    void on_loginBut_clicked();

private:
    Ui::AdminLoginDlg *ui;
     sqlite3* db;
    bool openDataConn();
};

#endif // ADMINLOGINDLG_H
