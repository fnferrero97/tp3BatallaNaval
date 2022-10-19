QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Barcos/submarino.cpp \
    main.cpp \
    Barcos/barco.cpp \
    Enums/randomrange.cpp \
    Jugador/jugador.cpp \
    Juego/juego.cpp \
    Tablero/tablero.cpp \
    Tablero/tableroataques.cpp \
    Tablero/tablerobarcos.cpp \
    Ventana/mainwindow.cpp

HEADERS += \
    Barcos/barco.h \
    Barcos/crucero.h \
    Barcos/destructor.h \
    Barcos/fragata.h \
    Barcos/lancha.h \
    Barcos/portaaviones.h \
    Barcos/submarino.h \
    Enums/barcos.h \
    Enums/info.h \
    Enums/randomrange.h \
    Jugador/jugador.h \
    Juego/juego.h \
    Tablero/tablero.h \
    Tablero/tableroataques.h \
    Tablero/tablerobarcos.h \
    Ventana/mainwindow.h

FORMS += \
    Ventana/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Ventana/src.qrc

