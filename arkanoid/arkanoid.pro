TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    sdlhelper.cpp \
    game.cpp \
    gameobject.cpp \
    player.cpp

INCLUDEPATH += /usr/include/SDL2

LIBS += -L/usr/lib/arm-linux-gnueabihf -lSDL2

HEADERS += \
    sdlhelper.h \
    game.h \
    gameobject.h \
    player.h
