#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <DigitalIndicator.h>
#include <QGridLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWidget *Widget;
    QGridLayout *GridLayout;
    DigitalIndicator *SevenLCD;


};

#endif // MAINWINDOW_H
