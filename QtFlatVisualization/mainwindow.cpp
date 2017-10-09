#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //face = new FaceCube2D(ui->gridLayoutWidget);
    ui->gridLayout->addWidget(new FaceCube2D(ui->gridLayoutWidget, QString("UUUUUUUUU")), 0, 1);
    ui->gridLayout->addWidget(new FaceCube2D(ui->gridLayoutWidget, QString("LLLLLLLLL")), 1, 0);
    ui->gridLayout->addWidget(new FaceCube2D(ui->gridLayoutWidget, QString("FFFFFFFFF")), 1, 1);
    ui->gridLayout->addWidget(new FaceCube2D(ui->gridLayoutWidget, QString("BBBBBBBBB")), 1, 2);
    ui->gridLayout->addWidget(new FaceCube2D(ui->gridLayoutWidget, QString("RRRRRRRRR")), 1, 3);
    ui->gridLayout->addWidget(new FaceCube2D(ui->gridLayoutWidget, QString("DDDDDDDDD")), 2, 1);


}

MainWindow::~MainWindow()
{
    delete ui;
}
