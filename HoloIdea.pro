#-------------------------------------------------
#
# Project created by QtCreator 2016-09-11T18:35:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HoloIdea
TEMPLATE = app


SOURCES += main.cpp\
    holoidea.cpp \
    opencvmethods.cpp

HEADERS  += holoidea.h \
    opencvmethods.h

FORMS    += holoidea.ui

INCLUDEPATH +=C:\\OpenCV-3.1.0\\opencv\\build\\include

LIBS +=-LC:\\OpenCV-3.1.0\\mybuild\\lib\\Release \
    -lopencv_core310 \
    -lopencv_highgui310 \
    -lopencv_imgcodecs310 \
    -lopencv_imgproc310

