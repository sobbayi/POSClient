#include "adminlogindlg.h"
#include "ui_adminlogindlg.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QFile>

AdminLoginDlg::AdminLoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminLoginDlg)
{
    ui->setupUi(this);
}

AdminLoginDlg::~AdminLoginDlg()
{
    sqlite3_close(db);
    delete ui;
}

void AdminLoginDlg::on_cancelBut_clicked()
{
    close();
}

void AdminLoginDlg::on_loginBut_clicked()
{
    if(openDataConn()){
        int rc;
        char *zErrMsg = 0;
        QString st = "SELECT id, username, password FROM users ";
        st.append("WHERE username = '");
        st.append(ui->uesername->text());
        st.append("' AND password = '");
        st.append(ui->password->text());
        st.append("';");
        rc = sqlite3_exec(db, st.toLocal8Bit(), NULL, 0, &zErrMsg);
            if( rc!=SQLITE_OK ){
              QMessageBox msgBox;

              msgBox.setText(QString("Error: %1\n").arg(sqlite3_errmsg(db)));
              msgBox.setStandardButtons(QMessageBox::Abort);
              msgBox.exec();
              sqlite3_free(zErrMsg);
           }
            else
           {
               MainWindow *m = (MainWindow*)this->parent();
               m->isadminable = true;
               close();
           }
    }
    else{
        QMessageBox msgBox;

        msgBox.setText(tr("Error verifying Credentials"));
        msgBox.setStandardButtons(QMessageBox::Abort);
        msgBox.exec();
    }
}

bool AdminLoginDlg::openDataConn()
{
    if(QFile::exists ( "core.ldb"))
    {
        sqlite3_open("core.ldb", &db);
        return true;
    }
    else
    {
        return false;
    }
}
