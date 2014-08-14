#ifndef ADMINDLG_H
#define ADMINDLG_H

#include <QDialog>
#include "wifisetupdlg.h"
#include "useradmindlg.h"
#include "gprssetupdlg.h"




namespace Ui {
class adminDlg;
}

class adminDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit adminDlg(QWidget *parent = 0);
    ~adminDlg();
    
private slots:
    void on_adminPanelSaveActBut_clicked();
    void on_cancelActivateActBut_clicked();
    void on_setupWiFiBut_clicked();
    void on_setupGPRSBut_clicked();
    void on_setupUsersBut_clicked();

private:
    Ui::adminDlg *ui;
};

#endif // ADMINDLG_H
