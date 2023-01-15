#-------------------------------------------------
#
# Project created by QtCreator 2022-08-25T21:59:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += multimediawidgets multimedia
TARGET = VideoProcess
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    videopreview.cpp \
    global.cpp \
    materiallibrary.cpp \
    myslider.cpp \
    rename.cpp \
    videoprocess.cpp \
    timebar.cpp \
    timesegment.cpp \
    sequence.cpp \
    videoslide.cpp \
    settingphoto.cpp \
    photoslide.cpp \
    subtitleslide.cpp \
    export.cpp

HEADERS  += mainwindow.h \
    videopreview.h \
    global.h \
    materiallibrary.h \
    myslider.h \
    rename.h \
    videoprocess.h \
    timebar.h \
    timesegment.h \
    sequence.h \
    videoslide.h \
    settingphoto.h \
    photoslide.h \
    subtitleslide.h \
    export.h

FORMS    += mainwindow.ui \
    videopreview.ui \
    materiallibrary.ui \
    rename.ui \
    videoprocess.ui \
    timesegment.ui \
    settingphoto.ui \
    subtitleselect.ui \
    export.ui

RESOURCES += \
    src.qrc
DISTFILES +=
INCLUDEPATH += $$PWD/Dev/include

LIBS += $$PWD/Dev/lib/avcodec.lib\
        $$PWD/Dev/lib/avdevice.lib\
        $$PWD/Dev/lib/avfilter.lib\
        $$PWD/Dev/lib/avformat.lib\
        $$PWD/Dev/lib/avutil.lib\
        $$PWD/Dev/lib/postproc.lib\
        $$PWD/Dev/lib/swresample.lib\
        $$PWD/Dev/lib/swscale.lib

