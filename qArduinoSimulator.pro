#-------------------------------------------------
#
# Project created by QtCreator 2019-12-25T23:08:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qArduinoSimulator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

#DEFINES += __cplusplus=201104L


DEFINES += ARDUSIM
DEFINES += ENABLE_API_NAME
DEFINES += __AVR_ATmega328P__
DEFINES += ARDUINO=100
#DEFINES += ARDUINO_MAIN
#DEFINES +=SKETCH
DEFINES += F_CPU=1000000UL
QMAKE_CXXFLAGS += -fdiagnostics-color -DARDUSIM -std=c++11
QMAKE_CFLAGS += -fdiagnostics-color -DARDUSIM -std=c++11

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#all the standard arduinoIDE includes are compatable with this compile to make sketches compatable.
#please include the paths here
INCLUDEPATH += ./arduino/cores ./arduino/variants ./include ./arduino/variants/eightanaloginputs
#INCLUDEPATH += ./arduino-1.8.9/hardware/tools/avr/avr/include/
SOURCES += \
    main.cpp \
    mainwindow.cpp \
    arduino/cores/WString.cpp \
    arduino/cores/WMath.cpp \
    arduino/cores/USBCore.cpp \
    arduino/cores/Tone.cpp \
    arduino/cores/Stream.cpp \
    arduino/cores/Print.cpp \
    arduino/cores/new.cpp \
    arduino/cores/IPAddress.cpp \
    arduino/cores/HID.cpp \
    arduino/cores/HardwareSerial.cpp \
    arduino/cores/CDC.cpp \
    arduino/cores/wiring.c \
    arduino/cores/wiring_digital.c \
    arduino/cores/wiring_pulse.c \
    arduino/cores/wiring_shift.c \
    arduino/cores/wiring_analog.c

HEADERS += \
        mainwindow.h \
    arduino/cores/WString.h \
    arduino/cores/wiring_private.h \
    arduino/cores/WCharacter.h \
    arduino/cores/USBDesc.h \
    arduino/cores/USBCore.h \
    arduino/cores/USBAPI.h \
    arduino/cores/Udp.h \
    arduino/cores/Stream.h \
    arduino/cores/Server.h \
    arduino/cores/Printable.h \
    arduino/cores/Print.h \
    arduino/cores/Platform.h \
    arduino/cores/new.h \
    arduino/cores/IPAddress.h \
    arduino/cores/HardwareSerial.h \
    arduino/cores/Client.h \
    arduino/cores/binary.h \
    arduino/cores/ardusim.h \
    arduino/cores/Arduino.h \
    arduino/variants/eightanaloginputs/pins_arduino.h \
    arduino/variants/leonardo/pins_arduino.h \
    arduino/variants/mega/pins_arduino.h \
    arduino/variants/micro/pins_arduino.h \
    arduino/variants/standard/pins_arduino.h \
    include/avr/common.h \
    include/avr/eeprom.h \
    include/avr/fuse.h \
    include/avr/interrupt.h \
    include/avr/io.h \
    include/avr/iom1280.h \
    include/avr/iom168p.h \
    include/avr/iom2560.h \
    include/avr/iom328p.h \
    include/avr/lock.h \
    include/avr/pgmspace.h \
    include/avr/portpins.h \
    include/avr/sfr_defs.h \
    include/avr/version.h \
    include/avr/wdt.h \
    include/util/atomic.h \
    include/util/crc16.h \
    include/util/delay.h \
    include/util/delay_basic.h \
    include/util/parity.h \
    include/util/setbaud.h \
    include/util/twi.h \
    arduino/variants/standard/pins_arduino.h \
    include/util/delay.h \
    sketch/sketch.h \
    arduino/cores/wiring_private.h

FORMS += \
        mainwindow.ui
