

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
//#include "QDebug"


#define F_CPU 1000000UL  // testing this cpu speed.

#include "ardusim.h"

#include <QElapsedTimer>
#include <qthread.h>




//////////  INO SKETCH AREA

//Place INO files here

#include <Arduino.h> // sometimes sketch has this already

//#include <stdio.h>
//#include "./scripting/TinyBasicPlus/TinyBasicPlus/TinyBasicPlus.ino" non working
//#include "scripting/Pymite/Arduino-Pymite.ino"




#include <sketch/sketch.h> //default sketch

////////////////////////////////////////////////

static MainWindow* g_mainWindow = nullptr; // Global pointer to our GUI

extern "C" void gui_update_pin(int pin, int val) {
    if (g_mainWindow) {
        QMetaObject::invokeMethod(g_mainWindow, "updatePin", Qt::QueuedConnection,
                                  Q_ARG(int, pin), Q_ARG(int, val));
    }
}

extern "C" void gui_update_pin_mode(int pin, int mode) {
    if (g_mainWindow) {
        QMetaObject::invokeMethod(g_mainWindow, "updatePinMode", Qt::QueuedConnection,
                                  Q_ARG(int, pin), Q_ARG(int, mode));
    }
}

// Prevent GUI from freezing during Arduino delay()
extern "C" void gui_delay(unsigned long ms) {
    if (g_mainWindow) {
        QElapsedTimer timer;
        timer.start();
        while (timer.elapsed() < (long)ms) {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
            QThread::msleep(10);
        }
    }
}






void MainWindow::updatePin(int pin, int val) {
    // Find all buttons in the UI that display this pin number
    QList<QPushButton*> allButtons = findChildren<QPushButton*>();
    for (QPushButton* btn : allButtons) {
        if (btn->text() == QString::number(pin)) {
            if (val) {
                btn->setStyleSheet("background-color: red; color: white; font-weight: bold;");
            } else {
                btn->setStyleSheet(""); // Reset to default
            }
        }
    }

    // Optional: Log to the console list widget
    ui->listWidget->addItem(QString("Pin %1 set to %2").arg(pin).arg(val ? "HIGH" : "LOW"));
    if(ui->listWidget->count() > 50) delete ui->listWidget->takeItem(0);
}

void MainWindow::updatePinMode(int pin, int mode) {
    QList<QPushButton*> allButtons = findChildren<QPushButton*>();
    for (QPushButton* btn : allButtons) {
        if (btn->text() == QString::number(pin)) {
            QString modeStr = (mode == INPUT) ? "INPUT" : "OUTPUT";
            btn->setToolTip(QString("Pin %1 (Mode: %2)").arg(pin).arg(modeStr));
        }
    }
}





////////// previously Main.c imported into mainwindow
uint8_t SIM_SFR[65536] = {0};
uint8_t SIM_MEM[65536] = {0};

void cli()
{
    fprintf(stderr, "[MCU] Global interrupt disabled\n");
}

void sei()
{
    fprintf(stderr, "[MCU] Global interrupt enabled\n");
}

int mainArduino(void)
{
    unsigned int loopcount = 0;

    fprintf(stderr, "ARDUSIM 0.1 - A Practical Arduino Simulator (C)2012 Written by Stanley Huang\n\n");

    init();
#if defined(USBCON)
    USB.attach();
#endif
    setup();
//  for (;;) {
    loop();
//        //update gui here

//        //if (serialEventRun) serialEventRun();
//        fprintf(stderr, "Loop %d\r", ++loopcount);
//        usleep(50000);
//   }
//   return 0;
      //  startTimer(0);
}
////////////////////////////////////////////////




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    QString filename = QApplication::applicationDirPath() + "/leonardo-small.png";
    QImage image(filename);
   ui->label->setPixmap(QPixmap::fromImage(image));

    //initArduino()
    mainArduino();
    //hook loop() to timer
   timerId = startTimer(1000);
}

MainWindow::~MainWindow()
{
       killTimer(timerId);
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    qDebug() << "Update...";
    loop();
}

