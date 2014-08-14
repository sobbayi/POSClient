
#include "slwifiinterface.h"

SLWiFiInterface::SLWiFiInterface(QObject *parent) :
    QObject(parent)
{
    ret = 0;
    dhcp =1;
}

int SLWiFiInterface::scanAccessPoints(QString accesspoints)
{
    int res = WifiScan(accesspoints.toStdString().c_str());
    if(res == 0)
            displayScanResults();
    return res;
}

void SLWiFiInterface::displayScanResults()
{
    ShowScanResults();
}

int SLWiFiInterface::setup(QString essid, QString password, int dhcp)
{
 //set the essid and passwd and switch dhcp or static network address if dhcp = 1 is use dhcp
    if(SetWifiSetup(essid.toStdString().c_str(), password.toStdString().c_str(), dhcp) != 0)
            {
                printf("Set Wifi Error:No THE ESSID\n");
                ret =-1;
                return ret;
            }
            else
            {
                printf("Set Wifi OK\n");
                return 0;

            }

            if(!dhcp) //use the dhcpc
              {
                // get these from either QSettings, Database or conf file
                  SetWifiAddress("192.168.8.15","192.168.8.1","202.101.98.55");
                  return 1;
              }
}



void SLWiFiInterface::getStatus(wifistatus_info_t *status)// signal level = 0~100
{
    GetWifiStatus(status); /* signal level = 0~100*/
    printf("THE WIFI IS %s -- signal level %d\n"
           ,status->connectStatus?("Connect"):("No Connect"),status->signalStrength);
}

int SLWiFiInterface::connect()
{
    if(SetWifiConnect() != 0 )
            {
               printf("Connect Error\n");
               ret = -1;
               return ret;
            }
            else
            {
                printf("Connect OK\n");
                return 0;
            }
}

void SLWiFiInterface::disconnect()
{
    SetWifiDisconnect();
}
