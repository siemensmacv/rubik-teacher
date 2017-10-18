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
    Shape3D();

    void setShapeTransform(QTransform *shapeTransform);
    void setShapeMaterial(Qt3DRender::QMaterial *shapeMaterial);
    void setShapeEntity(Qt3DCore::QEntity *shapeEntity);
    void setAnimHandler(AnimationHandler *animHandler);

private:
    QTransform *m_shapeTransform;
    Qt3DRender::QMaterial *m_shapeMaterial;
    Qt3DCore::QEntity *m_shapeEntity;
    AnimationHandler *m_animHandler;
};

#endif // SHAPE3D_H
