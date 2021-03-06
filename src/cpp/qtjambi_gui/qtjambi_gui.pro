QTJAMBILIB = QtJambiGui
TARGET = $$QTJAMBILIB

VERSION = $$QT_VERSION


SOURCES += \
    qtjambi_gui.cpp \
    qtjambi_gui_repository.cpp \
    qtmatrixes.cpp \

HEADERS += \
    qtjambi_gui.h \
    qtmatrixes.h \
    qtjambi_gui_repository.h \
    qtjambi_gui_qhashes.h

include(../qtjambi/qtjambi_include.pri)
include($$QTJAMBI_CPP/$$QTJAMBILIB/generated.pri)

# because qtjambishell_QActionEvent.cpp refers to qaction.h
macx:{
    INCLUDEPATH += $$(QTDIR)/lib/QtWidgets.framework/Headers
    INCLUDEPATH += $$(QTDIR)/include
}
INCLUDEPATH += $$(QTDIR)/include/QtWidgets
INCLUDEPATH += $$(QTDIR)/include/QtPlatformHeaders
INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

# libQtGui.so.4.7.4 is only dependant on libQtCore.so.4
QT = core gui

win32:CONFIG += precompile_header
PRECOMPILED_HEADER = qtjambi_gui_pch.h
