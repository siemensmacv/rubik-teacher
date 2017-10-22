#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mRubik2DHandler = new Rubik2DHandler(ui->gridLayout, ui->horizontalLayoutWidget);

    connect(ui->pushButton, &QPushButton::clicked,
            mRubik2DHandler, &Rubik2DHandler::upClock);

    connect(ui->pushButton_2, &QPushButton::clicked,
            mRubik2DHandler, &Rubik2DHandler::upCounterClock);

    connect(ui->pushButton_3, &QPushButton::clicked,
            mRubik2DHandler, &Rubik2DHandler::downClock);

    connect(ui->pushButton_4, &QPushButton::clicked,
            mRubik2DHandler, &Rubik2DHandler::downCounterClock);

    connect(ui->pushButton_5, &QPushButton::clicked,
            mRubik2DHandler, &Rubik2DHandler::frontClock);

    connect(ui->pushButton_6, &QPushButton::clicked,
            mRubik2DHandler, &Rubik2DHandler::frontCounterClock);

    connect(ui->pushButton_7, &QPushButton::clicked,
            mRubik2DHandler, &Rubik2DHandler::backClock);

    connect(ui->pushButton_8, &QPushButton::clicked,
            mRubik2DHandler, &Rubik2DHandler::backCounterClock);

    connect(ui->pushButton_9, &QPushButton::clicked,
            mRubik2DHandler, &Rubik2DHandler::leftClock);

    connect(ui->pushButton_10, &QPushButton::clicked,
            mRubik2DHandler, &Rubik2DHandler::leftCounterClock);

    connect(ui->pushButton_11, &QPushButton::clicked,
            mRubik2DHandler, &Rubik2DHandler::rightClock);

    connect(ui->pushButton_12, &QPushButton::clicked,
            mRubik2DHandler, &Rubik2DHandler::rightCounterClock);

    connect(ui->pushButton_13, &QPushButton::clicked,
            mRubik2DHandler, &Rubik2DHandler::xAxisClock);

    connect(ui->pushButton_14, &QPushButton::clicked,
            mRubik2DHandler, &Rubik2DHandler::xAxisCounterClock);

    connect(ui->pushButton_15, &QPushButton::clicked,
            mRubik2DHandler, &Rubik2DHandler::yAxisClock);

    connect(ui->pushButton_16, &QPushButton::clicked,
            mRubik2DHandler, &Rubik2DHandler::yAxisCounterClock);

    connect(ui->pushButton_17, &QPushButton::clicked,
            mRubik2DHandler, &Rubik2DHandler::zAxisClock);

    connect(ui->pushButton_18, &QPushButton::clicked,
            mRubik2DHandler, &Rubik2DHandler::zAxisCounterClock);

    connect(ui->pushButton_19, &QPushButton::clicked,
            mRubik2DHandler, &Rubik2DHandler::Solve);

    mFormulaHandler = new FormulaHandler(ui->formulaLayout, ui->horizontalLayoutWidget, mRubik2DHandler);

    connect(mRubik2DHandler, SIGNAL(FormulaChanged(Formula)), mFormulaHandler, SLOT(FormulaChanged(Formula)));
}

MainWindow::~MainWindow()
{
    delete mFormulaHandler;
    delete mRubik2DHandler;
    delete ui;
}
