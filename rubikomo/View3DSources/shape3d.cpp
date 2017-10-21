#include "./View3DHeaders/shape3d.h"

Shape3D::Shape3D(Qt3DCore::QEntity *rootEntity)
{
    m_shapeEntity=new Qt3DCore::QEntity(rootEntity);

    m_shapeTransform=new Qt3DCore::QTransform(m_shapeEntity);
    m_shapeMaterial = new Qt3DExtras::QPhongMaterial(m_shapeEntity);
    m_shapeMaterial->setDiffuse(QColor(255,255,255));

    m_shapeEntity->addComponent(m_shapeMaterial);
    m_shapeEntity->addComponent(m_shapeTransform);

}

void Shape3D::setShapeTransform(Qt3DCore::QTransform *shapeTransform)
{
    m_shapeTransform = shapeTransform;
}

void Shape3D::setShapeMaterial(Qt3DExtras::QPhongMaterial *shapeMaterial)
{
    m_shapeMaterial = shapeMaterial;
}

void Shape3D::setShapeEntity(Qt3DCore::QEntity *shapeEntity)
{
    m_shapeEntity = shapeEntity;
}

Qt3DCore::QTransform *Shape3D::shapeTransform() const
{
    return m_shapeTransform;
}
