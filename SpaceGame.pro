QT += core
QT -= gui

CONFIG += c++11

TARGET = SpaceGame
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    universe.cpp \
    ship.cpp \
    character.cpp \
    player.cpp \
    npc.cpp \
    planet.cpp \
    resourcegenerator.cpp \
    item.cpp \
    resource.cpp \
    resourcetypes.cpp \
    command.cpp \
    parser.cpp \
    commandwords.cpp \
    game.cpp \
    ingameitem.cpp \
    inventorycontainer.cpp \
    cargohold.cpp \
    shipitem.cpp \
    harvester.cpp \
    store.cpp \
    shipyard.cpp \
    starbase.cpp

HEADERS += \
    universe.h \
    ship.h \
    character.h \
    player.h \
    npc.h \
    planet.h \
    resourcegenerator.h \
    item.h \
    resource.h \
    resourcetypes.h \
    command.h \
    parser.h \
    commandwords.h \
    game.h \
    ingameitem.h \
    inventorycontainer.h \
    cargohold.h \
    shipitem.h \
    harvester.h \
    store.h \
    shipyard.h \
    starbase.h
