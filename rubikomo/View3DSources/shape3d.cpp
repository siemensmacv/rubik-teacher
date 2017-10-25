#include "./View3DHeaders/shape3d.h"

Shape3D::Shape3D(Qt3DCore::QEntity *rootEntity)
{
    m_shapeEntity=new Qt3DCore::QEntity(rootEntity);

    m_shapeTransform=new Qt3DCore::QTransform(m_shapeEntity);
    m_shapeMaterial = new Qt3DExtras::QPhongMaterial(m_shapeEntity);
    m_shapeMaterial->setDiffuse(QColor(255,255,255));
    //m_shapeMaterial->setSpecular((QColor(255,255,255));
    m_shapeMaterial->setShininess(0.0f);

    m_shapeEntity->addComponent(m_shapeMaterial);
    m_shapeEntity->addComponent(m_shapeTransform);

}

void Shape3D::setColor(QColor color)
{
    m_shapeMaterial->setDiffuse(color);
}

Qt3DCore::QTransform *Shape3D::shapeTransform() const
{
    return m_shapeTransform;
}

Qt3DCore::QEntity *Shape3D::entity() const
{
    return m_shapeEntity;
}
