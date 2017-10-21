#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m_view3D = new View3D(&controllerRubik.model.corners_edges);

    ui->setupUi(this);
    float tabWidth = (ui->tabWidget->width()*3-34);
    ui->tabWidget->setStyleSheet("QTabWidget QTabBar::tab{width:" + QString::number(tabWidth) + "px; }");
    ui->tabWidget->setCurrentIndex(2);

    ui->gridLayout_3->addWidget(m_view3D->getContainer());
    //for(int i=0;i<9;i++)

    connect(ui->pushButton_19,&QPushButton::clicked,
            m_view3D,&View3D::UpC);
    connect(ui->pushButton_29,&QPushButton::clicked,
            m_view3D,&View3D::RC);
}

MainWindow::~MainWindow()
{
    delete ui;
}
