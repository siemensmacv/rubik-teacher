#ifndef SHAPE3D_H
#define SHAPE3D_H

#include "animationhandler.h"

#include <Qt3DCore>
#include <Qt3DRender>
#include <Qt3DExtras>
#include <QPropertyAnimation>

class Shape3D
{
public:
    explicit Shape3D(Qt3DCore::QEntity *rootEntity);

    void setShapeTransform(Qt3DCore::QTransform *shapeTransform);
    void setShapeMaterial(Qt3DExtras::QPhongMaterial *shapeMaterial);
    void setShapeEntity(Qt3DCore::QEntity *shapeEntity);


    Qt3DCore::QTransform *shapeTransform() const;

protected:
    Qt3DCore::QTransform *m_shapeTransform;
    Qt3DExtras::QPhongMaterial *m_shapeMaterial;
    Qt3DCore::QEntity *m_shapeEntity;

};

#endif // SHAPE3D_H
