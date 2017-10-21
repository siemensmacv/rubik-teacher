#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    float tabWidth = (ui->tabWidget->width()*3-34);
    ui->tabWidget->setStyleSheet("QTabWidget QTabBar::tab{width:" + QString::number(tabWidth) + "px; }");
    ui->tabWidget->setCurrentIndex(2);

     m_view3D = new View3D(&controllerRubik.model.corners_edges,ui);

    ui->gridLayout_3->addWidget(m_view3D->getContainer());

    connect(ui->U_PushButton_3D,&QPushButton::clicked,
            m_view3D,&View3D::UpC);
    connect(ui->UR_PushButton_3D,&QPushButton::clicked,
            m_view3D,&View3D::UpCC);

    connect(ui->D_PushButton_3D,&QPushButton::clicked,
            m_view3D,&View3D::DownC);
    connect(ui->DR_PushButton_3D,&QPushButton::clicked,
            m_view3D,&View3D::DownCC);

    connect(ui->F_PushButton_3D,&QPushButton::clicked,
            m_view3D,&View3D::FrontC);
    connect(ui->FR_PushButton_3D,&QPushButton::clicked,
            m_view3D,&View3D::FrontCC);

    connect(ui->B_PushButton_3D,&QPushButton::clicked,
            m_view3D,&View3D::BackC);
    connect(ui->BR_PushButton_3D,&QPushButton::clicked,
            m_view3D,&View3D::BackCC);

    connect(ui->L_PushButton_3D,&QPushButton::clicked,
            m_view3D,&View3D::LeftC);
    connect(ui->LR_PushButton_3D,&QPushButton::clicked,
            m_view3D,&View3D::LeftCC);

    connect(ui->R_PushButton_3D,&QPushButton::clicked,
            m_view3D,&View3D::RightC);
    connect(ui->RR_PushButton_3D,&QPushButton::clicked,
            m_view3D,&View3D::RightCC);
}

MainWindow::~MainWindow()
{
    delete ui;
}
