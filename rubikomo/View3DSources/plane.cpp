#include "./View3DHeaders/plane.h"

Plane::Plane(Qt3DCore::QEntity *rootEntity) :
    Shape3D(rootEntity)
{

}

void Plane::setPlaneMesh(Qt3DExtras::QPlaneMesh *planeMesh)
{
    m_planeMesh = planeMesh;
}
