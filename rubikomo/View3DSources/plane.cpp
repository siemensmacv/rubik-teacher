#include "./View3DHeaders/plane.h"

Plane::Plane(Qt3DCore::QEntity *rootEntity) :
    Shape3D(rootEntity)
{

    m_planeMesh = new Qt3DExtras::QPlaneMesh();
    m_shapeEntity->addComponent(m_planeMesh);


    setColor(0,0,255);

}

void Plane::setPlaneMesh(Qt3DExtras::QPlaneMesh *planeMesh)
{
    m_planeMesh = planeMesh;
}

