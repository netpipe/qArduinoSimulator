#include "mainwindow.h"
#include <QApplication>
#include <qthread.h>
#include <QSplashScreen>



class I : public QThread
{
public:
    static void sleep(unsigned long secs) { QThread::sleep(secs); }
};


int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    QPixmap m("./media/logo.png");
    MainWindow w;
    QSplashScreen splash(m);





   splash.show();
  //   QThread::sleep(5);
    splash.finish(&w);
    w.show();

     //   QThread::sleep(10);
    //   QTimer::singleShot(0, manager, SLOT(doDownload(QUrl("https://www.google.com/images/branding/googlelogo/1x/googlelogo_color_272x92dp.png"))));
   // I::sleep(2); // splash is shown for 5 seconds


    return a.exec();
}

//#include <Arduino.h>
