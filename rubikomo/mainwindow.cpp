#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_view2D = new View2D(ui->horizontalLayoutWidget_2, &controllerRubik.model.matrix);
    m_view3D = new View3D(&controllerRubik.model.corners_edges);

    float tabWidth = (ui->tabWidget->width()*3-34);
    ui->tabWidget->setStyleSheet("QTabWidget QTabBar::tab{width:" + QString::number(tabWidth) + "px; }");
    ui->tabWidget->setCurrentIndex(2);

    ui->horizontalLayout->addLayout(m_view2D->getLayout());
    ui->gridLayout_3->addWidget(m_view3D->getContainer());

    connect(ui->pushButton_23,&QPushButton::clicked,
            m_view3D,&View3D::test);
}

MainWindow::~MainWindow()
{
    delete ui;
}
