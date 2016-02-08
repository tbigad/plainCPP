#-------------------------------------------------
#
# Project created by QtCreator 2016-02-08T21:09:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MarketBase
TEMPLATE = app
CONFIG   += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    market.cpp

HEADERS  += mainwindow.h \
    market.h \
    marketitem.h

FORMS    += mainwindow.ui
