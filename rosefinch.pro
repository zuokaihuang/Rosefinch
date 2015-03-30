#-------------------------------------------------
#
# Project created by QtCreator 2015-03-04T23:56:36
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = rosefinch
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

CONFIG += c++11

SOURCES += \
    core/utils/visit.cpp \
    core/Ref.cpp \
    core/Node.cpp \
    core/utils/Logger.cpp \
    core/utils/Lock.cpp \
    core/utils/Atom.cpp \
    core/utils/Collection.cpp \
    core/utils/Memory.cpp \
    core/utils/Time.cpp \
    core/Director.cpp \
    project/AppDelegate.cpp \
    project/main.cpp \
    core/Application.cpp \
    base/Sprite.cpp \
    base/Layer.cpp \
    core/Scene.cpp \
    project/HelloScene.cpp

HEADERS += \
    core/utils/visit.h \
    core/Ref.h \
    core/Node.h \
    core/utils/Logger.h \
    core/utils/Lock.h \
    core/utils/Atom.h \
    core/utils/Collection.h \
    core/utils/Memory.h \
    core/utils/Time.h \
    core/Director.h \
    project/AppDelegate.h \
    rosefinch.h \
    core/Application.h \
    base/Sprite.h \
    base/Layer.h \
    core/Scene.h \
    project/HelloScene.h
