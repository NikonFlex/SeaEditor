#-------------------------------------------------
#
# Project created by QtCreator 2021-11-28T15:45:12
#
#-------------------------------------------------

QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EditorApp
TEMPLATE = app

CONFIG += c++11

INCLUDEPATH += ../../bip/Source/emulator \
../../bip/Source/emulator/include \
../../bip/Source/emulator/geodesy/include


SOURCES += main.cpp\
editor.cpp \
addroutepointtool.cpp \
addroutetool.cpp \
appendshiptool.cpp \
basetool.cpp \
defaulttool.cpp \
deleteroutecommand.cpp \
deleteroutepointtool.cpp \
deletshiptool.cpp \
dropouttoolbutton.cpp \
editormath.cpp \
editroutetool.cpp \
movetool.cpp \
rotatetool.cpp \
route.cpp \
routepropertyview.cpp \
screenview.cpp \
shiplabel.cpp \
starteditordialog.cpp \
svgiconset.cpp \
targetpropertyview.cpp \
viewmodel.cpp \
zoomallcommand.cpp \



HEADERS  += editor.h \
addroutetool.h \
appendtool.h \
basetool.h \
defaulttool.h \
deleteroutecommand.h \
deleteroutepointtool.h \
deletetool.h \
dropouttoolbutton.h \
editor.h \
editormath.h \
editroutetool.h \
interfacecommand.h \
interfacesceneview.h \
interfacetool.h \
movetool.h \
rotatetool.h \
route.h \
routepropertyview.h \
scenarioeditutils.h \
screenview.h \
shiplabel.h \
starteditordialog.h \
svgiconset.h \
targetpropertyview.h \
viewmodel.h \
zoomallcommand.h \
addroutepointtool.h

FORMS    += editor.ui \
routepropertyview.ui \
starteditordialog.ui \
targetpropertyview.ui \

RESOURCES += \
    resources.qrc
