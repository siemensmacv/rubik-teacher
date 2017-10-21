#include "View3DHeaders/centre3d.h"

Centre3D::Centre3D(Qt3DCore::QEntity *rootEntity):
    Cubie(rootEntity,isCorner)
{
    cuboid()->animHandler()->XOrbitTransform()->setRadius(0.0f);
    cuboid()->animHandler()->YOrbitTransform()->setRadius(0.0f);
    cuboid()->animHandler()->ZOrbitTransform()->setRadius(0.0f);

    //set plane radius
}
