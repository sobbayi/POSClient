#include "gprssetupdlg.h"
#include "ui_gprssetupdlg.h"

GPRSSetupDlg::GPRSSetupDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GPRSSetupDlg)
{
    ui->setupUi(this);
}

GPRSSetupDlg::~GPRSSetupDlg()
{
    delete ui;
}

void GPRSSetupDlg::on_manualConnectRadio_clicked()
{

}

void GPRSSetupDlg::on_autoConnectRadio_clicked()
{

}

void GPRSSetupDlg::on_GprsSaveBut_clicked()
{

}

void GPRSSetupDlg::on_cancelGprsBut_clicked()
{

}
