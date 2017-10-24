#ifndef CUBOID_H
#define CUBOID_H

#include "./View3DHeaders/shape3d.h"
#include "./View3DHeaders/axishandler.h"

class Cuboid : public Shape3D
{
public:
    explicit Cuboid(Qt3DCore::QEntity *rootEntity, bool isCorner);
    bool m_isCorner;
    AxisHandler *axisHandler() const;
private:
    Qt3DExtras::QCuboidMesh *m_cuboidMesh;
    AxisHandler *m_axisHandler;
};
#endif // CUBOID_H
