#include "./View3DHeaders/plane.h"

Plane::Plane(Qt3DCore::QEntity *rootEntity) :
    Shape3D(rootEntity)
{

    m_planeMesh = new Qt3DExtras::QPlaneMesh();
    m_shapeEntity->addComponent(m_planeMesh);
    m_shapeTransform->setScale(0.9f);

}

