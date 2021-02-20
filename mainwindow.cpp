#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Widget = new QWidget();
    GridLayout = new QGridLayout();
    SevenLCD = new DigitalIndicator;
    long double a = 20.345678;
    SevenLCD->SetValue(a);//Если > символов, чем задано define, выводит нули красным!
    GridLayout->addWidget(SevenLCD);
    Widget->setLayout(GridLayout);
    setCentralWidget(Widget);



}

MainWindow::~MainWindow()
{
    delete ui;
}
