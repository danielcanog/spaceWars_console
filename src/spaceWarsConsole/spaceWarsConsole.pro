#-------------------------------------------------
#
# Project created by QtCreator 2014-09-02T11:02:09
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = spaceWarsConsole
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    graphicchar.cpp \
    graphicobjects.cpp \
    point.cpp \
    consoleTools/basicGraphic/basicgraphic.cpp

HEADERS += \
    graphicchar.h \
    graphicobjects.h \
    point.h \
    consoleTools/basicGraphic/basicgraphic.h
