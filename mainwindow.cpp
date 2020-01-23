

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include "QDebug"

#include "ardusim.h"

//#include <Arduino.h>
//#include <stdio.h>


#include <sketch/sketch.h>


//void setup();
//void loop();

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


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    QString filename = "./leonardo-small.png";
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
 //   qDebug() << "Update...";
    loop();
}

