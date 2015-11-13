#-------------------------------------------------
#
# Project created by QtCreator 2015-11-14T07:00:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AlgorithmExperiment
TEMPLATE = app


SOURCES += main.cpp\
        algorithmexperiment.cpp

HEADERS  += algorithmexperiment.h

FORMS    += algorithmexperiment.ui

INCLUDEPATH += /opt/arm/qt/qwt-6.1.2-qt-5.2.1-x11/include
LIBS += -L/opt/arm/qt/qwt-6.1.2-qt-5.2.1-x11/lib -lqwt
