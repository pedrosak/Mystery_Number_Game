#-------------------------------------------------
#
# Project created by QtCreator 2017-02-02T09:00:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mystery_Number_Game
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    numberengine.cpp \
    controlsengine.cpp

HEADERS  += mainwindow.h \
    numberengine.h \
    controlsengine.h

FORMS    += mainwindow.ui
