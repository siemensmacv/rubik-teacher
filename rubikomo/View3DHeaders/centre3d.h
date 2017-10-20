#ifndef CENTRE_H
#define CENTRE_H

#include "View3DHeaders/cubie.h"
#include "View3DHeaders/plane.h"

class Centre3D : public Cubie
{
public:
    Centre3D(Qt3DCore::QEntity *rootEntity);
private:
    Plane *m_plane;
};
#endif // CENTRE_H
