#ifndef CUBOID_H
#define CUBOID_H

#include "./View3DHeaders/shape3d.h"
#include "./View3DHeaders/axishandler.h"
#include <Qt3DCore>

class Cuboid : public Shape3D
{
public:
    Cuboid(Qt3DCore::QEntity *rootEntity, bool isCorner);
    bool m_isCorner;
    AxisHandler *m_axisHandler;
private:
    Qt3DExtras::QCuboidMesh *m_cuboidMesh;

};
#endif // CUBOID_H
