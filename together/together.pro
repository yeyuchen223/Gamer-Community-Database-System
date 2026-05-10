#-------------------------------------------------
#
# Project created by QtCreator 2022-11-04T13:03:36
#
#-------------------------------------------------

QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = together
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
    addmember.cpp \
        main.cpp \
        mainwindow.cpp \
    privateui.cpp \
    myself.cpp \
    member.cpp \
    rank.cpp \
    stusql.cpp \
    updatemember.cpp

HEADERS += \
    addmember.h \
        mainwindow.h \
    privateui.h \
    myself.h \
    member.h \
    rank.h \
    stusql.h \
    updatemember.h

FORMS += \
    addmember.ui \
        mainwindow.ui \
    privateui.ui \
    myself.ui \
    member.ui \
    rank.ui \
    updatemember.ui

DISTFILES += \
    1000.jpg

RESOURCES += \
    picture.qrc
