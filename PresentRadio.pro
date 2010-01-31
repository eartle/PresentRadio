# -------------------------------------------------
# Project created by QtCreator 2010-01-28T17:09:20
# -------------------------------------------------
QT += network \
    xml \
    phonon

TARGET = PresentRadio
TEMPLATE = app
LIBS += -llastfm -lqjson

mac { 
    HEADERS += BluetoothDeviceInquiryMac.h \
        CocoaInitializer.h
    OBJECTIVE_SOURCES += BluetoothDeviceInquiryMac.mm \
        CocoaInitializer.mm
    LIBS += -framework \
        IOBluetooth \
        -framework \
        Foundation \
        -framework \
        AppKit
}

SOURCES += main.cpp \
    mainwindow.cpp \
    bluetoothdevicemodel.cpp \
    radio.cpp

HEADERS += mainwindow.h \
    bluetoothdeviceinquiryinterface.h \
    bluetoothdevicemodel.h \
    radio.h

FORMS += mainwindow.ui