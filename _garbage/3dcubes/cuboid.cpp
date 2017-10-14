#include "cuboid.h"

Cuboid::Cuboid(Qt3DCore::QEntity *rootEntity)
{
    m_rootEntity = rootEntity;

    // Cuboid shape data
    m_cuboidMesh = new Qt3DExtras::QCuboidMesh();

    // CuboidMesh Transform
    m_cuboidTransform = new Qt3DCore::QTransform();
    m_cuboidTransform->setScale(1.0f);
    m_cuboidTransform->setTranslation(QVector3D(0.0f, 0.0f, 0.0f));

    m_cuboidMaterial = new Qt3DExtras::QPhongMaterial();
    m_cuboidMaterial->setDiffuse(QColor(QRgb(0xFF0000)));

    //Cuboid
    m_cuboidEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_cuboidEntity->addComponent(m_cuboidMesh);
    m_cuboidEntity->addComponent(m_cuboidTransform);
    m_cuboidEntity->addComponent(m_cuboidMaterial);

    //Animation
    m_cubeAnim = new QPropertyAnimation(m_cuboidTransform);
    m_cubeAnim->setTargetObject(m_cuboidTransform);
    m_cubeAnim->setPropertyName("rotationZ");
    m_cubeAnim->setStartValue(QVariant::fromValue(0));
    m_cubeAnim->setEndValue(QVariant::fromValue(90));
    m_cubeAnim->setDuration(1000);
    m_cubeAnim->setLoopCount(1);
    //m_cubeAnim->start();

}
