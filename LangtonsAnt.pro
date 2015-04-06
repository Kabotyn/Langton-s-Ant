#-------------------------------------------------
#
# Project created by QtCreator 2015-04-05T22:16:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LangtonsAnt
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    include/myscene.cpp \
    include/langtonant.cpp

HEADERS  += dialog.h \
    include/myscene.h \
    include/langtonant.h

FORMS    += dialog.ui
