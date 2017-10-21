#include "./View3DHeaders/view3d.h"

View3D::View3D(ModelRubik_CornersEdges *model3D)
{
    m_model3D = model3D;
    initCube3D();
}

void View3D::initCube3D(){
    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();


    view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x00AA00)));
    container = QWidget::createWindowContainer(view);


    // Root entity
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;

    // Camera
    Qt3DRender::QCamera *cameraEntity = view->camera();

    cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 100.0f);
    cameraEntity->setPosition(QVector3D(3.0f, 5.0f, 5.0f));
    cameraEntity->setUpVector(QVector3D(0, 1, 0));
    cameraEntity->setViewCenter(QVector3D(0, 0, 0));

    // Lighting
    Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor("white");
    light->setIntensity(1);
    lightEntity->addComponent(light);
    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
    lightTransform->setTranslation(QVector3D(5.0f, 5.0f, 5.0f));
    lightEntity->addComponent(lightTransform);

    // Lighting 2
    Qt3DCore::QEntity *lightEntity2 = new Qt3DCore::QEntity(rootEntity);
    Qt3DRender::QPointLight *light2 = new Qt3DRender::QPointLight(lightEntity);
    light2->setColor("white");
    light2->setIntensity(2);
    lightEntity2->addComponent(light);
    Qt3DCore::QTransform *lightTransform2 = new Qt3DCore::QTransform(lightEntity);
    lightTransform2->setTranslation(QVector3D(-5.0f, -5.0f, -5.0f));
    lightEntity2->addComponent(lightTransform2);

    theCube=new Cube3D(m_model3D,rootEntity);
    // Set root object of the scene
    view->setRootEntity(rootEntity);
}

QWidget *View3D::getContainer() const
{
    return container;
}

void View3D::test()
{
    theCube->test();
}

