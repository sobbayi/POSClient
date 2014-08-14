#include "admindlg.h"
#include "ui_admindlg.h"

adminDlg::adminDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminDlg)
{
    ui->setupUi(this);
}

adminDlg::~adminDlg()
{
    delete ui;
}

void adminDlg::on_adminPanelSaveActBut_clicked()
{
    close();
}

void adminDlg::on_cancelActivateActBut_clicked()
{
    close();
}

void adminDlg::on_setupWiFiBut_clicked()
{
    WiFiSetupDlg dlg(this);
    dlg.exec();
}

void adminDlg::on_setupGPRSBut_clicked()
{
    GPRSSetupDlg dlg(this);
    dlg.exec();
}

void adminDlg::on_setupUsersBut_clicked()
{
    UserAdminDlg dlg(this);
    dlg.exec();
}
