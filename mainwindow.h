#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    void cei();
    void cli();
    void setup();
 //   void pinMode(uint8_t pin, uint8_t mode);
 //   void digitalWrite(uint8_t pin, uint8_t val);


  //  void loop();


    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int timerId;

protected:
    void timerEvent(QTimerEvent *event);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
