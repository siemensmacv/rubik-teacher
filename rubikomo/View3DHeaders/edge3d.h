#ifndef EDGE_H
#define EDGE_H

#include "./View3DHeaders/cubie.h"
#include "./View3DHeaders/plane.h"

class Edge3D : public Cubie
{
public:
    Edge3D(Qt3DCore::QEntity *rootEntity);
    static const bool isCorner=false;
    Plane *upDownPlane();

private:
    Plane *m_plane,*m_plane2;
};
#endif // EDGE_H
