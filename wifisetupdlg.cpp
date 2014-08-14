#include "wifisetupdlg.h"
#include "ui_wifisetupdlg.h"

WiFiSetupDlg::WiFiSetupDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WiFiSetupDlg)
{
    ui->setupUi(this);
}

WiFiSetupDlg::~WiFiSetupDlg()
{
    delete ui;
}

void WiFiSetupDlg::on_refreshListiBut_clicked()
{

}

void WiFiSetupDlg::on_wifiSaveActBut_clicked()
{

}

void WiFiSetupDlg::on_cancelWifiBut_clicked()
{

}
