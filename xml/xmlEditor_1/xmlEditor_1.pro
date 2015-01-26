#-------------------------------------------------
#
# Project created by QtCreator 2015-01-26T15:26:27
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = xmlEditor_1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    classxmleditor.cpp

HEADERS  += mainwindow.h \
    classxmleditor.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    xmlexamples/config.xml
