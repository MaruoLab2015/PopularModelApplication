#-------------------------------------------------
#
# Project created by QtCreator 2015-01-07T12:10:57
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PopularModelApplication
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    stagesetting.cpp

HEADERS  += mainwindow.h \
    stagesetting.h

FORMS    += mainwindow.ui
