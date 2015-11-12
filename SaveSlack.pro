#-------------------------------------------------
#
# Project created by QtCreator 2015-11-12T20:18:14
#
#-------------------------------------------------

QT       += core sql websockets
QT       -= gui

TARGET = SaveSlack
CONFIG += console c++11 c++14
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Utility/database.cpp \
    Utility/settings.cpp \
    Model/Entity/persistable.cpp \
    Model/Repo/baserepo.cpp \
    Utility/handlejson.cpp \
    Utility/connectslack.cpp \
    saveslack.cpp

HEADERS += \
    Utility/database.hpp \
    Utility/settings.hpp \
    Model/Entity/persistable.hpp \
    Model/Repo/baserepo.hpp \
    Utility/handlejson.hpp \
    Utility/connectslack.hpp \
    saveslack.hpp

DISTFILES += \
    settings.ini
