TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++11
LIBS += -pthread

DESTDIR = bin
TARGET = trab3

INCLUDEPATH = include/
OBJECTS_DIR = obj/



SOURCES += \
    src/trab3/character/characters/knight.cpp \
    src/trab3/character/characters/thief.cpp \
    src/trab3/character/characters/wizard.cpp \
    src/trab3/character/character.cpp \
    src/trab3/character/inventory.cpp \
    src/trab3/game/game.cpp \
    src/trab3/item/armor/armor.cpp \
    src/trab3/item/potion/potions/healthpotion.cpp \
    src/trab3/item/potion/potions/manapotion.cpp \
    src/trab3/item/potion/potion.cpp \
    src/trab3/item/weapon/weapon.cpp \
    src/trab3/item/item.cpp \
    src/trab3/team/team.cpp \
    src/trab3/utils/thread.cpp \
    src/trab3/main.cpp
HEADERS += \
    src/trab3/character/characters/knight.h \
    src/trab3/character/characters/thief.h \
    src/trab3/character/characters/wizard.h \
    src/trab3/character/character.h \
    src/trab3/character/characters.h \
    src/trab3/character/inventory.h \
    src/trab3/game/game.h \
    src/trab3/item/armor/armor.h \
    src/trab3/item/potion/potions/healthpotion.h \
    src/trab3/item/potion/potions/manapotion.h \
    src/trab3/item/potion/potion.h \
    src/trab3/item/weapon/weapon.h \
    src/trab3/item/item.h \
    src/trab3/item/items.h \
    src/trab3/team/color.h \
    src/trab3/team/team.h \
    src/trab3/utils/thread.h
