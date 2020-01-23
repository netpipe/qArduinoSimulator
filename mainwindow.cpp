

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ardusim.h"
#define TEST3
#ifdef TEST3
#include <Arduino.h>
#include <stdio.h>


/* Blink without Delay

 Turns on and off a light emitting diode(LED) connected to a digital
 pin, without using the delay() function.  This means that other code
 can run at the same time without being interrupted by the LED code.

 The circuit:
 * LED attached from pin 13 to ground.
 * Note: on most Arduinos, there is already an LED on the board
 that's attached to pin 13, so no hardware is needed for this example.


 created 2005
 by David A. Mellis
 modified 8 Feb 2010
 by Paul Stoffregen

 This example code is in the public domain.


 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */

// constants won't change. Used here to
// set pin numbers:
const int ledPin =  13;      // the number of the LED pin

// Variables will change:
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
}

//unsigned long millis() {
//  printf("stub millis\n");
//  return 0;
//}

//void pinMode(uint8_t pin, uint8_t mode)
//{
//  printf("stub pinMode\n");
//}

//void digitalWrite(uint8_t pin, uint8_t val)
//{
//  printf("stub digitalWrite\n");
//}

void loop()
{
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the
  // difference between the current time and last time you blinked
  // the LED is bigger than the interval at which you want to
  // blink the LED.
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}





////
/// \brief setup
///
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
}

#endif

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    QString filename = "./leonardo-small.png";
    QImage image(filename);
    ui->label->setPixmap(QPixmap::fromImage(image));

//initArduino()
  //  mainArduino();
//hook loop() to timer
}

MainWindow::~MainWindow()
{
    delete ui;
}


