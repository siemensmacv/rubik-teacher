#ifndef PLANE_H
#define PLANE_H

#include "./View3DHeaders/shape3d.h"

class Plane : public Shape3D
{
public:
    Plane(Qt3DCore::QEntity *rootEntity);
    void setPlaneMesh(Qt3DExtras::QPlaneMesh *planeMesh);

private:
    Qt3DExtras::QPlaneMesh *m_planeMesh;

};
#endif // PLANE_H
