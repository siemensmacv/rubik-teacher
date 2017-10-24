
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>

#include <Qt3DCore>
#include <Qt3DRender>
#include <Qt3DExtras>
#include <QPropertyAnimation>

#include <rotatingeventhandler.h>
#include <cuboid.h>
#include <orbittransformcontroller.h>

//#include <QCamera>


int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget *widget = new QWidget();

    QHBoxLayout *horizontalLayout = new QHBoxLayout(widget);

    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
    view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x00AA00)));
    QWidget *container = QWidget::createWindowContainer(view);

    QVBoxLayout *verticalLayout = new QVBoxLayout();
    verticalLayout->setAlignment(Qt::AlignTop);

    horizontalLayout->addWidget(container, 1);
    horizontalLayout->addLayout(verticalLayout);

    // Root entity
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;

    // Camera
    Qt3DRender::QCamera *cameraEntity = view->camera();

    cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 100.0f);
    cameraEntity->setPosition(QVector3D(0, 0, 5.0f));
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

    //Cuboids
    Cuboid *cube2 = new Cuboid(rootEntity);
    cube2->m_cuboidTransform->setTranslation(QVector3D(1.0f, 0.0f, 1.0f));

    Cuboid *cube3 = new Cuboid(rootEntity);
    cube3->m_cuboidTransform->setTranslation(QVector3D(0.0f, 0.0f, 1.0f));

    //QMatrix4x4 matrix = cube2->m_cuboidTransform->matrix();
    //matrix.translate(1.0f, 0.0f, 1.0f);
    //cube2->m_cuboidTransform->setMatrix(matrix);

//    OrbitTransformController *cube2Controller = new OrbitTransformController(cube2->m_cuboidTransform);
//    cube2Controller->setTarget(cube2->m_cuboidTransform);
//    cube2Controller->setRadius(1.1f);
//    cube2Controller->setAngle(0.0f);

//    QPropertyAnimation *cube2RotationAnimation = new QPropertyAnimation(cube2->m_cuboidTransform);
//    cube2RotationAnimation->setTargetObject(cube2Controller);
//    cube2RotationAnimation->setPropertyName("angle");
//    cube2RotationAnimation->setStartValue(QVariant::fromValue(static_cast<int>(cube2Controller->angle()) % 360));
//    cube2RotationAnimation->setEndValue(QVariant::fromValue(cube2Controller->angle() + 90));
//    cube2RotationAnimation->setDuration(1000);
//    cube2RotationAnimation->setLoopCount(1);

    // For camera controls
    Qt3DExtras::QFirstPersonCameraController *camController = new Qt3DExtras::QFirstPersonCameraController(rootEntity);
    camController->setCamera(cameraEntity);


    // Set root object of the scene
    view->setRootEntity(rootEntity);

    // Button
    QPushButton *buton = new QPushButton(widget);
    buton->setText(QStringLiteral("R"));
    verticalLayout->addWidget(buton);

    // Button 2
    QPushButton *buton2 = new QPushButton(widget);
    buton2->setText(QStringLiteral("R\'"));
    verticalLayout->addWidget(buton2);

    QPushButton *buton3 = new QPushButton(widget);
    buton3->setText(QStringLiteral("U"));
    verticalLayout->addWidget(buton3);

    QPushButton *buton4 = new QPushButton(widget);
    buton4->setText(QStringLiteral("U\'"));
    verticalLayout->addWidget(buton4);

    QPushButton *buton5 = new QPushButton(widget);
    buton5->setText(QStringLiteral("F"));
    verticalLayout->addWidget(buton5);

    QPushButton *buton6 = new QPushButton(widget);
    buton6->setText(QStringLiteral("F\'"));
    verticalLayout->addWidget(buton6);

    // Rotation
    RotatingEventHandler *handler = new RotatingEventHandler(cube2);
//    handler->addAnimation(cube2->m_cubeAnim);
//    handler->addAnimation((cube2RotationAnimation));

    QObject::connect(buton, &QPushButton::clicked,
                     handler, &RotatingEventHandler::RC);

    QObject::connect(buton2, &QPushButton::clicked,
                     handler, &RotatingEventHandler::RCC);

    QObject::connect(buton3, &QPushButton::clicked,
                     handler, &RotatingEventHandler::UC);

    QObject::connect(buton4, &QPushButton::clicked,
                     handler, &RotatingEventHandler::UCC);

    QObject::connect(buton5, &QPushButton::clicked,
                     handler, &RotatingEventHandler::FC);

    QObject::connect(buton6, &QPushButton::clicked,
                     handler, &RotatingEventHandler::FCC);

//    QObject::connect(cube2->m_cubeAnim, &QPropertyAnimation::finished,
//                     handler, &RotatingEventHandler::animationEnded);

    // Show window
    widget->show();
    widget->resize(800, 600);


    return app.exec();
}
