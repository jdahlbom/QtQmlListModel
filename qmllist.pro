QT       += core gui quick

TARGET = qmllist
TEMPLATE = app

SOURCES += main.cpp\
    SimpleListModel.cpp

HEADERS  +=\
    SimpleListModel.h \
    DataObject.h

# This is needed for getting the QML file copied into the OSX application bundle.
QML_FILES.files = myuiscript.qml
QML_FILES.path = Contents/MacOS

QMAKE_BUNDLE_DATA += QML_FILES
