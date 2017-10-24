#include "cuboid.h"
#include <QDebug>

Cuboid::Cuboid(Qt3DCore::QEntity *rootEntity)
{

    relativeAxis=new AxisHandler();

    m_rootEntity = rootEntity;

    // Cuboid shape data
    m_cuboidMesh = new Qt3DExtras::QCuboidMesh();
//    m_cuboidMesh->setMinorRadius(0.3f);
//    m_cuboidMesh->setRadius(0.6f);

    // CuboidMesh Transform
    m_cuboidTransform = new Qt3DCore::QTransform();
    m_cuboidTransform->setScale(1.0f);
    //m_cuboidTransform->setTranslation(QVector3D(1.0f, 1.0f, 0.0f));

    m_cuboidMaterial = new Qt3DExtras::QPhongMaterial();
    m_cuboidMaterial->setDiffuse(QColor(QRgb(0xFF0000)));

    //Cuboid
    m_cuboidEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_cuboidEntity->addComponent(m_cuboidMesh);
    m_cuboidEntity->addComponent(m_cuboidTransform);
    m_cuboidEntity->addComponent(m_cuboidMaterial);

    connect(m_cuboidTransform, &Qt3DCore::QTransform::translationChanged,
            this, &Cuboid::newTranslation);
}

void Cuboid::newTranslation()
{
    //qDebug() << m_cuboidTransform->translation();
}
