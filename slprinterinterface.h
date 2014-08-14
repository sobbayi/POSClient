#ifndef SLPRINTERINTERFACE_H
#define SLPRINTERINTERFACE_H

#include <QObject>
#include <QPointer>

#define PRN_IOC_MAGIC 'P'

// Print condition codes
#define SL_PRINTER_DEVICEERROR  0x02
#define SL_PRINTER_OUTOFPAPER   0x01
#define SL_PRINTER_PRINTSUCCESS 0x00

#define PRN_IOC_SETCONTRAST         _IOW(PRN_IOC_MAGIC, 0, int)//Print head heating desity (1-8)
#define PRN_IOC_FEED                _IOW(PRN_IOC_MAGIC, 1, int)//Paper Feed Command v < 8000
#define PRN_IOC_STOP                _IOW(PRN_IOC_MAGIC, 3, int)//Cancel Print command
#define PRN_IOC_GETDOTWIDTH         _IOR(PRN_IOC_MAGIC, 4, int)//Get the Printer wide dots

QString DEV_PRN_NAME   = "/dev/ttyprinter0";

class SLPrinterInterface : public QObject
{
    Q_OBJECT
public:
    explicit SLPrinterInterface(QObject *parent = 0);
    int      printItem(qint8 density);

private:
    int openDevice(QString device);
    void setPrintDensity(QPointer<qint8> density);
    
signals:
    
public slots:
    
};

#endif // SLPRINTERINTERFACE_H
