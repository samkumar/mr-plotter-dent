TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Libraries
include(qtlibbw/bosswave.pri)
include(mr-plotter-qml/mrplotter.pri)

# Default rules for deployment.
include(deployment.pri)
