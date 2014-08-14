#ifndef WIFISETUPDLG_H
#define WIFISETUPDLG_H

#include <QDialog>

namespace Ui {
class WiFiSetupDlg;
}

class WiFiSetupDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit WiFiSetupDlg(QWidget *parent = 0);
    ~WiFiSetupDlg();
    
private slots:
    void on_refreshListiBut_clicked();

    void on_wifiSaveActBut_clicked();

    void on_cancelWifiBut_clicked();

private:
    Ui::WiFiSetupDlg *ui;
};

#endif // WIFISETUPDLG_H
