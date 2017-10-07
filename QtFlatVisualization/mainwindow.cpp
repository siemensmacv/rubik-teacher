#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    face = new FaceCube2D(ui->gridLayoutWidget);
    ui->setupUi(this);
    ui->gridLayout->addWidget(face, 1, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
