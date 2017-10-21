#-------------------------------------------------
#
# Project created by QtCreator 2017-10-14T20:11:59
#
#-------------------------------------------------

QT += core gui
QT += 3dcore 3drender 3dinput 3dextras
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rubikomo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    modelrubik.cpp \
    modelrubik_cornersedges.cpp \
    modelrubik_matrix.cpp \
    controllerrubik.cpp \
    rubikvalidator.cpp \
    View3DSources/shape3d.cpp \
    View3DSources/orbittransformcontroller.cpp \
    View3DSources/animationhandler.cpp \
    View3DSources/cuboid.cpp \
    View3DSources/cubie.cpp \
    View3DSources/plane.cpp \
    View3DSources/cube3d.cpp \
    View3DSources/cubiefactory.cpp \
    View3DSources/xorbittransformcontroller.cpp \
    View3DSources/zorbittransformcontroller.cpp \
    mainwindow.cpp \
    View3DSources/yorbittransformcontroller.cpp \
    View3DSources/corner3d.cpp \
    View3DSources/edge3d.cpp \
    View3DSources/centre3d.cpp \
    View3DSources/view3d.cpp

HEADERS += \
        mainwindow.h \
    modelrubik.h \
    modelrubik_cornersedges.h \
    modelrubik_matrix.h \
    rubikface.h \
    rubikedge.h \
    rubikcorner.h \
    controllerrubik.h \
    rubikvalidator.h \
    View3DHeaders/shape3d.h \
    View3DHeaders/animationhandler.h \
    View3DHeaders/orbittransformcontroller.h \
    View3DHeaders/cuboid.h \
    View3DHeaders/cubie.h \
    View3DHeaders/icubie.h \
    View3DHeaders/plane.h \
    View3DHeaders/cube3d.h \
    View3DHeaders/cubiefactory.h \
    View3DHeaders/xorbittransformcontroller.h \
    View3DHeaders/zorbittransformcontroller.h \
    View3DHeaders/yorbittransformcontroller.h \
    View3DHeaders/corner3d.h \
    View3DHeaders/edge3d.h \
    View3DHeaders/centre3d.h \
    View3DHeaders/view3d.h \
    View3DHeaders/matrixswap.h

FORMS += \
        mainwindow.ui
