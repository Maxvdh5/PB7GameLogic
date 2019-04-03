TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    game.cpp \
    level.cpp \
    object.cpp \
    objectlist.cpp

HEADERS += \
    game.h \
    level.h \
    object.h \
    objectlist.h
