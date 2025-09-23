QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    escull_color.cpp \
    main.cpp \
    mainwindow.cpp \
    numero_i_texto.cpp \
    rellotge_digital.cpp

HEADERS += \
    escull_color.h \
    mainwindow.h \
    numero_i_texto.h \
    rellotge_digital.h

FORMS += \
    escull_color.ui \
    mainwindow.ui \
    numero_i_texto.ui \
    rellotge_digital.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
