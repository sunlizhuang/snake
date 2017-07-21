#-------------------------------------------------
#
# Project created by QtCreator 2015-11-30T23:23:11
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = snake
TEMPLATE = app


SOURCES += main.cpp\
        mainWidget.cpp \
    GameWidget.cpp \
    GameWidget1.cpp

HEADERS  += mainWidget.h \
    GameWidget.h \
    GameWidget1.h

RESOURCES += \
    snakeresource.qrc \
    listenresource.qrc
