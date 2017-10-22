#include "./View3DHeaders/plane.h"

Plane::Plane(Qt3DCore::QEntity *rootEntity) :
    Shape3D(rootEntity)
{
    m_planeMesh = new Qt3DExtras::QPlaneMesh(m_shapeEntity);
    m_shapeEntity->addComponent(m_planeMesh);
    m_shapeTransform->setTranslation(QVector3D(-1.1f,1.61f,1.1f));
    m_animHandler = new AnimationHandler(m_shapeTransform, false);

}
void Plane::test(){
    m_animHandler->startYAxisCClockAnim();
}
void Plane::setPlaneMesh(Qt3DExtras::QPlaneMesh *planeMesh)
{
    m_planeMesh = planeMesh;
}

AnimationHandler *Plane::animHandler() const
{
    return m_animHandler;
}
