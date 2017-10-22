#include "./View3DHeaders/corner3d.h"

Corner3D::Corner3D(Qt3DCore::QEntity *rootEntity):
    Cubie(rootEntity,isCorner)
{
    cuboid()->m_isCorner=isCorner;
    cuboid()->animHandler()->XOrbitTransform()->setRadius(1.555f);
    cuboid()->animHandler()->YOrbitTransform()->setRadius(1.555f);
    cuboid()->animHandler()->ZOrbitTransform()->setRadius(1.555f);

    m_plane = new Plane(rootEntity);
   // m_plane2 = new Plane(rootEntity);
   // m_plane3 = new Plane(rootEntity);

    m_plane->animHandler()->XOrbitTransform()->setRadius(1.555f);
   // m_plane2->animHandler()->XOrbitTransform()->setRadius(2.555f);
    //m_plane3->animHandler()->XOrbitTransform()->setRadius(2.555f);

    m_plane->setColor(0,255,0);

    //set plane radius
}

Plane *Corner3D::plane()
{
    return m_plane;
}
