#-------------------------------------------------
#
# Project created by QtCreator 2015-03-02T22:53:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mpu
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    brigadier.cpp \
    worker.cpp

HEADERS  += mainwindow.h \
    brigadier.h \
    worker.h

FORMS    += mainwindow.ui
