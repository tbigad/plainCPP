#-------------------------------------------------
#
# Project created by QtCreator 2015-01-29T14:37:22
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = xmlEditor_1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        domitem.cpp \
        dommodel.cpp \

HEADERS  += mainwindow.h domitem.h dommodel.h mainwindow.h

FORMS    += mainwindow.ui
