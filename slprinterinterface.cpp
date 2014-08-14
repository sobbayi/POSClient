#include     <stdio.h>
#include     <stdlib.h>
#include     <unistd.h>
#include     <sys/types.h>
#include     <sys/stat.h>
#include     <fcntl.h>
#include     <termios.h>
#include     <errno.h>
#include     <sys/ioctl.h>
#include     <sys/time.h>
#include     <string.h>
#include "slprinterinterface.h"

SLPrinterInterface::SLPrinterInterface(QObject *parent) :
    QObject(parent)
{
}

// Print the specified document
// density must be 1~8. probably use default set at 5
int SLPrinterInterface::printItem(qint8 density)
{
    qint8 contrast;
    uchar buff[0x250];
    int printFeed;
    int feedLength;

    // we can now open the printer device
    if((printFeed = openDevice(DEV_PRN_NAME)) < 0)
        return SL_PRINTER_DEVICEERROR;

    memset(buff, 0, sizeof(buff));
    setPrintDensity(&density);

    ioctl(printFeed, PRN_IOC_SETCONTRAST, contrast);

    // check whether we have paper in the printer

    buff[0] = 0x10;
    buff[1] = 0x04;
    buff[2] = 0x02;					//epson command

    write(printFeed, buff, 3);    //write to device feed
    read(printFeed, &buff[3], 1); //Get print feed

    if(buff[3] & 0x20)
    {
        printf("write No Paper\n"); //change and call a QML function
        close(printFeed);
        return SL_PRINTER_OUTOFPAPER;
    }

    //Since we have paper lets do some actual Printing

    buff[0] = 0x1b;
    buff[1] = 0x21;
    buff[2] = 0xb0; //Print Mode: No Underline, Double Height, Double Width

    len = 3 + sprintf(&buff[3], "-Sasalog Sample-\n\n");
    write(printFeed, buff, feedLength); //write the feed data

    buff[2] = 0x00; //Print Mode: No Underline, Single Height, Single Width

    len = 3 + sprintf(&buff[3],
"        ACME ENTERPRISES        \
         BUSINESS STREET         \
       P. O. BOX 23156 NBI       \
         TEL: 020-236589         \
        VAT #: 0000000 A         \
        PIN: P569823697 Q        \
                                 \
 User                         012\
                                 \
 Till #: 002     Cash Sale #: 524\
 Date: 07-May-2012  Time: 08:15PM\
 --------------------------------\
 ITEM     QTY      PRICE   AMOUNT\
 --------------------------------\
 100219196             2 X 160.00\
 COLGATE T.PASTE 100ML     320.00\
 526586522             1 X 130.00\
 MORNING HARVEST                 \
 CORN FLAKES 500G          130.00\
 --------------------------------\
 TOTAL                     450.00\
 CASH                      500.00\
 CHANGE                     50.00\
 --------------------------------\
                                 \
 PRICES INCLUSIVE OF VAT WHERE   \
 APPLICABLE                      \
 --------------------------------\
 YOU WERE SERVED BY:        NGUGI\
 --------------------------------\
 RECEIPT #: 498679 ID #: 64890800\
                                 \
            THANK YOU            \
 --------------------------------\n");

    write(printFeed, buff, feedLength);

    close(printFeed);
    return SL_PRINTER_PRINTSUCCESS;
}

// Open the Printer device by passing in the device to open
int SLPrinterInterface::openDevice(QString device)
{
    int devStatus = open(device.toStdString().c_str(), O_RDWR);

        if(devStatus < 0)
        {     // Send notice to QML that there is no Printer
            printf("open %s error: Cannot Access Printer!\n", device);
        }

        return devStatus;
}

// Set how intense the print quality should be. Defaults to mid point
// Should be overridden from QSettings or database settings
void SLPrinterInterface::setPrintDensity(QPointer<qint8> density)
{
    if(density < 1 || density > 8)
        contrast = 5;
    else
        contrast = atoi(density);
}


