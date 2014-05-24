QMAKE_CXXFLAGS += -std=c++0x
QT += widgets

# Add more folders to ship with the application, here
#folder_01.source = qml/AsciiArtGenirator
android{folder_01.source = qmlMobility/AsciiArtGenirator}
!android{folder_01.source = qml/AsciiArtGenirator}
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    model.cpp \
    controller.cpp \
    algorith.cpp \
    onepixelonechar.cpp \
    onepixelmoneychars.cpp \
    onepixelonecharmodel.cpp \
    onepixelmoneycharsmodel.cpp

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
qtcAddDeployment()

HEADERS += \
    model.h \
    controller.h \
    algorith.h \
    onepixelonechar.h \
    algorithmes.h \
    onepixelmoneychars.h \
    onepixelonecharmodel.h \
    onepixelmoneycharsmodel.h \
    tools.h

OTHER_FILES += \
    android/src/org/qtproject/qt5/android/bindings/QtActivity.java \
    android/src/org/qtproject/qt5/android/bindings/QtApplication.java \
    android/src/org/kde/necessitas/ministro/IMinistroCallback.aidl \
    android/src/org/kde/necessitas/ministro/IMinistro.aidl \
    android/AndroidManifest.xml \
    android/version.xml \
    android/res/values-fr/strings.xml \
    android/res/layout/splash.xml \
    android/res/values-pl/strings.xml \
    android/res/values-it/strings.xml \
    android/res/values-zh-rTW/strings.xml \
    android/res/values-nb/strings.xml \
    android/res/values-ja/strings.xml \
    android/res/values-el/strings.xml \
    android/res/values-et/strings.xml \
    android/res/values-fa/strings.xml \
    android/res/values-ms/strings.xml \
    android/res/values-es/strings.xml \
    android/res/values-pt-rBR/strings.xml \
    android/res/values-nl/strings.xml \
    android/res/values-ro/strings.xml \
    android/res/values-de/strings.xml \
    android/res/values-ru/strings.xml \
    android/res/values/libs.xml \
    android/res/values/strings.xml \
    android/res/values-zh-rCN/strings.xml \
    android/res/values-rs/strings.xml \
    android/res/values-id/strings.xml
