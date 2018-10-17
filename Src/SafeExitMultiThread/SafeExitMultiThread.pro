#-------------------------------------------------
#
# Project created by QtCreator 2018-10-17T12:05:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SafeExitMultiThread
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    thread.cpp \
    main.cpp \
    bbb.cpp \
    aaa.cpp

HEADERS  += mainwidget.h \
    thread.h \
    bbb.h \
    aaa.h

FORMS    += mainwidget.ui
