TEMPLATE = app
TARGET = jotty
QT = core gui widgets
CONFIG += c++11

HEADERS += JottyWindow.h \
           JottyEditor.h \
           ConfigManager.h

SOURCES += main.cpp \
           JottyWindow.cpp \
           JottyEditor.cpp \
           ConfigManager.cpp
