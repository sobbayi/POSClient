#ifndef SLWIFIINTERFACE_H
#define SLWIFIINTERFACE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <QObject>
#include "lib/wifi_lib.h"

class SLWiFiInterface : public QObject
{
    Q_OBJECT
public:
    explicit SLWiFiInterface(QObject *parent = 0);
    int scanAccessPoints(QString accesspoints);
    void displayScanResults();
    int setup(QString essid, QString password, int dhcp);
    void getStatus(wifistatus_info_t *status);
    int connect();
    void disconnect();


    int  ret;
    int  dhcp; //use dhcp if no dhcp = 0;
    wifistatus_info_t status;
    
signals:
    
public slots:
    
};

#endif // SLWIFIINTERFACE_H
