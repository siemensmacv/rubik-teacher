#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowState(windowState() & ~(Qt::WindowMinimized | Qt::WindowFullScreen) | Qt::WindowMaximized);

    m_view2D = new View2D(this, &controllerRubik.model);

    float tabWidth = (ui->tabWidget->width()*3-34);
    ui->tabWidget->setStyleSheet("QTabWidget QTabBar::tab{width:" + QString::number(tabWidth) + "px; }");
    ui->tabWidget->setCurrentIndex(2);

    m_view3D = new View3D(&controllerRubik.model,ui);

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

    ui->horizontalLayout->insertLayout(0, m_view2D->getLayout());
    ui->gridLayout_3->addWidget(m_view3D->getContainer());

    connectFlatButtonsToSlots();
    connectRadioButtonsToSlots();

    m_colorinput = new View2D(this, &m_inputmodel, true);
    ui->horizontalLayout_4->insertLayout(0, m_colorinput->getLayout());

    ui->radioButton_Green->toggle();
    m_colorinput->setInputColor(RubikFace::Front);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectFlatButtonsToSlots()
{
    connect(ui->pushButton_BR_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_B_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_DR_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_D_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_FR_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_F_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_LR_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_L_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_RR_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_R_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_UR_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_U_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_XR_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_X_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_YR_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_Y_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_ZR_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_Z_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
}

void MainWindow::connectRadioButtonsToSlots()
{
    connect(ui->radioButton_Blue, &QRadioButton::toggled, this, &MainWindow::handleInputRadio);
    connect(ui->radioButton_Green, &QRadioButton::toggled, this, &MainWindow::handleInputRadio);
    connect(ui->radioButton_Orange, &QRadioButton::toggled, this, &MainWindow::handleInputRadio);
    connect(ui->radioButton_Red, &QRadioButton::toggled, this, &MainWindow::handleInputRadio);
    connect(ui->radioButton_White, &QRadioButton::toggled, this, &MainWindow::handleInputRadio);
    connect(ui->radioButton_Yellow, &QRadioButton::toggled, this, &MainWindow::handleInputRadio);
}

void MainWindow::handleButton()
{
    QString senderName = sender()->objectName();
    if(senderName == "pushButton_U_2D")
    {
        controllerRubik.rotateFaceClockwise(RubikFace::Up);
    }
    else if(senderName == "pushButton_UR_2D")
    {
        controllerRubik.rotateFaceCounterClockwise(RubikFace::Up);
    }
    else if(senderName == "pushButton_D_2D")
    {
        controllerRubik.rotateFaceClockwise(RubikFace::Down);
    }
    else if(senderName == "pushButton_DR_2D")
    {
        controllerRubik.rotateFaceCounterClockwise(RubikFace::Down);
    }
    else if(senderName == "pushButton_F_2D")
    {
        controllerRubik.rotateFaceClockwise(RubikFace::Front);
    }
    else if(senderName == "pushButton_FR_2D")
    {
        controllerRubik.rotateFaceCounterClockwise(RubikFace::Front);
    }
    else if(senderName == "pushButton_B_2D")
    {
        controllerRubik.rotateFaceClockwise(RubikFace::Back);
    }
    else if(senderName == "pushButton_BR_2D")
    {
        controllerRubik.rotateFaceCounterClockwise(RubikFace::Back);
    }
    else if(senderName == "pushButton_L_2D")
    {
        controllerRubik.rotateFaceClockwise(RubikFace::Left);
    }
    else if(senderName == "pushButton_LR_2D")
    {
        controllerRubik.rotateFaceCounterClockwise(RubikFace::Left);
    }
    else if(senderName == "pushButton_R_2D")
    {
        controllerRubik.rotateFaceClockwise(RubikFace::Right);
    }
    else if(senderName == "pushButton_RR_2D")
    {
        controllerRubik.rotateFaceCounterClockwise(RubikFace::Right);
    }
    else if(senderName == "pushButton_X_2D")
    {
        controllerRubik.rotateXAxisClockwise();
    }
    else if(senderName == "pushButton_XR_2D")
    {
        controllerRubik.rotateXAxisCounterClockwise();
    }
    else if(senderName == "pushButton_Y_2D")
    {
        controllerRubik.rotateYAxisClockwise();
    }
    else if(senderName == "pushButton_YR_2D")
    {
        controllerRubik.rotateYAxisCounterClockwise();
    }
    else if(senderName == "pushButton_Z_2D")
    {
        controllerRubik.rotateZAxisClockwise();
    }
    else if(senderName == "pushButton_ZR_2D")
    {
        controllerRubik.rotateZAxisCounterClockwise();
    }
}

void MainWindow::handleInputRadio()
{
    QString senderName = sender()->objectName();
    if(senderName == "radioButton_Blue")
    {
        m_colorinput->setInputColor(RubikFace::Back);
    }
    else if(senderName == "radioButton_Green")
    {
        m_colorinput->setInputColor(RubikFace::Front);
    }
    else if(senderName == "radioButton_Orange")
    {
        m_colorinput->setInputColor(RubikFace::Right);
    }
    else if(senderName == "radioButton_Red")
    {
        m_colorinput->setInputColor(RubikFace::Left);
    }
    else if(senderName == "radioButton_White")
    {
        m_colorinput->setInputColor(RubikFace::Down);
    }
    else if(senderName == "radioButton_Yellow")
    {
        m_colorinput->setInputColor(RubikFace::Up);
    }
}

void MainWindow::validateAndLoadInput()
{
    RubikValidator validator(m_inputmodel.getModel());
    if(validator() == true)
        controllerRubik.setModel(m_inputmodel.getModel());
    else
        qInfo("Nem");
}
