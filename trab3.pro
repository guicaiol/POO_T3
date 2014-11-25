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
    src/character/characters/knight.cpp \
    src/character/characters/thief.cpp \
    src/character/characters/wizard.cpp \
    src/character/character.cpp \
    src/character/inventory.cpp \
    src/game/game.cpp \
    src/item/armor/armor.cpp \
    src/item/potion/potions/healthpotion.cpp \
    src/item/potion/potions/manapotion.cpp \
    src/item/potion/potion.cpp \
    src/item/weapon/weapon.cpp \
    src/item/item.cpp \
    src/team/team.cpp \
    src/utils/thread.cpp \
    src/main.cpp \
    src/utils/position.cpp \
    src/game/field.cpp \
    src/utils/timer.cpp
HEADERS += \
    src/character/characters/knight.h \
    src/character/characters/thief.h \
    src/character/characters/wizard.h \
    src/character/character.h \
    src/character/characters.h \
    src/character/inventory.h \
    src/game/game.h \
    src/item/armor/armor.h \
    src/item/potion/potions/healthpotion.h \
    src/item/potion/potions/manapotion.h \
    src/item/potion/potion.h \
    src/item/weapon/weapon.h \
    src/item/item.h \
    src/item/items.h \
    src/team/color.h \
    src/team/team.h \
    src/utils/thread.h \
    src/utils/position.h \
    src/utils/myvector.h \
    src/game/field.h \
    src/utils/timer.h
