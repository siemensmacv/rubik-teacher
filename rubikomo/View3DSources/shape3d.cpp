#include "./View3DHeaders/shape3d.h"

Shape3D::Shape3D()
{

}

void Shape3D::setShapeTransform(QTransform *shapeTransform)
{
    m_shapeTransform = shapeTransform;
}

void Shape3D::setShapeMaterial(Qt3DRender::QMaterial *shapeMaterial)
{
    m_shapeMaterial = shapeMaterial;
}

void Shape3D::setShapeEntity(Qt3DCore::QEntity *shapeEntity)
{
    m_shapeEntity = shapeEntity;
}

void Shape3D::setAnimHandler(AnimationHandler *animHandler)
{
    m_animHandler = animHandler;
}
