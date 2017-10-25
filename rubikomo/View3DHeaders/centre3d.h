#ifndef CENTRE_H
#define CENTRE_H

#include "View3DHeaders/cubie.h"
#include "View3DHeaders/plane.h"

class Centre3D : public Cubie
{
public:
    Centre3D(Qt3DCore::QEntity *rootEntity);
    static const bool isCorner=false;
    Plane *upDownPlane();

    void setUpPlanes();

    void updateColors(Corner corner,CornerOrientation orient){}
    void updateColors(Edge edge,EdgeOrientation orient){}
    void updateColors(RubikFace centre);

private:
    Plane *m_plane;
};
#endif // CENTRE_H
