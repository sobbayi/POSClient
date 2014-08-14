#include "useradmindlg.h"
#include "ui_useradmindlg.h"

UserAdminDlg::UserAdminDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserAdminDlg)
{
    ui->setupUi(this);
}

UserAdminDlg::~UserAdminDlg()
{
    delete ui;
}

void UserAdminDlg::on_addUserBut_clicked()
{

}

void UserAdminDlg::on_editUserBut_clicked()
{

}

void UserAdminDlg::on_deleteUserBut_clicked()
{

}

void UserAdminDlg::on_propertiesBut_clicked()
{

}

void UserAdminDlg::on_usersListView_clicked(const QModelIndex &index)
{

}

void UserAdminDlg::on_userAdminSaveBut_clicked()
{

}

void UserAdminDlg::on_cancelUserAdminBut_clicked()
{

}
