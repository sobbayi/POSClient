#ifndef _WIFI_LIB_H
#define _WIFI_LIB_H


typedef struct wifistatus_info{
    int connectStatus;
    int signalStrength;
 }wifistatus_info_t;


/*scan the access point*/
extern int WifiScan(const char *ebuf);

/*show the wifi scan results*/
extern int ShowScanResults(void);

/*set the essid and passwd and \
switch dhcp or static network address if dhcp = 1 is use dhcp*/
extern int SetWifiSetup(const char *ebuf,const char *pbuf,int dhcp);

//set the wifi NetWork Address
extern int SetWifiAddress(const char *ip,const char *gateway,const char *dns);

//Connect the AP
extern int SetWifiConnect(void);

//Disconnect the AP
extern int SetWifiDisconnect(void);

extern int GetWifiStatus(wifistatus_info_t *status);





#endif
