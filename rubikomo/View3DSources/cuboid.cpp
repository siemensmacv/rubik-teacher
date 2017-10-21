#include "./View3DHeaders/cuboid.h"

Cuboid::Cuboid(Qt3DCore::QEntity *rootEntity,bool isCorner) :
    Shape3D(rootEntity)
{
    m_isCorner=isCorner;
    m_cuboidMesh = new Qt3DExtras::QCuboidMesh(m_shapeEntity);
    m_shapeEntity->addComponent(m_cuboidMesh);
    m_animHandler = new AnimationHandler(m_shapeTransform,m_isCorner);


}

AnimationHandler *Cuboid::animHandler() const
{
    return m_animHandler;
}
