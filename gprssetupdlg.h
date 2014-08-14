#ifndef GPRSSETUPDLG_H
#define GPRSSETUPDLG_H

#include <QDialog>

namespace Ui {
class GPRSSetupDlg;
}

class GPRSSetupDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit GPRSSetupDlg(QWidget *parent = 0);
    ~GPRSSetupDlg();
    
private slots:
    void on_manualConnectRadio_clicked();

    void on_autoConnectRadio_clicked();

    void on_GprsSaveBut_clicked();

    void on_cancelGprsBut_clicked();

private:
    Ui::GPRSSetupDlg *ui;
};

#endif // GPRSSETUPDLG_H
