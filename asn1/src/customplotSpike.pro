#-------------------------------------------------
#
# Project created by QtCreator 2013-10-22T22:11:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = customplotSpike
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        qcustomplot.cpp \
    firedataclass.cpp

HEADERS  += mainwindow.h\
         qcustomplot.h \
    firedataclass.h

FORMS    += mainwindow.ui
