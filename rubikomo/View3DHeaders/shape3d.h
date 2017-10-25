#ifndef SHAPE3D_H
#define SHAPE3D_H

#include <Qt3DCore>
#include <Qt3DRender>
#include <Qt3DExtras>
#include <QPropertyAnimation>

class Shape3D
{
public:
    Shape3D(Qt3DCore::QEntity *rootEntity);

    void setShapeTransform(Qt3DCore::QTransform *shapeTransform);
    void setShapeMaterial(Qt3DExtras::QPhongMaterial *shapeMaterial);
    void setShapeEntity(Qt3DCore::QEntity *shapeEntity);

    void setColor(QColor color);

    Qt3DCore::QTransform *shapeTransform() const;

    Qt3DCore::QEntity *entity() const;

protected:
    Qt3DCore::QTransform *m_shapeTransform;
    Qt3DExtras::QPhongMaterial *m_shapeMaterial;
    Qt3DCore::QEntity *m_shapeEntity;

};

#endif // SHAPE3D_H
