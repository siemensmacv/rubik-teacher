#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    handler = new Rubik2DHandler(ui->gridLayout, ui->horizontalLayoutWidget);

    connect(ui->pushButton, &QPushButton::clicked,
            handler, &Rubik2DHandler::upClock);

    connect(ui->pushButton_2, &QPushButton::clicked,
            handler, &Rubik2DHandler::upCounterClock);

    connect(ui->pushButton_3, &QPushButton::clicked,
            handler, &Rubik2DHandler::downClock);

    connect(ui->pushButton_4, &QPushButton::clicked,
            handler, &Rubik2DHandler::downCounterClock);

    connect(ui->pushButton_5, &QPushButton::clicked,
            handler, &Rubik2DHandler::frontClock);

    connect(ui->pushButton_6, &QPushButton::clicked,
            handler, &Rubik2DHandler::frontCounterClock);

    connect(ui->pushButton_7, &QPushButton::clicked,
            handler, &Rubik2DHandler::backClock);

    connect(ui->pushButton_8, &QPushButton::clicked,
            handler, &Rubik2DHandler::backCounterClock);

    connect(ui->pushButton_9, &QPushButton::clicked,
            handler, &Rubik2DHandler::leftClock);

    connect(ui->pushButton_10, &QPushButton::clicked,
            handler, &Rubik2DHandler::leftCounterClock);

    connect(ui->pushButton_11, &QPushButton::clicked,
            handler, &Rubik2DHandler::rightClock);

    connect(ui->pushButton_12, &QPushButton::clicked,
            handler, &Rubik2DHandler::rightCounterClock);

    connect(ui->pushButton_13, &QPushButton::clicked,
            handler, &Rubik2DHandler::xAxisClock);

    connect(ui->pushButton_14, &QPushButton::clicked,
            handler, &Rubik2DHandler::xAxisCounterClock);

    connect(ui->pushButton_15, &QPushButton::clicked,
            handler, &Rubik2DHandler::yAxisClock);

    connect(ui->pushButton_16, &QPushButton::clicked,
            handler, &Rubik2DHandler::yAxisCounterClock);

    connect(ui->pushButton_17, &QPushButton::clicked,
            handler, &Rubik2DHandler::zAxisClock);

    connect(ui->pushButton_18, &QPushButton::clicked,
            handler, &Rubik2DHandler::zAxisCounterClock);
}

MainWindow::~MainWindow()
{
    delete ui;
}
