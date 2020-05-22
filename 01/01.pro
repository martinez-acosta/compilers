TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += \
        main.cpp \
    cmdline.c

HEADERS += \
    cmdline.h \
    state.h \
    nfa.h
