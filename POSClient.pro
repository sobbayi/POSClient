#-------------------------------------------------
#
# Project created by QtCreator 2012-06-27T13:24:59
#
#-------------------------------------------------

QT       += core gui sql

TARGET = POSClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    adminlogindlg.cpp \
    qwertykb.cpp \
    postableview.cpp \
    posmaintablemodel.cpp \
    maintabledelegate.cpp \
    flickable.cpp \
    admindlg.cpp \
    gprssetupdlg.cpp \
    wifisetupdlg.cpp \
    useradmindlg.cpp \
    sqlite3.c \
    slwifiinterface.cpp \
    slprinterinterface.cpp \
    sldbinterface.cpp

HEADERS  += mainwindow.h \
    adminlogindlg.h \
    qwertykb.h \
    postableview.h \
    posmaintablemodel.h \
    maintabledelegate.h \
    flickable.h \
    admindlg.h \
    gprssetupdlg.h \
    wifisetupdlg.h \
    useradmindlg.h \
    sqlite3.h \
    slwifiinterface.h \
    slprinterinterface.h \
    sldbinterface.h

FORMS    += mainwindow.ui \
    adminlogindlg.ui \
    qwertykb.ui \
    admindlg.ui \
    gprssetupdlg.ui \
    wifisetupdlg.ui \
    useradmindlg.ui
