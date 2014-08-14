#ifndef USERADMINDLG_H
#define USERADMINDLG_H

#include <QDialog>
#include <QModelIndex>
namespace Ui {
class UserAdminDlg;
}

class UserAdminDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit UserAdminDlg(QWidget *parent = 0);
    ~UserAdminDlg();
    
private slots:

    void on_addUserBut_clicked();

    void on_editUserBut_clicked();

    void on_deleteUserBut_clicked();

    void on_propertiesBut_clicked();

    void on_usersListView_clicked(const QModelIndex &index);

    void on_userAdminSaveBut_clicked();

    void on_cancelUserAdminBut_clicked();

private:
    Ui::UserAdminDlg *ui;
};

#endif // USERADMINDLG_H
