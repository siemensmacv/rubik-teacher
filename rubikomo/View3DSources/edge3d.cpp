#include "View3DHeaders/edge3d.h"

Edge3D::Edge3D(Qt3DCore::QEntity *rootEntity):
    Cubie(rootEntity)
{
    cuboid()->animHandler()->XOrbitTransform()->setRadius(1.1f);
    cuboid()->animHandler()->YOrbitTransform()->setRadius(1.1f);
    cuboid()->animHandler()->ZOrbitTransform()->setRadius(1.1f);

    //set plane radius
}
