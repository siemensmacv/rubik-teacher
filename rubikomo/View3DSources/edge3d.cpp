#include "View3DHeaders/edge3d.h"

Edge3D::Edge3D(Qt3DCore::QEntity *rootEntity):
    Cubie(rootEntity,isCorner)
{
    m_cuboid->m_isCorner=isCorner;


    //set plane radius
}

Plane *Edge3D::upDownPlane()
{
 return m_plane;
}
