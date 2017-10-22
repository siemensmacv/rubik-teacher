#ifndef CORNER_H
#define CORNER_H

#include "./View3DHeaders/cubie.h"
#include "./View3DHeaders/plane.h"

class Corner3D : public Cubie
{
public:
    explicit Corner3D(Qt3DCore::QEntity *rootEntity);
    static const bool isCorner=true;
    Plane *plane();

private:
    Plane *m_plane;
    Plane *m_plane2;
    Plane *m_plane3;
};
#endif // CORNER_H
