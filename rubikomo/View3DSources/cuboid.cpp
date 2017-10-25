#include "./View3DHeaders/cuboid.h"

Cuboid::Cuboid(Qt3DCore::QEntity *rootEntity) :
    Shape3D(rootEntity)
{
    m_cuboidMesh = new Qt3DExtras::QCuboidMesh(m_shapeEntity);
    m_shapeEntity->addComponent(m_cuboidMesh);
    m_shapeMaterial->setDiffuse(QColor(0,0,0));
    m_axisHandler = new AxisHandler();
}
