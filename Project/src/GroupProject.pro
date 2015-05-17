#-------------------------------------------------
#
# Project created by QtCreator 2013-11-15T14:11:00
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = GroupProject
TEMPLATE = app


SOURCES += main.cpp\
    ombidatabase.cpp \
    introwindow.cpp \
    mainprogramview.cpp \
    qcustomplot.cpp \
    graphwindow.cpp

HEADERS  += \
    ombidatabase.h \
    introwindow.h \
    mainprogramview.h \
    qcustomplot.h \
    graphwindow.h

FORMS    += \
    introwindow.ui \
    mainprogramview.ui \
    graphwindow.ui

RESOURCES += \
    resources.qrc
