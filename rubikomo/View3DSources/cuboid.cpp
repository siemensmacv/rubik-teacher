#include "./View3DHeaders/cuboid.h"

Cuboid::Cuboid(Qt3DCore::QEntity *rootEntity) :
    Shape3D(rootEntity)
{
    m_cuboidMesh = new Qt3DExtras::QCuboidMesh(m_shapeEntity);
    m_shapeEntity->addComponent(m_cuboidMesh);

    m_animHandler = new AnimationHandler(m_shapeTransform);
}

AnimationHandler *Cuboid::animHandler() const
{
    return m_animHandler;
}
