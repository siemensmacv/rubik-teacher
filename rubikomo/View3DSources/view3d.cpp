#include "./View3DHeaders/view3d.h"

View3D::View3D(ModelRubik *model3D, Ui::MainWindow *ui)
{
    m_model3D = model3D;
    m_ui=ui;
    timer=new QTimer(this);
    connect(timer,&QTimer::timeout,
            this,&View3D::onAnimationEnded);
    connect(m_model3D,&ModelRubik::cubeChanged,
            this,&View3D::onInput);

    // Root entity
    rootEntity = new Qt3DCore::QEntity();

    view = new Qt3DExtras::Qt3DWindow();
    view->defaultFrameGraph()->setClearColor(QColor(QRgb(0xAAAAAA)));
    container = QWidget::createWindowContainer(view);

    // Camera
    Qt3DRender::QCamera *cameraEntity = view->camera();

    cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 100.0f);
    cameraEntity->setPosition(QVector3D(5.0f, 5.0f, 5.0f));
    cameraEntity->setUpVector(QVector3D(0, 1, 0));
    cameraEntity->setViewCenter(QVector3D(0, 0, 0));

    // For camera controls
    Qt3DExtras::QFirstPersonCameraController *camController = new Qt3DExtras::QFirstPersonCameraController(rootEntity);
    camController->setCamera(cameraEntity);

    // Lighting
    Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor("white");
    light->setIntensity(1);
    lightEntity->addComponent(light);
    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
    lightTransform->setTranslation(QVector3D(0.0f, 0.0f, 5.0f));
    lightEntity->addComponent(lightTransform);

    // Lighting 2
    Qt3DCore::QEntity *lightEntity2 = new Qt3DCore::QEntity(rootEntity);
    Qt3DRender::QPointLight *light2 = new Qt3DRender::QPointLight(lightEntity2);
    light2->setColor("white");
    light2->setIntensity(1);
    lightEntity2->addComponent(light);
    Qt3DCore::QTransform *lightTransform2 = new Qt3DCore::QTransform(lightEntity2);
    lightTransform2->setTranslation(QVector3D(5.0f, 0.0f, 0.0f));
    lightEntity2->addComponent(lightTransform2);

    // Lighting 3
    Qt3DCore::QEntity *lightEntity3 = new Qt3DCore::QEntity(rootEntity);
    Qt3DRender::QPointLight *light3 = new Qt3DRender::QPointLight(lightEntity3);
    light3->setColor("white");
    light3->setIntensity(1);
    lightEntity3->addComponent(light3);
    Qt3DCore::QTransform *lightTransform3 = new Qt3DCore::QTransform(lightEntity3);
    lightTransform3->setTranslation(QVector3D(0.0f, 5.0f, 0.0f));
    lightEntity3->addComponent(lightTransform3);


    // Lighting 4
    Qt3DCore::QEntity *lightEntity4 = new Qt3DCore::QEntity(rootEntity);
    Qt3DRender::QPointLight *light4 = new Qt3DRender::QPointLight(lightEntity4);
    light4->setColor("white");
    light4->setIntensity(1);
    lightEntity4->addComponent(light4);
    Qt3DCore::QTransform *lightTransform4 = new Qt3DCore::QTransform(lightEntity4);
    lightTransform4->setTranslation(QVector3D(-3.0f, -3.0f, -3.0f));
    lightEntity4->addComponent(lightTransform4);

    // Set root object of the scene
    view->setRootEntity(rootEntity);

    initCube3D();
}


void View3D::onInput(int load)
{
    if(load==0){
        cubeEntity->setEnabled(false);
        initCube3D();
        reset();
        theCube->updateColors(m_model3D);
    }
}


void View3D::reset(){
    theCube->resetColors();
}


void View3D::initCube3D(){
    cubeEntity = new Qt3DCore::QEntity(rootEntity);

    theCube=new Cube3D(m_model3D,cubeEntity);
}


void View3D::toggleAllButtons(bool toggle)
{
    m_ui->U_PushButton_3D->setEnabled(toggle);
    m_ui->UR_PushButton_3D->setEnabled(toggle);

    m_ui->D_PushButton_3D->setEnabled(toggle);
    m_ui->DR_PushButton_3D->setEnabled(toggle);

    m_ui->F_PushButton_3D->setEnabled(toggle);
    m_ui->FR_PushButton_3D->setEnabled(toggle);

    m_ui->B_PushButton_3D->setEnabled(toggle);
    m_ui->BR_PushButton_3D->setEnabled(toggle);

    m_ui->L_PushButton_3D->setEnabled(toggle);
    m_ui->LR_PushButton_3D->setEnabled(toggle);

    m_ui->R_PushButton_3D->setEnabled(toggle);
    m_ui->RR_PushButton_3D->setEnabled(toggle);
}

QWidget *View3D::getContainer() const
{
    return container;
}

void View3D::UpC()
{
    toggleAllButtons(false);
    theCube->UpC();
    timer->start(ANIMATION_DURATION);
}
void View3D::UpCC()
{
    toggleAllButtons(false);
    theCube->UpCC();
    timer->start(ANIMATION_DURATION);
}

void View3D::DownC()
{
    toggleAllButtons(false);
    theCube->DownC();
    timer->start(ANIMATION_DURATION);
}

void View3D::DownCC()
{
    toggleAllButtons(false);
    theCube->DownCC();
    timer->start(ANIMATION_DURATION);
}

void View3D::FrontC()
{
    toggleAllButtons(false);
    theCube->FrontC();
    timer->start(ANIMATION_DURATION);
}
void View3D::FrontCC()
{
    toggleAllButtons(false);
    theCube->FrontCC();
    timer->start(ANIMATION_DURATION);
}

void View3D::BackC()
{
    toggleAllButtons(false);
    theCube->BackC();
    timer->start(ANIMATION_DURATION);
}
void View3D::BackCC()
{
    toggleAllButtons(false);
    theCube->BackCC();
    timer->start(ANIMATION_DURATION);
}

void View3D::RightC()
{
    toggleAllButtons(false);
    theCube->RightC();
    timer->start(ANIMATION_DURATION);
}
void View3D::RightCC()
{
    toggleAllButtons(false);
    theCube->RightCC();
    timer->start(ANIMATION_DURATION);
}

void View3D::LeftC()
{
    toggleAllButtons(false);
    theCube->LeftC();
    timer->start(ANIMATION_DURATION);
}

void View3D::LeftCC()
{
    toggleAllButtons(false);
    theCube->LeftCC();
    timer->start(ANIMATION_DURATION);
}

void View3D::onAnimationEnded()
{
    toggleAllButtons(true);
}

