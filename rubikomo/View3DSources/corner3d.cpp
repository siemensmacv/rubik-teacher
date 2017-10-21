#include "./View3DHeaders/corner3d.h"

Corner3D::Corner3D(Qt3DCore::QEntity *rootEntity):
    Cubie(rootEntity,isCorner)
{
    cuboid()->m_isCorner=isCorner;
    cuboid()->animHandler()->XOrbitTransform()->setRadius(1.555f);
    cuboid()->animHandler()->YOrbitTransform()->setRadius(1.555f);
    cuboid()->animHandler()->ZOrbitTransform()->setRadius(1.555f);

    //set plane radius
}
