#ifndef CORNER_H
#define CORNER_H

#include "./View3DHeaders/cubie.h"
#include "./View3DHeaders/plane.h"

class Corner3D : public Cubie
{
public:
    explicit Corner3D(Qt3DCore::QEntity *rootEntity);
    static const bool isCorner=true;
    Plane *upDownPlane();

    void setUpPlanes();

private:
    Plane *m_upDownPlane;
    Plane *m_frontBackPlane;
    Plane *m_leftRightPlane;
};
#endif // CORNER_H
