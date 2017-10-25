#ifndef EDGE_H
#define EDGE_H

#include "./View3DHeaders/cubie.h"
#include "./View3DHeaders/plane.h"

class Edge3D : public Cubie
{
public:
    Edge3D(Qt3DCore::QEntity *rootEntity);

    void setUpPlanes();
    void updateColors(Corner corner,CornerOrientation orient){}
    void updateColors(Edge edge,EdgeOrientation orient);
    void updateColors(RubikFace centre){}

private:
    Plane *m_plane,*m_plane2;
};
#endif // EDGE_H
