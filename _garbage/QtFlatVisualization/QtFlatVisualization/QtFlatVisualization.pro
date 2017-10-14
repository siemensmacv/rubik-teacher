#-------------------------------------------------
#
# Project created by QtCreator 2017-10-05T11:05:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtFlatVisualization
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    facecube2d.cpp \
    qbaserubikcube6matrix.cpp \
    rubik2dhandler.cpp \
    ../ckociemba/coordcube.c \
    ../ckociemba/cubiecube.c \
    ../ckociemba/facecube.c \
    ../ckociemba/search.c \
    ../ckociemba/solve.c

HEADERS += \
        mainwindow.h \
    facecube2d.h \
    Cub_Rubik.h \
    qbaserubikcube6matrix.h \
    qrubikcube6matrix.h \
    rubik2dhandler.h \
    Cub_Rubik.h \
    facecube2d.h \
    ../ckociemba/color.h \
    ../ckociemba/coordcube.h \
    ../ckociemba/corner.h \
    ../ckociemba/cubiecube.h \
    ../ckociemba/edge.h \
    ../ckociemba/facecube.h \
    ../ckociemba/facelet.h \
    ../ckociemba/search.h

FORMS += \
        mainwindow.ui
