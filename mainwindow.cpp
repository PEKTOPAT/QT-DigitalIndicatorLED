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
    long long a = -2469414;
    SevenLCD->SetValue(a);//Если > символов, чем задано define, выводит нули красным!
    GridLayout->addWidget(SevenLCD);
    //SevenLCD->SetIndicatorColor(QColor(121,116,246,250));
    Widget->setLayout(GridLayout);
    setCentralWidget(Widget);



}

MainWindow::~MainWindow()
{
    delete ui;
}
