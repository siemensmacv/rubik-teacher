#include "View3DHeaders/centre3d.h"

Centre3D::Centre3D(Qt3DCore::QEntity *rootEntity):
    Cubie(rootEntity,isCorner)
{
    //set plane

    //m_plane=new Plane(cuboid()->entity());
}

Plane *Centre3D::upDownPlane()
{
    return m_plane;
}
