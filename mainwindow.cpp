#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    #define ARDUSIM
    #define ENABLE_API_NAME
    #define __AVR_ATmega328P__
    #define ARDUINO=100


    QString filename = "./leonardo-small.png";
    QImage image(filename);
    ui->label->setPixmap(QPixmap::fromImage(image));


}

MainWindow::~MainWindow()
{
    delete ui;
}


