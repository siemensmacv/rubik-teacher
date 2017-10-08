#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //face = new FaceCube2D(ui->gridLayoutWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}
